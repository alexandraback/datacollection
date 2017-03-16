#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdio>
#include<string.h>
#include<set>
using namespace std;

typedef long long Int;
#define FOR(i,a,b)  for(int i=(a);i<=(b);++i)
#define sz(s) (int)(s).size()
#define mp make_pair
#define pb push_back
void assert(bool x){if(!x)throw -1;}
const int inf = 1000000000;
const int MOD = 1000000007;
#define sqr(x) (x)*(x)
const double PI = acos(-1.0);
const double EPS = 1e-9;


const int N = 55;
int init[N];
int open[N];
int recv[N][N],k[N];
bool dp[1<<20];
bool allow[1<<20][20];

int main()
{
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int tests;cin>>tests;
	FOR(test,1,tests){
		int n;
		int kinit;
		cin>>kinit>>n;
		FOR(i,0,kinit-1)cin>>init[i];
		FOR(i,0,n-1){
			cin>>open[i]>>k[i];
			FOR(j,0,k[i]-1)cin>>recv[i][j];
		}

		memset(allow,false,sizeof(allow));
		memset(dp,false,sizeof(dp));
		dp[0]=true;
		FOR(mask,0,(1<<n)-1)if(dp[mask]){
			vector<int> have(204,0);
			FOR(i,0,kinit-1)have[init[i]]++;
			FOR(i,0,n-1)if(!(mask&(1<<i))){
				//cout<<"- "<<i<<endl;
				have[open[i]]--;
				FOR(j,0,k[i]-1)have[recv[i][j]]++;
			}
			//cout<<mask<<": ";FOR(i,0,400)if(have[i])cout<<i<<" ";cout<<endl;
			FOR(nx,0,n-1)if(!(mask&(1<<nx))){
				vector<int> tmp = have;
				tmp[open[nx]]++;
				FOR(i,0,k[nx]-1)tmp[recv[nx][i]]--;
				if(tmp[open[nx]]){
					allow[(1<<n)-1-mask-(1<<nx)][nx]=true;
					dp[mask^(1<<nx)] = true;
				}
				//tmp[open[nx]]--;
				//FOR(i,0,k[nx]-1)recv[nx][i]++;
			}
		}

		cout<<"Case #"<<test<<": ";
		if(!dp[(1<<n)-1]){
			puts("IMPOSSIBLE");
			continue;
		}

		vector<int> ans;
		int must = (1<<n)-1,now=0;
		while(must){
			FOR(nx,0,n-1)if((must&(1<<nx))){
				int to = (must^(1<<nx));
				if(allow[now][nx] && dp[to]){
					ans.pb(nx);
					must=to;
					now^=(1<<nx);
					break;
				}
			}
		}
		
		FOR(i,0,sz(ans)-1)cout<<ans[i]+1<<" ";
		cout<<endl;

		cerr<<test<<endl;
	}
}