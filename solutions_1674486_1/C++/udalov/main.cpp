#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define forit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define eprintf(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#define sz(v) ((int)((v).size()))
typedef pair<int, int> ii;
typedef long long LL;

#define N 100500
vector<int> a[N];
int q[N];
int b[N];

int main() {
	int __;
	scanf("%d", &__);
	forn(_, __) {
		int n;
		scanf("%d", &n);
		forn(i, n) {
			a[i].clear();
			int k, x;
			scanf("%d", &k);
			forn(___, k) {
				scanf("%d", &x);
				x--;
				a[i].push_back(x);
			}
		}
		
		bool ans = false;
		forn(start, n) {
			forn(i, n) b[i] = 0;
			b[start] = 1;
			int qb = 0, qe = 0;
			q[qe++] = start;
			while (qb < qe) {
				int v = q[qb++];
				forit(it, a[v]) {
					if (b[*it]) {
						ans = true;
						goto end;
					}
					b[*it] = 1;
					q[qe++] = *it;
				}
			}
		}
		
		end:
		printf("Case #%d: ", _+1);
		puts(ans ? "Yes" : "No");
	}
	return 0;
}
