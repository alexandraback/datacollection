#include<cstdio>
#include<cstring>

#define N 1000005
using namespace std;

int tc;
int y,x;
int main() {
	int i,j,k;
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	scanf("%d", &tc);
	for(int tcc = 1; tcc<= tc; tcc++){
		scanf("%d %d ", &x, &y);
		printf("Case #%d: ", tcc);
		if (y > 0) {
			char str[] = "SN";
			for(i = 0; i < y; i++)
				printf("%s", str);
		} else if (y < 0) {
			char str[] = "NS";
			for(i = 0; i < -y; i++)
				printf("%s", str);
		}
		if (x > 0) {
			char str[] = "WE";
			for(i = 0; i < x; i++)
				printf("%s", str);
		} else if (x < 0) {
			char str[] = "EW";
			for(i = 0; i < -x; i++)
				printf("%s", str);
		}
		printf("\n");
	}
	return 0;
}