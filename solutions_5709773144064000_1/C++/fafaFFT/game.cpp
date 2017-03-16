#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

#define PB push_back
typedef long double LD;

int main() {
	int id=1;int t;scanf("%d",&t);
	while(t--) {
		LD c,s,f,x;
		s=2;
		double fc,ff,fx;
		scanf("%lf %lf %lf",&fc,&ff,&fx);
		c=fc;f=ff;x=fx;
		LD res = x/s;
		
		LD bud = 0;
		int maleje = 1;
		int ile = 0;
		while(maleje) {
			maleje = 0;
			LD budowanie = bud + c/(s+ile * f);  
			LD nowyczas = budowanie + x /(s+(ile+1)*f);
			bud = budowanie;
			ile++;
			if(res > nowyczas) {
				res = nowyczas;
				maleje = 1;
				//printf("%lf ",(double)res);
			}
		}
		
		printf("Case #%d: %.7llf\n",id++,(double)res);
	}
	return 0;
}
