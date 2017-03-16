#include<cstdio>
using namespace std;
int T;
int A,B;
double ret,acc,curr;
int main(void){
	freopen("A2.in","r",stdin);
	freopen("A2.out","w",stdout);
	scanf("%d",&T);
	for(int l0=1;l0<=T;l0++){
		scanf("%d %d",&A,&B);
		ret=B+2;
		acc=1;
		for(int l1=1;l1<=A;l1++){
			scanf("%lf",&curr);
			acc*=curr;
			curr=acc*(A-l1+A-l1+B-A+1)+(1-acc)*(A-l1+A-l1+1+B-A+B+1);
			if(ret>curr) ret=curr;
		}
		printf("Case #%d: %.10lf\n",l0,ret);
	}

	return 0;
}