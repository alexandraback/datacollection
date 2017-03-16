//Grzegorz Chuchro
#include <stdio.h>

int main(){
	long double minpowerof2 = 1.0;
	int i = 0;
	while(i<40) minpowerof2 /= 2.0, ++i;
	
	int t, result;
	unsigned long long int p,q;
	long double pq, power_of2 ,pd, qd, pq2;
	scanf("%d",&t);
	int t2 = 1;
	while(t2<=t){
		scanf("%llu/%llu", &p, &q);
		//printf("%llu\n", q);
		pd = (long double)p;
		//printf("@%Lf\n", pd);
		qd = (long double)q;
		//pq = ((long double)p)/((long double)q);
		pq2 = pq = pd/qd;
		
		power_of2 = 1.0;
		while(pq2>0 && power_of2>=minpowerof2){ //power_of2>0.0
			while(pq2>=power_of2) pq2 -= power_of2;
			power_of2 /= 2.0;
		}
		if(pq2>0){
			printf("Case #%d: impossible\n", t2);
			++t2;
			continue;
		}
		
		power_of2 = 1.0/2.0;
		result = 1;
		while(pq<power_of2){
			power_of2 /= 2.0;
			++result;
		}
		
		//printf("Case %d: %d %lf %llu %llu\n", t2, result, pq, p, q);
		printf("Case #%d: %d\n", t2, result);
		++t2;
	}

	return 0;
}
