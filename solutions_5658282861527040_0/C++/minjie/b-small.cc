
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define MAXN 200

int main() {
	int T, a, b, k;
	scanf("%d", &T);
	for(int it = 1;it <= T; ++it) {
		int ans = 0;
		scanf("%d%d%d", &a, &b, &k);
		for(int i = 0;i < a; ++i) {
			for(int j = 0;j < b; ++j) {
				if ((i & j) < k) ans ++;
			}
		}
		printf("Case #%d: %d\n", it, ans);
	}
}
