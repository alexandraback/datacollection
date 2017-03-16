#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>

#define sqr(x) ((x) * (x))
#define ALL(c) (c).begin(), (c).end()

using namespace std;

const double PI = 2.0 * acos (0.0);
const int INF = 2123123123;
const int EPS = 1e-9;

typedef long long LL;

inline int NUM (char c) { return (int)c - 48; }
inline char CHAR (int n) { return (char)(n + 48); }
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

inline void OPEN(const string &s) 
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int palindrome(LL x)
{
	LL k = 0, temp = 0;
	temp = x;
	while (x)
	{
		k = k*10+x%10;
		x/=10;
	}
	return temp == k;
}

LL a1,a2,l,r;
vector<LL> spl;

int main()
{
	LL i,t,tc;
	OPEN("gcjqc");
	for (i = 1; i <= 10000000; i++)
			if (palindrome(i) && palindrome(i*i)) spl.push_back(i*i);
			
	//for (i = 0; i < spl.size(); i++) printf("%lld\n", spl[i]);
	
	scanf("%lld", &t);
	for (tc = 1; tc <= t; tc++)
	{
		scanf("%lld %lld", &l, &r);
		for (i = 0; i < spl.size(); i++) if (spl[i] > r) break;
		a1 = i;
		for (i = 0; i < spl.size(); i++) if (spl[i] >= l) break;
		a2 = i;
		printf("Case #%lld: %lld\n", tc, a1-a2);
	}
}