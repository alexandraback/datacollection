#include<cstring>
#include<cstdio>
using namespace std;

int a[77];
int main() {
	printf("Case #1:\n");
	int cnt(0);
	for(int msk(0); msk < (1 << 15); msk++) {
		a[0] = 1;
		for(int i(0); i < 15; i++) {
			a[i * 2 + 1] = a[i * 2 + 2] = (msk & (1 << i)) > 0;
		}
		a[31] = 1;
		for(int i(0); i < 32; i++) {
			printf("%d", a[i]);
		}
		printf(" 3 4 5 6 7 8 9 10 11\n");
		cnt++;
		if(cnt == 500) {
			break;
		}
	}
}
