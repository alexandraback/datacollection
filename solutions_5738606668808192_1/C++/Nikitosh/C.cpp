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

map <vi, vi> m;

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
		int n, cnt;
		scanf("%d%d", &n, &cnt);
		printf("Case #%d:\n", tt + 1);
		vi a(n);
		m.clear();
		a[0] = a[n - 1] = 1;
		while (sz(m) != cnt)
		{
			forab (i, 1, n - 1)
				a[i] = rand() % 2;
			bool good = 1;
			vi v;
			forab (base, 2, 11)
			{
				bool ok = 0;
				forab (j, 2, 10)
				{
					int cur = 0;
					forn (i, n)
						cur = (cur * base + a[i]) % j;
					if (cur == 0)
					{
						ok = 1;
						v.pb(j);
						break;
					}
				}
				if (!ok)
				{
				    good = 0;
					break;
				}
			}
			if (good)
				m[a] = v;
		}
		for (auto np : m)
		{
			forn (i, n)
				printf("%d", np.fs[i]);
			forn (i, 9)
				printf(" %d", np.sc[i]);
		   	puts("");
		}
 	}	

	return 0;
}