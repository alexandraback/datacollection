#include<cstdio>
#include<cstring>

int main() {
	int t;
	scanf("%d", &t);
	for (int ii = 1;ii <= t;ii++) {
		bool flag = false;
		int x, r, c;
		scanf("%d%d%d", &x, &r, &c);

		if (x >= 4) {
			flag = false;
		}  
		if (x == 1) {
			flag = true;
		} 
		if (x == 2) {
			if (r * c % x == 0) {
				flag = true;
			} else {
				flag = false;
			}
		}
		if (x == 3) {
			if (r * c % 3 != 0) {
				flag = false;
			} else {
				if ((r % 3 == 0 && c % 2 == 0) || (c % 3 == 0 && r % 2 == 0)) {
					flag = true;
				} else {
					flag = false;
				}
			}
		}
		// if (x == 4) {
		// 	if (r * c % 4 != 0) {
		// 		flag = false;
		// 	} else if (r % 2 == 1 || c % 2 == 1) {
		// 		flag = false;
		// 	} else if (r == 2 && c == 2) {
		// 		flag = false;
		// 	} else {
		// 		flag = true;
		// 	}
		// }
		if (flag) {
			printf("Case #%d: GABRIEL\n", ii);
		} else {
			printf("Case #%d: RICHARD\n", ii);
		}

	}
	return 0;
}