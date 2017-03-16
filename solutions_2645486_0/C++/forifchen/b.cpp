#include <bits/stdc++.h>
#define f(i,x,y) for (int i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define eps (1e-9)
#define oo (1<<30)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; f(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; f(i,0,m)f(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define N 1
using namespace std;
template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}

int tc, caso;
int E,R,n;
int v[10005];
ll dp[2][10000005];

int main(){
	cin >> tc;
	while(tc--) {
		cin >> E >> R >> n;
		f(i,0,n) scanf("%d", v + i);
		ll s = 0;
		f(i,0,n) s += v[i];
		ll res;
		if (E <= R) res = E*s;
		else {
			f(i,0,E+1) dp[0][i] = 0;
			int tt = 0;
			fd(j,n-1,0) {
				tt = !tt;
				f(i,0,E+1) {
					ll &memo = dp[tt][i];
					if (i == 0) { memo = dp[!tt][R]; continue; }
					else {
						memo = dp[tt][i-1] + v[j];
						if (i+R <= E) maxi(memo, dp[!tt][i+R]);
					}
				}
//				adebug(dp[tt], E+1);
			}
			res = dp[tt][E];
		}

		printf("Case #%d: %lld\n", ++caso, res);
	}
}

