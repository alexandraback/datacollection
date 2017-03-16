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

// 1 i j k -1 -i -j -k
int op(int x, int y)
{
	int sgn = (x < 4) ^ (y < 4);
	x = x & 3; y = y & 3;
	int ans;
	if (x == 0 || y == 0 || (x+1)%3 == y%3) ans = x ^ y;
	else ans = x ^ y ^ 4;

	if (sgn) ans = ans ^ 4;
	return ans;
}
int encode(char x)
{
	if (x == 'i') return 1;
	else if (x == 'j') return 2;
	else return 3;
}

int pref[40005], suf[40005];

bool solve(string &s, ll x)
{
	int y = x < 4 ? x : 4;
	int len = s.size() * y;
	f(i,0,len) pref[i] = suf[i] = encode( s[i % s.size()] );
	f(i,1,len) pref[i] = op(pref[i-1], pref[i]);
	fd(i,len-2,0) suf[i] = op(suf[i], suf[i+1]);

	int pi = pref[s.size() - 1];
	if (x % 4 == 0) return 0;
	else if (x % 4 == 2 && (pi&3)==0) return 0;
	else if (x % 2 == 1 && pi != 4) return 0;

	int i = 0;
	for (; i < len && pref[i] != 1; i++);
	if (i == len) return 0;

	ll j = len - 1;
	for (; j >= 0 && suf[j] != 3; j--);
	if (j == -1) return 0;
	if (x > 4) j += (ll) s.size() * (x - 4);
	return i < j;
}

int caso;

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		ll n,x; cin >> n >> x;
		string s; cin >> s;
		int ans = solve(s, x);
		printf("Case #%d: %s\n", ++caso, ans? "YES" : "NO");
	}
}

