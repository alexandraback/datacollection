#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair 
#define sz(x) ((int)(x).size ())
#define re return
#define pb push_back
#define y0 y123423
#define y1 y2345
#define j0 j234
#define j1 j345
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt (abs(x))
#define makeunique(x) sort (all (x)), (x).resize (unique (x) - (x).begin())

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef vector <string> vs;
typedef long double ld;
typedef double D;

template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T  gcd (T a, T b) { re a ? gcd (b % a, a) : b; } 
template <class T> int sgn (T x) { re x > 0 ? 1 : (x < 0 ? -1 : 0); }
template <class T> T sqr (T x) { re x * x; }

const ld pi  = acos ((ld)(-1.0));

const int maxn = 1005;

int n;
map<string, int> seta, setb;
int was[maxn];
int p[maxn];
vi gr[maxn];
int ct;
char s[25];

bool go(int cur)
{
	if (was[cur] == ct) return false;
	was[cur] = ct;
	for (auto v : gr[cur])
	{
		if (p[v] == -1 || go(p[v]))
		{
			p[v] = cur;
			return true;
		}
	}
	return false;
}

inline int getnuma()
{
	string cur = string(s);
	if (seta.count(cur)) return seta[cur];
	int ans = seta.size();
	seta[cur] = ans;
	return ans;
}

inline int getnumb()
{
	string cur = string(s);
	if (setb.count(cur)) return setb[cur];
	int ans = setb.size();
	setb[cur] = ans;
	return ans;
}

int main ()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		seta.clear();
		setb.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) gr[i].clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s);
			int a = getnuma();
			scanf("%s", s);
			int b = getnumb();
			gr[a].pb(b);
		}
		int answer = seta.size() + setb.size();
		for (int i = 0; i < (int)setb.size(); i++) p[i] = -1;
		for (int i = 0; i < n; i++)
		{
			ct++;
			if (go(i)) answer--;
		}
		printf("Case #%d: %d\n", T + 1, n - answer);
		fprintf(stderr, "%d/%d cases done!\n", T + 1, NT);
	}
	
	return 0;
}
