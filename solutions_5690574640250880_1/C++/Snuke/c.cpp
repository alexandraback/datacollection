#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<complex>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int dp[55][55][2555];
vector<string> ans;

void dfs(int i, int j, int k){
	if(!i) return;
	i--;
	dfs(i,dp[i+1][j][k],k-j);
	rep(l,j) ans[i][l] = '.';
}

int main(){
	int ts;
	cin >> ts;
	rrep(ti,ts){
		int n, m, x;
		cin >> n >> m >> x;
		x = n*m-x;
		ans = vector<string>(n,string(m,'*'));
		
		if(x != 1){
			rep(i,n+1)rep(j,m+1)rep(k,x+1) dp[i][j][k] = -1;
			dp[0][m][0] = 0;
			rep(i,n)rep(j,m+1)rep(k,x+1){
				if(dp[i][j][k] == -1) continue;
				rep(l,j+1){
					if(i == 1 && l != j) continue;
					if(l == 1 && m != 1) continue;
					dp[i+1][l][k+l] = j;
				}
			}
			
			rep(i,m+1){
				if(dp[n][i][x] == -1) continue;
				dfs(n,i,x);
				ans[0][0] = 'c';
				break;
			}
		} else ans[0][0] = 'c';
		
		printf("Case #%d:\n",ti);
		if(ans[0][0] != 'c') puts("Impossible");
		else {
			rep(i,n) cout << ans[i] << endl;
		}
	}
	
	return 0;
}





