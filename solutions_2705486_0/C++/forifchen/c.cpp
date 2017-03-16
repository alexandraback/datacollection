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
#define oo (1<<29)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; f(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; f(i,0,m)f(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define N 1
using namespace std;
template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}

int tc, caso;
string s;
vector<string> vs[20];
int dp[5000][20];
int g[5000];

int main(){

	ifstream archivo;
	archivo.open("other.txt");
	string ex;
	int lenmax = 0;
	int ww = 0;
	while (archivo >> ex) {
		ww++;
		vs[ex.size()].pb(ex);
		maxi(lenmax,(int) ex.size());
	}
//	debug(ww);
	archivo.close();
//	debug(lenmax);
//	cout << vs[5].size() << endl;

	cin >> tc;
	while(tc--) {
		cin >> s;
		int n = s.size();
		for (int i = 0; i < n; i++) for (int j = 1; j<=10 && i+j<=n; j++) {
			int &res = dp[i][j] = oo;
			for(int k = 0; k < vs[j].size(); k++) {
				char *t = &vs[j][k][0];
				int ult = -oo;
				int ok = 1, z = 0;
				f(r,0,j) if (s[i+r] != t[r]) {
					if (ult+5 > r) ok = 0, r = oo;
					else {
						ult = r;
						z++;
					}
				}
				if (ok) mini(res, z);
			}
		}	
		g[0] = 0;
		f(i,1,n+1) {
			g[i] = oo;
			for (int j = 1; j <= 10 && j <= i; j++)if (dp[i-j][j]!=oo) {
				mini(g[i], g[i-j] + dp[i-j][j]);
			}
		}

		printf("Case #%d: %d\n", ++caso, g[n]);
	}
}

