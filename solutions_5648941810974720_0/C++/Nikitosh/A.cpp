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

const int MAXN = 4005;
const char *t[10] = {
"ZERO",
"ONE",
"TWO",
"THREE",
"FOUR",
"FIVE",
"SIX",
"SEVEN",
"EIGHT",
"NINE"
};

int a[MAXN], cnt[MAXN];
char s[MAXN];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int tests;
	scanf("%d\n", &tests);
	forn (tt, tests)
	{
		gets(s);
		int len = strlen(s);
		forn (i, 26)
			a[i] = 0;
		forn (i, len)
			a[s[i] - 'A']++;
		cnt[0] = a['Z' - 'A'];
		cnt[2] = a['W' - 'A'];
		cnt[4] = a['U' - 'A'];
		cnt[6] = a['X' - 'A'];
		cnt[8] = a['G' - 'A'];
		for (int i = 0; i < 10; i += 2)
		{
			forn (j, (int) strlen(t[i]))
				a[t[i][j] - 'A'] -= cnt[i];
		}
		cnt[1] = a['O' - 'A'];
		cnt[3] = a['T' - 'A'];
		cnt[5] = a['F' - 'A'];
		cnt[7] = a['S' - 'A'];
		for (int i = 1; i < 8; i += 2)
			forn (j, (int) strlen(t[i]))
				a[t[i][j] - 'A'] -= cnt[i];
		cnt[9] = a['I' - 'A'];
		printf("Case #%d: ", tt + 1);
		forn (i, 10)
			forn (j, cnt[i])
				printf("%d", i);
		puts("");
	}	

	return 0;
}