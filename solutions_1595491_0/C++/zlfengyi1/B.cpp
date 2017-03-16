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
const int inf = int(1e9)+7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

const int MAXN = 100+5;
int f[30];
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	int caseNum;
	scanf("%d", &caseNum);
	
	
	int n, s, p;
	REP(c, 1, caseNum+1) {
		scanf("%d%d%d", &n, &s, &p);
		ME(f);
		FOR(i,31) if (i >= p) {
			if (3*p-2 <= i) f[i] = 1;
			else if (3*p-4 <= i) f[i] = 2;
		}
		int ans = 0, x;
		FOR(i,n) {
			scanf("%d", &x);
			if (f[x] == 1) ans++;
			if (f[x] == 2 && s) {
				s--;
				ans++;
			}
		}
		printf("Case #%d: ", c);
		printf("%d\n", ans);
	};
//	while (1>0) {}
	return 0;
} 
