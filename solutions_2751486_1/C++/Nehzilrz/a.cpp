#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back

char ch[1000005];

int main() {
	int T, n;
	scanf("%d", &T);
	for (int t0 = 1; t0 <= T; ++t0) {
		scanf("%s %d\n", ch, &n);
		int len = strlen(ch);
		int last = -1, t = -2;
		LL ans = 0;
		for (int i = 0; i < len; ++i) {
			if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u') {
				last = i;
			}
			if (i - last >= n) t = max(t, i - n);
			if (t >= -1) ans += t + 2;
		}
		cout << "Case #" << t0 << ": " << ans << endl;
	}
	return 0;
}
