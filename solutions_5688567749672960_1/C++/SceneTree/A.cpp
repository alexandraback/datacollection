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

int Tests;
char s[100];
int64 n;

int main()
{
	int tts = 0;
	for (scanf("%d", &Tests); Tests--; ) {
		scanf("%lld", &n);
		int64 ans = 0;
		if (n % 10 == 0) {
			n--;
			++ans;
		}
		if (n < 10) {
			ans += n;
			n = 1;
		}

		for (; n > 1; ) {
			sprintf(s, "%lld", n);
			int l = strlen(s);
			int64 tmp = 0;
			for (int i = l / 2; i < l; ++i) {
				tmp = tmp * 10 + s[i] - '0';
			}
			ans += tmp;
			reverse(s, s + l);
			tmp = 0;
			for (int i = (l + 1) / 2; i < l; ++i) {
				tmp = tmp * 10 + s[i] - '0';
			}
			ans += tmp;
			if (tmp > 1) ans++;
			n = 0;
			for (int i = 0; i < l - 1; ++i) n = n * 10 + 9;
		}
		printf("Case #%d: %lld\n", ++tts, ans);
	}
	return 0;
}