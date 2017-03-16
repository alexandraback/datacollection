#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<ctime>
#include<bitset>
#define LL long  long
#define db double
#define EPS 1e-15
#define inf 1e10

using namespace std;

const int MAXN = 1 << 10 ;
int prime[MAXN];
int pri[MAXN],cnt;
int ans[11];
int n,m;
void init(){
    for (int i=2;i<MAXN;i++){
        if (!prime[i]) pri[cnt++]=i;
        for (int j=0;j<cnt && i*pri[j]<MAXN;j++){
            prime[i*pri[j]]=1;
            if(i%pri[j]==0) continue;
        }
    }
}
void solve(){
    scanf("%d%d",&n,&m);
    LL s=(1LL<<(n-1))+1;
    LL t=(1LL<<n)-1;
    for (LL i=s;i<=t;i+=2){
        int flag=1;
        for (int j=2;j<=10;j++){
            int flag1=0;
            for (int k=0;k<10;k++){
                LL tmp=i;
                LL T=1,res=0;
                while (tmp){
                    res+=(tmp&1)*t;
                    res%=pri[k];
                    tmp/=2;
                    }
                if (!res){
                    flag1=1;
                    ans[j]=pri[k];
                    break;
                }
            }
            if (!flag1) flag=0;
        }
        if (flag) {
            for (int j=n-1;j>=0;j--)
                printf("%d",(i>>j)&1);
            for (int j=2;j<=10;j++)
                printf("%d",ans[j]);
            puts("");
            m--;
            if (m==0) break;
        }
    }
}
int main(){
    freopen("1.in","r",stdin);
    freopen("out.txt","w",stdout);
    init();
    int T;
    scanf("%d",&T);
    for (int i=1;i<=T;i++){
        printf("Case #%d:\n",i);
        solve();
    }
    return 0;
}
