#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main () {
	int T, x, y;
	bool negx, negy;
	scanf("%d", &T);
	for (int kolkoskusam = 0; kolkoskusam < T; kolkoskusam ++) {
		printf("Case #%d: ", kolkoskusam + 1);
		scanf("%d %d", &x, &y);
/*		if (x < 0) negx = true;
		else negx = false;
		if (y < 0) negy = true;
		else negy = false;
*/		while (x != 0) {
			if (x > 0) {
				printf("WE");
				x --;
			}
			else {
				printf("EW");
				x ++;
			}
		}
		while (y != 0) {
			if (y > 0) {
				printf("SN");
				y --;
			}
			else {
				printf("NS");
				y ++;
			}
		}
		printf("\n");
	}
	return 0;
}