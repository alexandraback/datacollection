#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN=1004;
long long int DP[10000001];
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    long long int E,T,N,R,q=1,num[MAXN],res;

    scanf("%lld",&T);
    while(T--){
        res=0;
        scanf("%lld %lld %lld",&E,&R,&N);
        for(int i=0;i<N;i++) scanf("%lld",&num[i]);
        for(int i=0;i<=E;i++) DP[i]=0;
        for(int i=0;i<N;i++){
            for(int j=E-1;j>=0;j--){
                DP[j]=max(DP[j],DP[j+1]+num[i]);
            }
            for(int j=E-1;j>=0;j--){
                DP[min(E,j+R)]=max(DP[min(E,j+R)],DP[j]);
            }
        }
        for(int i=0;i<=E;i++) res=max(res,DP[i]);
        printf("Case #%lld: %lld\n",q++,res);
    }
}

