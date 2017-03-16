#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

#define Rep(i,n) for(int i = 0; i < n; ++i)
#define Rep2(i, f, t) for(int i = (f); i <= (t); ++i)
#define tr(C,it) for(__typeof__((C).begin()) it = (C).begin(); it != (C).end(); ++it)

const int maxn = 20;
typedef long long ll;
int  sum[1<<maxn];
vector<int> col[20 * 100000 + 1];
int x[maxn];
int n;

void output(int s) {
	bool isfirst = true;
	for(int i = 0,j = 1; i < n; ++i, j<<=1) {
		if((j & s) > 0) {
			if(!isfirst) {
				printf(" ");
			} else {
				isfirst = false;
			}
			printf("%d", x[i]);
		}
	}
	puts("");
}

int main() {
	int tc;
	scanf("%d", &tc);
	for(int nCase = 1; nCase <= tc; ++nCase) {
		printf("Case #%d:\n", nCase);
		scanf("%d", &n);
		Rep(i, n) {
			scanf("%d", x + i);
		}
		sum[0] = 0;
		int low;
		int maxs = 0;
		for(int i = 1; i < (1<<n); ++i) {
			low = i & -i;
			sum[i] = sum[i - low] + x[__builtin_ctz(low)];
			col[sum[i]].push_back(i);
			maxs = max(maxs, sum[i]);
		}
		bool found = false;
		for(int i = 0; i <= maxs; ++i) {
			if(col[i].size() > 1 && !found) {
				for(int j = 0; j < col[i].size() && !found; ++j) {
					for(int k = j + 1; k < col[i].size() && !found; ++k) {
						if(col[i][j] & col[i][k]) continue;
						found = true;
						output(col[i][j]);
						output(col[i][k]);
					}
				}
			}
			col[i].clear();
		}
		if(!found) {
			puts("Impossible");
		}
	}
	return 0;
}

