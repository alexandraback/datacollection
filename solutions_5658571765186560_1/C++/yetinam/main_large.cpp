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
		if (x>=7) {
			printf("Case #%d: RICHARD\n",d);
			continue;
		}
		if ((r*c)%x!=0) {
			printf("Case #%d: RICHARD\n",d);
			continue;
		}
		if (x==1) {
			printf("Case #%d: GABRIEL\n",d);
			continue;
		}
		if (x==2) {
			printf("Case #%d: GABRIEL\n",d);
			continue;
		}
		if (x==3) {
			if (min(r,c)>=2) {
				printf("Case #%d: GABRIEL\n",d);
				continue;
			} else {
				printf("Case #%d: RICHARD\n",d);
				continue;
			}
		}
		if (x==4) {
			if (max(r,c)>=4&&min(r,c)>2) {
				printf("Case #%d: GABRIEL\n",d);
				continue;
			} else {
				printf("Case #%d: RICHARD\n",d);
				continue;
			}
		}
		if (x==5) {
			if (min(r,c)>=4) {
				printf("Case #%d: GABRIEL\n",d);
				continue;
			} else {
				printf("Case #%d: RICHARD\n",d);
				continue;
			}
		}
		if (x==6) {
			if (max(r,c)>=6&&min(r,c)>=4) {
				printf("Case #%d: GABRIEL\n",d);
				continue;
			} else {
				printf("Case #%d: RICHARD\n",d);
				continue;
			}
		}
	}
	return 0;
}
