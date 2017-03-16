#include"cstdio"
#include"iostream"
#include"map"
#include"string"
#include"cstring"
#include"vector"
#include"utility"
#include"algorithm"
#include"cmath"
#include"queue"
#include"stack"
#include"set"

using namespace std;
#define Nmax 1005007

int N;
bool vis[Nmax];
int que[Nmax];
int qfront,qback;
int dp[Nmax];

int rev_dig(int v){
    int ans=0;
    while(v>0){
        ans*=10;
        ans+=v%10;
        v/=10;
    }
    return ans;
}
int bfs(){
    que[qback++]=1;
    dp[1]=1;
    vis[1]=true;
    while(qback>qfront){
        if(vis[N])return 1;

        int tv=que[qfront];
        vis[tv]=true;
        int rv=rev_dig(que[qfront]);
        int dv=tv+1;
        if(!vis[rv]){
            dp[rv]=dp[tv]+1;
            que[qback++]=rv;
            vis[rv]=true;
        }
        if(!vis[dv]){
            dp[dv]=dp[tv]+1;
            que[qback++]=dv;
            vis[dv]=true;
        }
        qfront++;
    }
}
int main(){
    freopen("d:A-small-attempt0.in","r",stdin);
    freopen("d:A.out","w",stdout);
	int T;
	int casenum=0;
	cin>>T;
	while(casenum++<T){
        cin>>N;
        qfront=qback=0;
        memset(vis,false,sizeof(vis));
        bfs();
        printf("Case #%d: %d\n",casenum,dp[N]);
	}


return 0;}
