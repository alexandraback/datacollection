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
int A,B,C;

ll memo[2][2][2][31];
ll dp(int a, int b, int c, int pos) {
	if (pos == -1) return 1;
	ll &res = memo[a][b][c][pos];
	if (~res) return res;
	res = 0;
	int na = 2; if (a == 0 && !(A&(1<<pos)) ) na = 1;
	int nb = 2; if (b == 0 && !(B&(1<<pos)) ) nb = 1;
	int nc = 2; if (c == 0 && !(C&(1<<pos)) ) nc = 1;
	f(ia,0,na) f(ib,0,nb) if ((ia&ib) < nc ) {
		int ic = ia&ib;
		int a2 = a || ia+1<na? 1 : 0;
		int b2 = b || ib+1<nb? 1 : 0;
		int c2 = c || ic+1<nc? 1 : 0;
		res += dp(a2, b2, c2, pos-1);
	}
	return res;
}

int main(){
	int tc; cin >> tc;
	while(tc--) {
		cin >> A >> B >> C;
		A--; B--; C--;
		clr(memo, -1);
		printf("Case #%d: %lld\n", ++caso, dp(0,0,0, 29));
	}
}


