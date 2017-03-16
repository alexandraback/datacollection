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
const ll inf = 3e18;

int n;
char s[20], t[20];
char ans[20];
ll answer, ansa, ansb;

inline ll getmin(ll a, char *s, int x)
{
	for (int i = x; i < n; i++)
	{
		a *= 10;
		if (s[i] == '?') a += 0;
		else a += s[i] - '0';
	}
	return a;
}

inline ll getmax(ll a, char *s, int x)
{
	for (int i = x; i < n; i++)
	{
		a *= 10;
		if (s[i] == '?') a += 9;
		else a += s[i] - '0';
	}
	return a;
}

inline void updans(ll a, ll b)
{
	if (abs(a - b) > answer) return;
	if (abs(a - b) < answer)
	{
		answer = abs(a -b );
		ansa = a;
		ansb =b;
		return;
	}
	if (a > ansa) return;
	if (a < ansa)
	{
		answer = abs(a -b );
		ansa = a;
		ansb =b;
		return;
	}
	if (b > ansb) return;
	ansb = b;
}

void trybuild(ll a, ll b, int x)
{
	ll mina = getmin(a, s, x);
	ll maxa = getmax(a, s, x);
	ll minb = getmin(b, t, x);
	ll maxb = getmax(b, t, x);
	//cout << "trybuild " << a << ' ' << b << ' ' << x << endl;
	updans(mina, minb);
	updans(maxa, maxb);
	updans(mina, maxb);
	updans(maxa, minb);
}

int main ()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		scanf("%s%s", s, t);
		n = strlen(s);
		ll a = 0;
		ll b = 0;
		answer = inf;
		ansa = inf;
		ansb = inf;
		bool found = false;
		for (int i = 0; i < n; i++)
		{
			if (!(s[i] == t[i] || s[i] == '?' || t[i] == '?'))
			{
				if (i > 0 && (s[i - 1] == '?' || t[i - 1] == '?'))
				{
					a /= 10;
					b /= 10;
					if (s[i - 1] == '?' && t[i - 1] == '?')
					{
						trybuild(a * 10, b * 10, i);
						trybuild(a * 10 + 1, b * 10, i);
						trybuild(a * 10, b * 10 + 1, i);
					} else if (s[i - 1] == '?')
					{
						int dig = t[i - 1] - '0';
						trybuild(a * 10 + dig, b * 10 + dig, i);
						if (dig > 0) trybuild(a * 10 + dig - 1, b * 10 + dig, i);
						if (dig < 9) trybuild(a * 10 + dig + 1, b * 10 + dig, i);
					} else
					{
						//cout << "here " << endl;
						int dig = s[i - 1] - '0';
						trybuild(a * 10 + dig, b * 10 + dig, i);
						if (dig > 0) trybuild(a * 10 + dig, b * 10 + dig - 1, i);
						if (dig < 9) trybuild(a * 10 + dig, b * 10 + dig + 1, i);
					}
				} else
				{
					trybuild(a, b, i);
				}
				found = true;
				break;
			} else
			{
				int dig = 0;
				if (s[i] != '?') dig = s[i] - '0';
				if (t[i] != '?') dig = t[i] - '0';
				a *= 10;
				a += dig;
				b *= 10;
				b += dig;
				if (dig > 0 && s[i] == '?') trybuild(a - 1, b, i + 1);
				if (dig > 0 && t[i] == '?') trybuild(a, b - 1, i + 1);
				if (dig < 9 && s[i] == '?') trybuild(a + 1, b, i + 1);
				if (dig < 9 && t[i] == '?') trybuild(a, b + 1, i + 1);
			}
		}
		if (!found)
		{
			ansa = a;
			ansb = b;
			answer = abs(a - b);
		}
		//int st = 1;
		//for (int i = 0; i < n; i++) st *= 10;
		//pair<ll, pair<ll, ll>> ans2 = {inf, {inf, inf}};
		//for (int i = 0; i < st; i++)
		//{
			//for (int j = 0; j < st; j++)
			//{
				//bool ok = true;
				//int a = i;
				//int b = j;
				//for (int tt = n - 1; tt >= 0; tt--)
				//{
					//if (s[tt] != '?' && a % 10 != s[tt] - '0') ok = false;
					//if (t[tt] != '?' && b % 10 != t[tt] - '0') ok = false;
					//a /= 10;
					//b /= 10;
				//}
				//if (!ok) continue;
				////cout << "try " << a << ' ' << b << endl;
				//ans2 = min(ans2, {abs(i - j), {i, j}});
			//}
		//}
		printf("Case #%d: ", T + 1);
		//printf("%lld %lld\n", ansa, ansb);
		sprintf(ans, "%018lld", ansa);
		for (int i = 18 - n; i < 18; i++) printf("%c", ans[i]);
		printf(" ");
		sprintf(ans, "%018lld", ansb);
		for (int i = 18 - n; i < 18; i++) printf("%c", ans[i]);
		printf("\n");
		//printf("%lld %lld\n", ans2.se.fi, ans2.se.se);
		//assert(ans2.se.fi == ansa && ans2.se.se == ansb);
		fprintf(stderr, "%d/%d cases done!\n", T + 1, NT);
	}
	
	return 0;
}
