#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


const int N = 1000 + 10;

inline int Work() {
	static int n;
	static char str[N];
	
	scanf("%d %s ", &n, str);
	int ret = 0, cot = 0;
	
	for (int i = 0; i <= n; ++i) {
		if (cot < i)
			ret += (i - cot), cot = i;
		cot += str[i] - '0';
	}
	
	return ret;
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	
	int T; scanf("%d ", &T);
	for (int i = 1; i <= T; ++i)
		printf("Case #%d: %d\n", i, Work());
	
	return 0;
}
