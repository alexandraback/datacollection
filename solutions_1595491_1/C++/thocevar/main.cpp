#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int tests;
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++) {
		int n,s,p,x,r=0;
		scanf("%d %d %d",&n,&s,&p);
		for (int i=1;i<=n;i++) {
			scanf("%d",&x);
			if (x==0 || x==1 || x==29 || x==30) {
				if (3*p-2<=x) r++;
			} else {
				if (x<3*p-4) {
					continue;
				} else if (x<3*p-2) {
					if (s>0) { s--; r++; }
				} else {
					r++;
				}
			}
		}
		printf("Case #%d: %d\n",test,r);
	}
    return 0;
}
