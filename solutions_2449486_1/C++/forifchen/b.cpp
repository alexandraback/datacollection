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

int tc, n, m;
int a[105][105];

int main(){
	iostream::sync_with_stdio(0);
	cin >> tc;
	int caso = 0;
	while (tc--) {
		cin >> n >> m;
		f(i,0,n) f(j,0,m) cin >> a[i][j];
		bool ok = 1;
		f(i,0,n) f(ii,i+1,n) f(j,0,m) f(jj,j+1,m) 
			if (min(a[i][jj], a[ii][j]) != min(a[i][j], a[ii][jj])) ok = 0;
		cout << "Case #" << (++caso) << ": ";
		cout << (ok? "YES" : "NO") << endl;
	}
}

