#include<cstdio>
#include<cstring>
using namespace std;
long long dp[50];
long long cal(int k,int t){
    if(t<0) return 1;
    if(dp[t]) return dp[t];
    if(k&(1<<t)){
        return dp[t]=(1LL<<(2*t))*3+cal(k,t-1);
    }
    else return dp[t]=cal(k,t-1)*3;
}
long long cnt(int a,int b,int k,int t){
    if(t<0) return 1;
    int msb=(1<<t);
    if(a==msb-1&&b==msb-1) return cal(k,t-1);
    if(k&msb){
        if(a<msb||b<msb){
            return 1LL*(a+1)*(b+1);
        }
        else{
            return 1LL*(a+1)*(b+1)-1LL*(a+1-msb)*(b+1-msb)+cnt(a-msb,b-msb,k,t-1);
        }
    }
    else{
        if(a<msb&&b<msb){
            return cnt(a,b,k,t-1);
        }
        else if(a<msb){
            return cnt(a,b-msb,k,t-1)+cnt(a,msb-1,k,t-1);
        }
        else if(b<msb){
            return cnt(a-msb,b,k,t-1)+cnt(msb-1,b,k,t-1);
        }
        else{
            return cnt(a-msb,msb-1,k,t-1)+cnt(msb-1,b-msb,k,t-1)+cal(k,t-1);
        }
    }
}
int main(){
    int c,t,a,b,k;
    scanf("%d",&t);
    for(c=1;c<=t;c++){
        scanf("%d%d%d",&a,&b,&k);
        memset(dp,0,sizeof(dp));
        //for(int i=0;i<10;i++) printf("%d\n",cal(k-1,i));
        printf("Case #%d: %lld\n",c,cnt(a-1,b-1,k-1,29));
    }
    return 0;
}
