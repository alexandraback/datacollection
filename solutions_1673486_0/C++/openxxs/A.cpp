#include <stdio.h>
#include <stdlib.h>

double p[100000];

int main(int argc, char** argv){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	int T, a,b;
	int backstep;
	double result,tmp,psar;
	scanf("%d",&T);
	int i,j;
	for(i=1; i<=T; i++){
		scanf("%d%d",&a,&b);
		for(j=0; j<a; j++){
			scanf("%lf",&p[j]);
		}
		result = 2+b;
		psar = p[0];
		for(backstep=a-1; backstep>=0; backstep--){
			tmp = backstep + psar*(b-(a-backstep)+1) + (1-psar)*(2*b-(a-backstep)+2);
			if(tmp < result){
				result = tmp;
			}
			psar *= p[a-backstep];
		}
		printf("Case #%d: %.6lf\n",i,result);
	}
	return 0;
}