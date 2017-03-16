#include <iostream>

using namespace std;

int main() {
	int t, r, c, w;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i) {
		scanf("%d %d %d", &r, &c, &w);
		int result = (r - 1) * int(c / w);
		if(c % w == 0) {
			printf("Case #%d: %d\n", i, result + c / w + w - 1);
		}
		else {
			printf("Case #%d: %d\n", i, result + int(c / w) + w);	
		}
	}
	return 0;
}