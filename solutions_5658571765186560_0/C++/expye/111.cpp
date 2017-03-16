#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const char ans[2][10] = {
	"RICHARD", "GABRIEL"	
};
int T;
int main() {
	freopen("wtf.in", "r", stdin);
	freopen("4.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int x, r, c;
		bool q = 0;
		scanf("%d%d%d", &x, &r, &c);
		if (x <= 4) {
			if (x == 1) q = 1;
			if (x == 2 && r * c % 2 == 0) q = 1;
			if (x == 3) {
				if (r * c % 3 == 0) q = 1;	
			}
		}
		printf("Case #%d: %s\n", i, ans[q]);
	}
	return 0;
}
