#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

int R, n, m, p;
int a[100];
int v[10000];
int b[110];

int main()
{
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C-small-1-attempt0.out", "w", stdout);

	int Tests, tts = 0;
	for (scanf("%d", &Tests); Tests--; ) {
		scanf("%d%d%d%d", &R, &n, &m, &p);

		printf("Case #%d:\n", ++tts);
		for (int o = 1; o <= R; ++o) {
			for (int i = 1; i <= p; ++i) scanf("%d", &a[i]);
			bool f1 = 1;
			for (b[1] = 2; b[1] <= m && f1; ++b[1]) {
				for (b[2] = 2; b[2] <= m && f1; ++b[2]) {
					for (b[3] = 2; b[3] <= m && f1; ++b[3]) {
						ME(v);
						v[1] = 1;
						for (int i = 1; i <= 3; ++i) v[b[i]] = 1;
						v[b[1] * b[2]] = 1;
						v[b[1] * b[3]] = 1;
						v[b[2] * b[3]] = 1;
						v[b[1] * b[2] * b[3]] = 1;

						bool ff = 1;
						for (int i = 1; i <= p; ++i)
						if (v[a[i]] == 0) {
							ff = 0;
							break;
						}
						if (ff) {
							printf("%d%d%d\n", b[1], b[2], b[3]);
							f1 = 0;
							break;
						}
					}
					if (!f1) break;
				}
				if (!f1) break;
			}
			if (f1) puts("222");
		}
	}
	return 0;
}
