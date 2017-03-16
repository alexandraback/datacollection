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

bool winGabriel(int x, int r, int c)
{
	if (r*c % x) return 0;
	if (x <= 2) return 1;
	if (x >= 4) return 0;
	// x = 3, 3|rc
	if (r%3) swap(r,c);

	if (r % 2 == 0)
	{
		return c >= 2;
	}
	else
	{
		if (r == 3) return c % 2 == 0;
		else return c!=1 && c!=3;
	}
}

int main()
{
	int tc, caso = 0;
	cin >> tc;
	while (tc--)
	{
		int x,r,c; cin >> x >> r >> c;
		int ans = winGabriel(x, r, c);
		printf("Case #%d: %s\n", ++caso, ans? "GABRIEL" : "RICHARD");
	}
}

