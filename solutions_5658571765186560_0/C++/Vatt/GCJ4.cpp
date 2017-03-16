#include <stdio.h>
#include <algorithm>
using namespace std;
int t,x,r,c;
int main(int argc, char *argv[])
{
	scanf("%d",&t);
	for(int rr=1;rr<=t;rr++) {
		printf("Case #%d: ",rr);
		scanf("%d %d %d",&x,&r,&c);
		if(r>c) {
			r^=c;
			c^=r;
			r^=c;
		}
		if((r*c)%x!=0) printf("RICHARD\n");
		else if(x>c) printf("RICHARD\n");
		else if(r==1) {
			if(x>2) printf("RICHARD\n");
			else printf("GABRIEL\n");
		}
		else if(r==2) {
			if(x>3) printf("RICHARD\n");
			else printf("GABRIEL\n");
		}
		else if(x>=7) {
			printf("RICHARD\n");
		}
		else if(x<=5) {
			printf("GABRIEL\n");
		}
		else if(x==6) {
			if(r==3) printf("RICHARD\n");
			else if(r>3) {
				printf("GABRIEL\n");
			}
		}
	}
	return 0;
}
