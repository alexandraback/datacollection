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

int a[10], b[10];
int main()
{
	int Tests, tts = 0;
	for (scanf("%d", &Tests); Tests--; ) {
		int n;
		scanf("%d", &n);
		int m = 0;
		for (int i = 0; i < n; ++i) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			for (int j = 0; j < y; ++j) {
				a[++m] = x;
				b[m] = z + j;
			}
		}
		int ans = 0;
		if (m == 2) {
			if (b[1] != b[2]) {
				if (b[1] > b[2]) {
					swap(b[1], b[2]);
					swap(a[1], a[2]);
				}
				double l1 = 360 - a[1];
				double l2 = 360 - a[2];
				double x = 0;
				if (l1 > l2) {
					x = (double)(l1 * b[1] - l2 * b[2]) / (double)(b[1] - b[2]);
					l1 = x;
					l2 = x;
				} else {
					x = 1;
					l1 += 360;
				}
				if (x > 0) {
					x = (double)(l1 * b[1] - l2 * b[2]) / (double)(b[1] - b[2]);
					if (x > 0) ans = 1;
				}
			}
		}
		printf("Case #%d: %d\n", ++tts, ans);
	}
	return 0;
}