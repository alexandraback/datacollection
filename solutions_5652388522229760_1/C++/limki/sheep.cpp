#include <cstdio>
#define GOAL ((1<<10)-1)
using namespace std;
int T,n;
long long rv,val[1000042];

int brek(long long a){
	int rv=0;
	//printf("%lld ",a);
	if (a==0)
		rv=1;
	while(a>0){
		rv |= 1<< (a%10) ;
		a/=10;
	}
	//printf("%d\n",rv);
	return rv;
}

void solve1(){
	int cur;
	val[0]=-1;
	for (long long i=1;i<1000020;i++){
		cur=0;
		val[i]=-1;
		for(int j=1;j<10000;j++){
			cur |= brek(i*j);
			if (cur==GOAL){
				val[i] = i*j;
				break;
			}
			if (j>100){
				printf("EEE\n");
				break;
			}
		}
	}
	
}

int main(){
	solve1();
	//solve2();
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&n);
		rv = val[n];
		if (rv>=0)
			printf("Case #%d: %lld\n",i,rv);
		else
			printf("Case #%d: INSOMNIA\n",i);
	}	
}
