#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<numeric>
#include<fstream>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64

int dp[1000006];
int myrev(int u){
    int ret = 0;
    while(u){
        ret = ret*10 + u%10;
        u /= 10;
    }
    return ret;
}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.ans","w",stdout);
    int t,cs = 1, u, v, n;
    cin>>t;
    while(t--){
        SET(dp);
        cin>>n;
        queue<int> q;
        q.push(0);
        dp[0] = 0;
        while(!q.empty()){
            int u = q.front();
            if(u == n) break;
            q.pop();
            if(dp[u+1]==-1){
                dp[u+1] = dp[u] + 1;
                q.push(u+1);
            }
            v = myrev(u);
            if(dp[v]==-1){
                dp[v] = dp[u] + 1;
                q.push(v);
            }
        }
        printf("Case #%d: %d\n",cs++,dp[n]);
    }
	return 0;
}
