#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAXN = 20;
const LL INF = 8e18;

int len;
LL minn[MAXN], maxx[MAXN], ten[MAXN];
char s[MAXN], t[MAXN], s2[MAXN], t2[MAXN];

LL getMin(int k)
{
	//printf("max %d\n", k);
 	forab (i, k, len)
 	{
 		if (s[i] == '?')
 			s[i] = '0';
		if (t[i] == '?')
			t[i] = '9';
	}
	return minn[k];
}

LL getMax(int k)
{
	//printf("min %d\n", k);
 	forab (i, k, len)
 	{
 		if (s[i] == '?')
 			s[i] = '9';
		if (t[i] == '?')
			t[i] = '0';
	}
	return maxx[k];
}

void restore(int k)
{
	forab (i, k, len)
		s[i] = s2[i], t[i] = t2[i];
}

LL solve(int k)
{
	//printf("solve %d\n", k);
	if (k == len)
		return 0;
	if (s[k] == '?' && t[k] == '?')
	{
		LL min1 = solve(k + 1);
		restore(k);
		LL min2 = INF, min3 = INF;
		min2 = min(min2, abs(getMax(k + 1) - ten[len - 1 - k]));
		restore(k);
		min3 = min(min3, abs(getMin(k + 1) + ten[len - 1 - k]));
		restore(k);
		//printf("%d %I64d %I64d %I64d\n", k, min1, min2, min3);
		if (min1 <= min2 && min1 <= min3)
		{
		    s[k] = t[k] = '0';
			return solve(k + 1);
		}
		if (min2 <= min1 && min2 <= min3)
		{
		    s[k] = '0';
		    t[k] = '1';
			return abs(getMax(k + 1) - ten[len - 1 - k]);
		}
		if (min3 <= min1 && min3 <= min2)
		{
			s[k] = '1';
			t[k] = '0';
			return abs(getMin(k + 1) + ten[len - 1 - k]);			
		}
	}
	if (s[k] == '?' && t[k] != '?')
	{
		LL min1 = solve(k + 1);
		restore(k);
		LL min2 = INF, min3 = INF;
		if (t[k] != '0')
			min2 = min(min2, abs(getMax(k + 1) - ten[len - 1 - k]));
		restore(k);
		if (t[k] != '9')
			min3 = min(min3, abs(getMin(k + 1) + ten[len - 1 - k]));
		restore(k);
		//printf("%d %I64d %I64d %I64d\n", k, min1, min2, min3);
		if (min2 <= min1 && min2 <= min3)
		{
		   	s[k] = t[k] - 1;
			return abs(getMax(k + 1) - ten[len - 1 - k]);
		}
		if (min1 <= min2 && min1 <= min3)
		{
		    s[k] = t[k];
			return solve(k + 1);
		}                   	
		if (min3 <= min1 && min3 <= min2)
		{
		    s[k] = t[k] + 1;
			return abs(getMin(k + 1) + ten[len - 1 - k]);
		}
	}
	if (s[k] != '?' && t[k] == '?')
	{
		LL min1 = solve(k + 1);
		restore(k);
		LL min2 = INF, min3 = INF;
		if (s[k] != '0')
			min2 = min(min2, abs(getMin(k + 1) + ten[len - 1 - k]));
		restore(k);
		if (s[k] != '9')
			min3 = min(min3, abs(getMax(k + 1) - ten[len - 1 - k]));
		restore(k);
		//printf("22 %d %I64d %I64d %I64d\n", k, min1, min2, min3);
		if (min2 <= min1 && min2 <= min3)
		{
		    t[k] = s[k] - 1;
			return abs(getMin(k + 1) + ten[len - 1 - k]);
		}
		if (min1 <= min2 && min1 <= min3)
		{
		    t[k] = s[k];
			return solve(k + 1);
		}
		if (min3 <= min1 && min3 <= min2)
		{
		    t[k] = s[k] + 1;
			return abs(getMax(k + 1) - ten[len - 1 - k]);
		}
	}
	if (s[k] != '?' && t[k] != '?')
	{
	    if (s[k] == t[k])
	    	return solve(k + 1);
		if (s[k] < t[k])
		{
			return abs(getMax(k + 1) + ten[len - 1 - k] * (s[k] - t[k]));
		}
		if (s[k] > t[k])
			return abs(getMin(k + 1) + ten[len - 1 - k] * (s[k] - t[k]));			
	}
	assert(0);
}

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int tests;
	scanf("%d", &tests);
	forn (tt, tests)
	{
		scanf("%s %s", s, t);
		len = strlen(s);
		forn (i, len)
			s2[i] = s[i], t2[i] = t[i];
		ten[0] = 1;
		forab (i, 1, 19)
			ten[i] = ten[i - 1] * 10;
		maxx[len] = minn[len] = 0;
		fornr (i, len)
		{
			maxx[i] = maxx[i + 1];
			minn[i] = minn[i + 1];
			if (s[i] == '?')
			{
				maxx[i] = maxx[i] + ten[len - 1 - i] * 9;
				minn[i] = minn[i] + ten[len - 1 - i] * 0;
			}
			else
			{
				maxx[i] = maxx[i] + ten[len - 1 - i] * (s[i] - '0');
				minn[i] = minn[i] + ten[len - 1 - i] * (s[i] - '0');
			}
			if (t[i] == '?')
			{
				maxx[i] = maxx[i] - ten[len - 1 - i] * 0;
				minn[i] = minn[i] - ten[len - 1 - i] * 9;
			}
			else
			{
				maxx[i] = maxx[i] - ten[len - 1 - i] * (t[i] - '0');
				minn[i] = minn[i] - ten[len - 1 - i] * (t[i] - '0');
			}
		}
		//printf("%I64d %I64d\n", minn[2], maxx[2]);
    	solve(0);
    	printf("Case #%d: %s %s\n", tt + 1, s, t);
    }	

	return 0;
}