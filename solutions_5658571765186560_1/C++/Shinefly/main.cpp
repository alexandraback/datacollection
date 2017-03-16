#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline bool Work() {
	int x, r, c;
	scanf("%d %d %d ", &x, &r, &c);
	
	if (x <= 6) {
		if (r % x == 0 && c >= x - 1) return true;
		if (c % x == 0 && r >= x - 1) return true;
		return false;
	}
	else return false;
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	
	int T; scanf("%d ", &T);
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		printf(Work()? "GABRIEL\n": "RICHARD\n");
	}
	
	return 0;
}
