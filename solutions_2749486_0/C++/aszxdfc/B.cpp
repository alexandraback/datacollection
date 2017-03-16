#include<iostream>
#include<math.h>
using namespace std;
int x, y;
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("outB.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++) {
        scanf("%d%d",&x,&y);
		printf("Case #%d: ", i + 1);
		if(y > 0) {
			for(int j = 0; j < y; j++) {
				printf("SN");
			}
		}
		else {
			for(int j = 0; j < -y; j++) {
				printf("NS");
			}
		}
		if(x > 0) {
			for(int j = 0; j < x; j++) {
				printf("WE");
			}
		}
		else {
			for(int j = 0; j < -x; j++) {
				printf("EW");
			}
		}
		printf("\n");
	}
	return 0;
}

