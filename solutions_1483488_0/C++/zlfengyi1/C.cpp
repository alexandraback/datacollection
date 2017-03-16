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

const int MAXN =  2000000+5;
bool f[MAXN];
vector<int> va[MAXN];

void init() {
	ME(f);
	for (int i = 10; i < MAXN; i++) if (!f[i]) {
		f[i] = true;
		int base = 1;
		int x = i;
		va[i].push_back(i);
		while (x > 9) {
			base *= 10;
			x /= 10;
		}
		x = i;
		while (1>0) {
			if (x % 10 == 0) { x /= 10; continue;}
			x = base*(x%10) + x/10;
			if (x == i) break;
			if (x >= MAXN) continue;
			f[x] = true;
			va[i].push_back(x);
			
		}
	}
}
int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	init();
	int caseNum;
	scanf("%d", &caseNum);
	
	
	REP(c, 1, caseNum+1) {
		int A, B;
		scanf("%d%d", &A, &B);
		int ans = 0;
		for (int i = 1; i < MAXN; i++) if (va[i].size() >= 2) {
			int tmp = 0;
			FOR(j, va[i].size()) {
				if (va[i][j] >= A && va[i][j] <= B) tmp++;
			}
			ans += tmp*(tmp-1)/2;
		}
		printf("Case #%d: ", c);
		printf("%d\n", ans);
	};
//	while (1>0) {}
	return 0;
} 
