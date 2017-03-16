#include "bits/stdc++.h"

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

#ifdef ROOM_311
__attribute__((destructor)) void fini_main()
{
	fprintf(stderr, "Execution time = %0.0lf ms\n", clock() * 1000.0 / CLOCKS_PER_SEC);
}
#endif

#define MY_RAND 1
#if MY_RAND
uint64_t rnd_data = 0xDEADBEEFDULL;
inline void my_srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int my_rand() { rnd_data = rnd_data * 0x5DEECE66DULL + 0xB; return (rnd_data >> 17) & 0x7FFFFFFF; }
#define rand my_rand
#define srand my_srand
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }
template <class _T> inline string tostr(const _T &a) { ostringstream os(""); os << a; return os.str(); }

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int __attribute__((mode(TI))) u128;
typedef pair < int, int > PII;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-11;

#define MAXP 30008
int b[((MAXP+1) >> 5) + 10];
int c[MAXP + 8];
int pc;
int p[MAXP / 2];

__attribute__((constructor)) void gen_primes()
{
	memset(b, 0, sizeof(b));
	int sq = (int)(sqrt(MAXP) + 2);
	for(int j = 4; j <= MAXP; j += 2)
	{
		b[j >> 5] |= 1 << j;
		c[j] = 2;
	}
	for(int i=3; i<=sq; i+=2)
	{
		if (b[i >> 5] & (1 << i)) continue;
		int j = i * i;
		while (j <= MAXP)
		{
			b[j >> 5] |= 1 << j;
			c[j] = i;
			j += i * 2;
		}
	}
	b[1 >> 5] |= 1 << 1;
	pc = 0;
	for(int i=2; i<=MAXP; i++)
	{
		if (!(b[i >> 5] & (1 << i))) c[i] = i, p[pc++] = i;
	}
}

bool check(u64 x, int n, bool print_ans = false)
{
	For(base, 2, 10)
	{
		u128 cur = 0;
		u128 pp = 1;
		forn(j, n)
		{
			if (x & (1 << j)) cur += pp;
			pp *= base;
		}
		bool bb = false;
		forn(i, pc)
		{
			if (p[i] * (u64)p[i] >= cur) return false;
			if (cur % p[i] == 0)
			{
				if (print_ans) printf(" %d", p[i]);
				bb = true;
				break;
			}
		}
		if (!bb) return false;
	}
	return true;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	srand(246724);
	int tc;
	scanf("%d", &tc);
	For(tn, 1, tc)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		set < u64 > ans;
		while ((int)ans.sz < k)
		{
			u64 x = ((((u64)rand() << 1) | 1) | (1ULL << (n - 1))) & ((1ULL << n) - 1);
			if (ans.count(x)) continue;
			if (check(x, n)) ans.insert(x);
		}

		fprintf(stderr, "Case #%d: %0.0lf ms\n", tn, clock() * 1000.0 / CLOCKS_PER_SEC);
		printf("Case #%d:\n", tn);
		fori(it, ans)
		{
			ford(j, n)
			{
				putchar('0' + ((*it >> j) & 1));
			}
			if (!check(*it, n, true)) cerr << "Botwa !!!" << endl;
			puts("");
		}
	}
	
	return 0;
}
