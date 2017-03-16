#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf( "%d", &t);
	for(int z = 0; z < t; z ++) {
		int r, c, w;
		scanf(" %d %d %d", &r, &c, &w);
		printf("Case #%d: %d\n", z + 1, (c / w) * r + w - ( (c % w) == 0 ) );
	}
	return 0;
}
