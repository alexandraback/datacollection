#include <stdio.h>

#define MAX_N 101


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.txt", "w", stdout);
    int T;
    char s[MAX_N];
    int val[MAX_N][MAX_N];
    int caso=1;
    int A,B,K;
    int i,j,k;
    int tam;
    char c;
    int flag;
    long long sol=0;
    int arr[MAX_N];
    int aux;

    scanf("%d", &T);
    while (T--){
        aux=0;
        sol=0;

        scanf("%d %d %d", &A, &B, &K);

        for(i=0; i<A; i++){
            for(j=0;j<B;j++){
                if((i&j)<K){
                    sol++;
                }
            }
        }
        /*
        LA=getLeftMost(A);
        LB=getLeftMost(B);
        LK=getLeftMost(K);
        L2A=get2LeftMost(A, LA);
        L2B=get2LeftMost(B, LB);
        L2K=get2LeftMost(K, LK);

        for(i=0; i<LK;i++){
            if(isBitOn(K,i)){

            }
        }*/
        printf("Case #%d: %d\n", caso, sol);
        caso++;

    }
    return 0;
}

