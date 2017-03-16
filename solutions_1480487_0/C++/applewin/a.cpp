#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;
int N;
int m[220];

int main(){
    int T, sum;
    scanf("%d", &T);
    for(int i=1;i<=T;++i){
        scanf("%d",&N);
        sum = 0;
        for(int j=0;j<N;++j){
            scanf("%d", &m[j]);
            sum += m[j];
        }
        printf("Case #%d:", i);
        double KK = double(sum * 2)/double(N);
        char kkk[220];
        int P = 0;
        int LLL = sum;
        memset(kkk,0,sizeof(kkk));
        for(int j=0;j<N;++j){
            double Y = 100.0 * double(KK-m[j])/double(sum);
            if(Y<= 0){
                kkk[j] = 1;
                P++;
                LLL -= m[j];
            }   
        }
        KK = double(sum + LLL)/double(N-P);
        for(int j=0;j<N;++j){
            if (kkk[j] == 1)
                printf(" 0");
            else{
                printf(" %lf", 100.0 * double(KK-m[j])/double(sum));
            }
        }
        puts("");
    }
    return 0;
}

