#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define len(x) (int((x).size()))
#ifdef LOCALD
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) {}
#endif

#ifdef __linux__
#define I64d "%lld"
#else
#define I64d "%I64d"
#endif

typedef long long int int64;
typedef long double ext;

const int inf = 1000000000;


using namespace std;

const int maxn = 200;

int tests;
int s, n;
int a[maxn];

int main()
{
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
	scanf("%d", &tests);
	for (int test = 0; test < tests; test++){
		scanf("%d %d", &s, &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int mn = inf;
		int cur = 0;
		int j = 0;
		while (j < n){
			while ((j < n) && (a[j] < s)){
				s += a[j];
				j++;
			}
			mn = min(mn, cur + n - j);
			cur++;
			if (s == 1)
				break;
			s += s - 1;
		}
		printf("Case #%d: %d\n", test + 1, mn);
	}
    return 0;
}
