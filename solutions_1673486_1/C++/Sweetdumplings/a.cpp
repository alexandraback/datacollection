#include <cstdio>
#include <cstring>
int n;
double p[100005];
void Main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for (int i=1;i<=a;++i) scanf("%lf",p+i);
	//keeping typing
	double ans1=0;
	double right=1;
	for (int i=1;i<=a;++i) right*=p[i];
	ans1=right*(b+1-a)+(1-right)*(b+2-a+b);
	//retype
	double ans2=2+b;
	if (ans2<ans1) ans1=ans2;
	//backspace
	for (int k=1;k<a;++k){
		right=1;
		for (int i=1;i<=k;++i) right=right*p[i];
		double tmp=right*(a-k+a-k+b-a+1)+(1-right)*(a-k+a-k+b-a+1+b+1);
		if (tmp<ans1) ans1=tmp;
	}
	printf("%lf\n",ans1);
}
int main(){
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;++i){
		fprintf(stderr,"%d\n",i);
		printf("Case #%d: ",i);
		Main();
	}
	return 0;
}
