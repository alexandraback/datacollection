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

int used[MAXN];

void foo(LL k)
{
	while (k > 0)
		used[k % 10] = 1, k /= 10;	
}

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int t;
	scanf("%d", &t);
	forn (tt, t)
	{
		forn (j, 10)
			used[j] = 0;
		int n;
		scanf("%d", &n);
		printf("Case #%d: ", tt + 1);
		if (n == 0)
		{
			puts("INSOMNIA");
			continue;			
		}
		LL k = 0;
		while (1)
		{
			bool ok = 1;
			forn (j, 10)
				if (used[j] == 0)
					ok = 0;
			if (ok)
				break;
			k += n;
			foo(k);
		}
		printf("%I64d\n", k);
	}

	return 0;
}