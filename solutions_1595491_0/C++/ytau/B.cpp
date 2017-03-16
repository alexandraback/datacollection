


#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <sstream>
#include <string>

#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <algorithm>

#include <utility>
// ytau (HK)
using namespace std;



const int inf = 2000000000;
const long long linf = 9000000000000000000LL;
const double finf = 1.0e18;
const double eps = 1.0e-8;


int T, N, S, p, t, ans1, ans2;

int main() {
	scanf("%d", &T);
	for (int tt=1; tt<=T; tt++) {
		scanf("%d%d%d", &N, &S, &p);
		ans1 = ans2 = 0;
		for (int i=0; i<N; i++) {
			scanf("%d", &t);
			int tmp = (t+2)/3;
			if (tmp >= p) ans1++;
			else if ((2<=t) && (t<=28) && ((t+1)/3+1>=p)) ans2++;
		}
		printf("Case #%d: %d\n", tt, ans1 + min(S, ans2));
	}
	return 0;
}


