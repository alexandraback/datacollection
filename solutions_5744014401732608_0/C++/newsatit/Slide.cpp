#include <bits/stdc++.h>
using namespace std;
int table[60][60];
int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        for(int i=0;i<55;i++){
            for(int j=0;j<55;j++){
                table[i][j] = 0;
            }
        }
        long long M,check;
        int B;
        check = 1;
        scanf("%d%lld",&B,&M);
        for(int i=0;i<B-2;i++){
           check *= 2;
        }
        printf("Case #%d: ",t);
        if(M>check){
            printf("IMPOSSIBLE\n");continue;
        }
        M--;
        table[1][B] = 1;
        for(int i=2; i<B; i++){
            for(int j = i+1; j<=B; j++){
                table[i][j] = 1;
            }
        }
        int index;
        index = B-1;
        for(long long i=1;i<=M;){
            if(M&i){
                table[1][index] = 1;
            }
            i*=2;
            index--;
        }
        printf("POSSIBLE\n");
        for(int i=1; i<=B;i++){
            for(int j=1;j<=B;j++){
               printf("%d",table[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
