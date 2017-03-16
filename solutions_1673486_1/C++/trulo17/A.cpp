#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	for(int c=1;c<=T;++c){
		int A,B;
		scanf("%d%d",&A,&B);
		double res=min(B+2,A+B+1);
		double e1=1.0,p;
		for(int i=1;i<=A;++i){
			scanf("%lf",&p);
			e1*=(p);
			res=min(res,A-i+e1*(B-i+1)+(1-e1)*(2*B-i+2));
		}
		printf("Case #%d: %.9lf\n",c,res);
	}
}
