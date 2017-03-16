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
	int cases;
	scanf("%d", &cases);
	for (int T = 1; T <= cases; ++T) {
		int N, S, P;
		scanf("%d %d %d", &N, &S, &P);
		printf("Case #%d: ", T);
		int result = 0;
		for (int i = 0; i < N; ++i) {
			int sum;
			scanf("%d", &sum);
			if (sum/3 >= P || (sum%3 != 0 && sum/3+1 >= P)) {
				result += 1;
			} else if (S > 0) {
				if (sum >= 2 && (sum-2)/3+2 >= P) {
					result += 1;
					S -= 1;
				}
			}
		}
		printf("%d\n", result);
	}
	return 0;
}
