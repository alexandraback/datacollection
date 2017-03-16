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
int n, x, y;
double memo[1420][1420];
int k;
double dp(int a, int b) {
	if (a == 0 && b == 0) return 1;
	double &res = memo[a][b];
	if (res != -1) return res;
	res = 0;
	if (a) res += dp(a-1,b) * (b==2*k? 1 : 0.5);
	if (b) res += dp(a, b-1) * (a==2*k? 1 : 0.5);
	return res;
}

int main(){
	cin >> tc;
	while(tc--) {
		f(i,0,1420) f(j,0,1420) memo[i][j] = -1;
		cin >> n >> x >> y;
		if (x<0) x = -x;

		k = 1;
		while ((2*k+1)*(k+1) <= n) k++;
		int dif = n - (2*k-1)*k;
		double res = 0;
		if (x+y <= 2*k-2) res = 1;
		else if (x + y > 2*k ) res = 0;
		else {
			res = 0;
			for(int a = 0; a<=2*k; a++) {
				int b = dif - a;
				if (0<=b && b<=2*k && b >= y+1) {
					res += dp(a,b);
				}
			}
		}
		printf("Case #%d: %.8f\n", ++caso, res);
	}
}

