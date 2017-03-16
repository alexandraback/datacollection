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
const double eps = 1E-10;
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

const int MAXN = 200+5;
int s[MAXN];
double ans[MAXN];
int n, sum;

bool ke(double p) {
	double res = 0;
	FOR(i,n) {
		if (p > s[i])
			res += (p-s[i])/sum;
	} 
	return (res > 1-eps);
}
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int caseNum;
	scanf("%d", &caseNum);
	
	
	REP(c, 1, caseNum+1) {
		cin>>n;
		sum = 0;
		FOR(i,n) {
			cin>>s[i];
			sum += s[i];
		}	
		FOR(i,n) {
			double left = 0, right = 1;
			FOR(rr,200) {
				double mid = (left+right)/2;
				if (ke(s[i]+mid*sum)) {
					ans[i] = mid;
					right = mid;
				} else {
					left = mid;
				}
			}
		}
		
		printf("Case #%d:", c);
		FOR(i,n) printf(" %.8lf", 100*ans[i]);
		puts("");
	}
//	while (1>0) {}
	return 0;
} 
