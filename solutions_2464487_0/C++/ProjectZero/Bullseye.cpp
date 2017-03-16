#include <cstdio>
#include <cmath>

const long long MAXT = 2e18;
const int MAXN = 1000005;
long long areasum,area,r,t;
int T;

long long sum[MAXN];

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	
	FILE *fout;
	fout = fopen("A-small.out","w");
	
	scanf("%d",&T);
	for(int _i=1;_i<=T;_i++){
		scanf("%lld %lld",&r,&t);
		
		areasum = 0;
		
		int cc = 0;
		long long rnow = r;
		area = 0;
		
		do{
			areasum += (rnow+1+rnow);
			if(areasum > t) break;
			rnow+=2;
			cc++;
		}while(area <= t);
		printf("Case #%d: %d\n",_i,cc);
		fprintf(fout,"Case #%d: %d\n",_i,cc);
		
	}
	return 0;
}