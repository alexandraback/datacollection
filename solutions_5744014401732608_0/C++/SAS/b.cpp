#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

long long int p2(long long k){
    return 1LL << k;
}


int B;
char bitMap[52][52];

long long int M;
int main(){
    int T;
    scanf("%d",&T);
    for(int ca= 1;ca <=T;ca++){
        scanf("%d %lld",&B, &M);
        for(int i=0;i<52;i++) for(int j=0;j<52;j++) bitMap[i][j] = 0;
        for(int i=0;i<B;i++) for(int j=0;j<B;j++) bitMap[i][j] = '0';
        for(int i=0;i<B - 1;i++) bitMap[i][i + 1] = '1';

        printf("Case #%d: ", ca);
        long long int max_possible = p2(B - 2);

        if(M > max_possible){
            printf("IMPOSSIBLE\n");
            continue;
        }else{
            printf("POSSIBLE\n");
        }

        long long int total = 1;
        int index = 1;
        for(;index<B;index++){
            for(int i=0;i<index;i++){
                bitMap[i][index] = '1';
            }

            if(total >= M){
                break;
            }


            total *= 2;
        }


        long long int residual = total - M; 

        for(int i=1;i<index;i++){
            if(residual % 2 == 1){
                bitMap[i][index] = '0';
            }
            residual /= 2;
        }

        for(int i=0;i<B;i++){
            printf("%s\n",bitMap[i]);
        }


    }
    return 0;
}
