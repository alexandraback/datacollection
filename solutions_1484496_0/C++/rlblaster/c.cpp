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

int N;
int nums[510];
int last_seen[20*100010];

void print_nums(int bm)
{
	for (int i = 0; i < N; ++i) {
		if ((bm & (1<<i)) == 0) continue;
		printf("%d ", nums[i]);
	}
	puts("");
}

int main()
{
	int TC;
	scanf("%d", &TC);
	for (int ctc = 1; ctc <= TC; ++ctc) {
		scanf("%d", &N);
		assert(N == 20);
		for (int i = 0; i < N; ++i)
			scanf("%d", &nums[i]);
		memset(last_seen, 0, sizeof last_seen);
		printf("Case #%d:\n", ctc);
		for (int i = 1; i < (1<<N); ++i) {
			int sum = 0;
			for (int j = 0; j < N; ++j) {
				if ((i & (1<<j)) == 0) continue;
				sum += nums[j];
			}
			if (last_seen[sum] != 0) {
				print_nums(last_seen[sum]);
				print_nums(i);
				goto DONE;
			}
			last_seen[sum] = i;
		}
		puts("Impossible");
DONE:;
	}
	return 0;
}
