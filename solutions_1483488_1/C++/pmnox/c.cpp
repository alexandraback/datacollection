#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

void doit(){
	int a, b;
	scanf("%d %d", &a, &b);
	int ret = 0;
	for (int i = a; i <= b; i++) {
		int num = i;
		int dig = 1; int tmp = i;
		while (tmp >= 1) { dig *= 10; tmp /= 10; }

		for (int k = 0; k < 10; k++) {
			int next = (num / 10 + (num % 10 * (dig / 10)));
			if (next == i) break;
			if (next > i && next <= b)
				ret++;
			num = next;
		}
	}
	printf("%d", ret);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i=1;i<=t;i++){
		printf("Case #%d: ", i);
		doit();
		printf("\n");
	}

	return 0;
}
