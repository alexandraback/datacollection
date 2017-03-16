#include <bits/stdc++.h>
using namespace std;
int main() {
	int tc;
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> tc;
	for (int q=1; q <=tc; q++) {
		int a=0,b=0,counter = 0;
		bool flag = false;
		char c;
		scanf("%d%c%d", &a,&c,&b);
		int temp = b;
		while (temp != 2) {
			temp /= 2;
			if (temp %2 != 0) {
				printf("Case #%d: impossible\n", q);
				flag = true;
				break;
			}
		}
		if (flag) continue;
		while (a/b < 1) {
			a *= 2;
			counter++;
		}
			
		printf("Case #%d: %d\n", q, counter);
	}
}
