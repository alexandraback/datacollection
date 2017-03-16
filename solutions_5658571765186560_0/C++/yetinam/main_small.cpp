#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int d=1;d<=t;d++) {
		int x,r,c;
		scanf("%d%d%d",&x,&r,&c);
		if (x==1) {
			printf("Case #%d: GABRIEL\n",d);
		}
		if (x==2) {
			if ((r*c)%2==0) {
				printf("Case #%d: GABRIEL\n",d);
			} else {
				printf("Case #%d: RICHARD\n",d);
			}
		}
		if (x==3) {
			if ((r*c)%3!=0) {
				printf("Case #%d: RICHARD\n",d);
			} else {
				if (r*c==3) {
					printf("Case #%d: RICHARD\n",d);
				} else {
					printf("Case #%d: GABRIEL\n",d);
				}
			}
		}
		if (x==4) {
			if ((r<4&&c<4)||((r*c)%4!=0)) {
				printf("Case #%d: RICHARD\n",d);
			} else {
				if (min(r,c)<3) {
					printf("Case #%d: RICHARD\n",d);
				} else {
					printf("Case #%d: GABRIEL\n",d);
				}
			}
		}
	}
	return 0;
}
