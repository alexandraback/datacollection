#include <iostream>

using namespace std;

int main() {
	int t, r, c, w;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i) {
		scanf("%d %d %d", &r, &c, &w);
		if(c % w == 0) {
			printf("Case #%d: %d\n", i, c / w + w - 1);
		}
		else {
			printf("Case #%d: %d\n", i, int(c / w) + w);	
		}
	}
	return 0;
}