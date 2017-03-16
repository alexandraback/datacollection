#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define SZ(x) ((int) (x).size())
#define maxit(x,y) ((x) = max((x),(y)))
#define minit(x,y) ((x) = min((x),(y)))
typedef long long LL;

int main()
{
	setlinebuf(stdout);
	int cases;
	scanf("%d", &cases);
	for (int T = 1; T <= cases; ++T) {
		int A, B;
		int cnt = 0;
		scanf("%d %d", &A, &B);
		printf("Case #%d: ", T);
		for (int n = A; n <= B; ++n) {
			char buf[64], buf2[64];
			sprintf(buf, "%d", n);
			int len = strlen(buf);
			set<int> was;
			for (int j = 1; j < len; ++j) {
				strcpy(buf2, buf+j);
				char t = buf[j];
				buf[j] = 0;
				strcat(buf2, buf);
				buf[j] = t;
				int m;
				sscanf(buf2, "%d", &m);
				if (n < m && A <= m && m <= B && was.find(m) == was.end()) {
					cnt += 1;
					//printf("(%d %d)\n", n, m);
					was.insert(m);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
