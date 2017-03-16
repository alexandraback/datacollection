#include <cstdio>

int T,D;
int ps[1008];
int main() {
	scanf("%d",&T);
	for(int tn=1;tn<=T;tn++) {
		scanf("%d",&D);
		for(int i=0;i<D;i++) scanf("%d",&ps[i]);
		int sol=1000;
		for(int nonsp=1;nonsp<=1000;nonsp++) {
			int spcount=0;
			for(int i=0;i<D;i++) {
				if(ps[i]%nonsp) {
					spcount+=ps[i]/nonsp;
				} else {
					spcount+=ps[i]/nonsp-1;
				}
			}
			if(sol>nonsp+spcount) sol=nonsp+spcount;
		}
		printf("Case #%d: %d\n",tn,sol);
	}
	return 0;
}
