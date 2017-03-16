#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline bool Work() {
	int x, r, c;
	scanf("%d %d %d ", &x, &r, &c);
	
	if (x == 1) return true;
	else if (x == 2) return r * c % 2 == 0;
	else if (x == 3) {
		if (r % 3 == 0 && c >= 2) return true;
		if (c % 3 == 0 && r >= 2) return true;
		return false;	
	}
	else if (x == 4) {
		if (r % 4 == 0 && c >= 3) return true;
		if (c % 4 == 0 && r >= 3) return true;
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
