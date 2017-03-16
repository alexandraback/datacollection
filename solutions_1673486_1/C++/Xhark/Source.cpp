#include <stdio.h>
double prob[1000020];
int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T-->0) {
		int i;
		int A, B;
		scanf("%d %d",&A,&B);
		for(i=0;i<A;i++){
			scanf("%lf",&prob[i]);
		}
		double p = 1.0, ep = (double)B*2 + 99.0;
		for(i=0;i<=A;i++){
			if (i-1 >= 0) p *= prob[i-1];

			int ty = 0, fail = 0;
			if (i == 0) ty = 1;
			else {
				ty = A - i;
			}

			ty += B - i + 1;

			if (i == 0) fail = ty;
			fail = ty + B + 1;

			double ee = p * (double)ty + (1.0-p) * (double)fail;
			if (ee < ep) ep = ee;
		}
		static int cs = 1;
		printf("Case #%d: %.9lf\n", cs++, ep);
	}

}