#include <cstdio>
#define MAXN 200005

int n,m,cases;
double p[MAXN],q[MAXN];

double min(double x,double y){
	if(x<y)return x;
	else return y;
}

int main(){
	scanf("%d",&cases);
	for(int xx = 1; xx <= cases; ++xx){
		double ans = 999999999;
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n; ++i)
			scanf("%lf",&p[i]);
		q[0] = p[0];
		for(int i = 1; i < n; ++i)
			q[i] = q[i-1] * p[i];
		//keep trying
		ans = min(ans, q[n-1]*(m-n+1)*1.0+(1-q[n-1])*(m-n+1+m+1)*1.0);
		//all clear
		ans = min(ans, 1+m+1);
		//backspace
		for(int i = 0; i < n; ++i){
			int countpress = n - i - 1;
			ans = min(ans, q[i]*(countpress+(m-i))+(1-q[i])*(countpress+(m-i)+(m+1)));
		}
		printf("Case #%d: %.6lf\n",xx,ans);
	}
}
