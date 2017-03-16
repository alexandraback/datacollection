#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	double c,f,x,p,best,buy,nbuy;
	int t;
	scanf("%d",&t);
	for(int test=1; test<=t; test++){
		scanf("%lf %lf %lf",&c,&f,&x);
		p=2.0;
		best = 0;
		do{
			nbuy = x/p;
			buy = c/p + x/(p+f);
			//printf("%lf %lf\n",nbuy, buy );
			if( nbuy <= buy ){
				best+=nbuy;
				break;
			}else{
				best+=c/p;
				p+=f;
			}
		}while( buy < nbuy );

		printf("Case #%d: %.7lf\n",test,best);
	}
	return 0;
}