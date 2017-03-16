#pragma comment(linker, "/stack:128000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <climits>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define x first
#define y second
#define ft first
#define sc second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = INT_MAX / 2;
const ld EPS = ld(1e-9);
const ld PI = ld(3.1415926535897932384626433832795);

int a, b, k;

inline bool read()
{
	if (scanf("%d%d%d", &a, &b, &k) != 3)
		return false;
		
	return true;
}

inline string toStr(int x)
{
	if (x == 0)
		return "0";
		
	string ans = "";
	
	while(x > 0)
	{
		int cur = (x % 2);
		x /= 2;
		
		ans.pb('0' + cur);
	}
	
	reverse(all(ans));
	
	return ans;
}

inline void norm(string& s, int l)
{
	while(sz(s) < l)
		s = "0" + s;
}

const int N = 50 + 3;

li z[N][2][2][2];

inline int get(const string& s, int i, int j)
{
	int ans = 0;
	
	if (j == 0 || (j == 1 && s[i] == '1'))
		ans = 1;
		
	return ans;
}

inline int getNext(int j, int can, int val)
{
	int ans = 0;
	
	if (j == 1 && can == val)
		ans = 1;
		
	return ans;
}

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);

	string sa = toStr(a - 1);		
	string sb = toStr(b - 1);		
	string sk = toStr(k - 1);		

	int l = max(sz(sa), max(sz(sb), sz(sk)));		
	
	norm(sa, l);	
	norm(sb, l);	
	norm(sk, l);	
	
	memset(z, 0, sizeof(z));
	z[0][1][1][1] = 1;
	
	forn(i, l)	
		forn(ja, 2)
		forn(jb, 2)
		forn(jk, 2)
		{
			li& dv = z[i][ja][jb][jk];
			
			if (dv == 0)
				continue;
				
			int cana = get(sa, i, ja);
			int canb = get(sb, i, jb);
			int cank = get(sk, i, jk);
			
			fore(xa, 0, cana)
			fore(xb, 0, canb)
			{
				int val = (xa & xb);
				if (val > cank)
					continue;
					
				int na = getNext(ja, cana, xa);
				int nb = getNext(jb, canb, xb);
				int nk = getNext(jk, cank, val);
				
				z[i + 1][na][nb][nk] += dv;
			}
		}
		
	li ans = 0;
	
	forn(ja, 2)
	forn(jb, 2)
	forn(jk, 2)
		ans += z[l][ja][jb][jk];
		
	cout << ans << endl;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int testCnt;

    assert(scanf("%d\n", &testCnt) == 1);

    forn(test, testCnt)
    {
    	assert(read());
		solve(test);
	}

    return 0;
}
