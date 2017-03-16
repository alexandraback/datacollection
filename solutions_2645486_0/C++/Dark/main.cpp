#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define sz(i) int(i.size())
#define mst(i,n) memset(i,n,sizeof(i))
#define eps 1e-4
#define MOD 1000000007
#define LL long long
#define pi acos(-1)
#define ALL(n) n.begin(),n.end()
#define pb push_back
#define iFor(i,n) for(typeof(n.begin()) i=n.begin();i!=n.end();i++)

int dp[15][15];
void update(int &a,int b){
    if(a==-1||a<b) a=b;
}
int main(){
	int ca, c = 0;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&ca);
	while(ca--){
        int e,r,n;
        int v[20];
        cin>>e>>r>>n;
        For(i,n) cin>>v[i];
        mst(dp,-1);
        dp[0][e] = 0;
        int ans = 0;
        For(i,n)
            For(j,e+1){
                if(dp[i][j]==-1) continue;
                For(sp,j+1){
                    int next = min(j - sp + r, e);
                    update(dp[i+1][next], dp[i][j]+v[i]*sp);
                }
            }
        For(j,e+1) ans = max(ans, dp[n][j]);
        cout<<"Case #"<<++c<<": "<<ans<<endl;
	}
	return 0;
}
