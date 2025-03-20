#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int russianPeasant(int, int);
int test(int*,int*, int*);

int main(){

    // int n = 10;
    // int m = 23;
    // int ans = russianPeasant(n,m);

    int n,m,ans;
    if(test(&n,&m,&ans)){
        printf("%d * %d = %d\n",n,m,ans);
    }

    return 0;
}

int test(int* n, int* m, int* ans){
    for(unsigned i = 0; i < 100000; ++i){
        *n = rand() % 100000 + 1;
        *m = rand() % 100000 + 1;
        *ans = russianPeasant(*n,*m);
        if(*ans != (*n) * (*m)){
            return 1;
        }
    }
    return 0;
}

int russianPeasant(int n, int m){

    int carry = 0;
    while(n > 1){
        int odd = 0;
        if(n%2){
            odd = 1;
        }
        n /= 2;
        if(odd){
            carry += m;
        }
        m *= 2;
        
    }
    return carry + m;
}
