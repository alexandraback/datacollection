#include <bits/stdc++.h>
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c)  for(auto &(i) : (c))
#define x     first
#define y     second
#define pb  push_back
#define PB  pop_back()
#define iOS  ios_base::sync_with_stdio(false)
#define sqr(a)  (((a) * (a)))
#define all(a)  a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x)  ((x)<<1)
#define R(x)  (((x)<<1)+1)
#define umap  unordered_map
#define smax(x, y)	x = max((x), (y))
#define smin(x, y)	x = min((x), (y))
#define double long double
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
const int maxn = 1000+ 100,inf =  1e9 + 7;
int p[maxn];
int n;
int dp[maxn][maxn];
int main(){
	iOS;
	int T;
	cin >> T;
	fill(&dp[0][0], &dp[0][0] + maxn * maxn, inf);
	For(i,0,maxn)
		dp[0][i] = 0;
	For(i,1,maxn)
		For(j,1,maxn){
			if(i <= j)
				dp[i][j] = 0;
			For(x,1,i)
				smin(dp[i][j], 1 + dp[x][j] + dp[i-x][j]);
		}
	For(TT, 1, T + 1){
		cout << "Case #" << TT << ": ";
		cin >> n;
		For(i,0,n)
			cin >> p[i];
		int ans = 1e9 + 100;
		For(i,1,maxn){
			int s = 0;
			For(j,0,n)
				s += dp[p[j]][i];//cost(p[j], i);
			smin(ans, s + i);
		}
		cout << ans << endl;

	}
}



