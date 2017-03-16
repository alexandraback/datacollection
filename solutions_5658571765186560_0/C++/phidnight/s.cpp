#include <cstdio>

int T,R,C,X;
int judge(int nx,int nr,int nc) {
	if(nr>nc) return judge(nx,nc,nr);
	if(nx>6) return 0;
	if((nr*nc)%nx) return 0;
	if(nx<3) return 1;
	if(nx==3&&nr==1) return 0;
	if(nx==4&&nr<=2) return 0;
	if(nx==5) {
		if(nr<=2) return 0;
		if(nr==3&&nc==5) return 0;
	}
	if(nx==6&&nr<=3) return 0;
	return 1;
}
int main() {
	scanf("%d",&T);
	for(int tn=1;tn<=T;tn++) {
		scanf("%d%d%d",&X,&R,&C);
		if(judge(X,R,C)) {
			printf("Case #%d: GABRIEL\n",tn);
		} else {
			printf("Case #%d: RICHARD\n",tn);
		}
	}
	return 0;
}
