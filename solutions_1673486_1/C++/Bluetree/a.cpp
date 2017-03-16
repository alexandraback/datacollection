#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define oo 200005

double s[oo],p[oo];
int n,m,Test;
double xx,res;
int main()
{
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	scanf("%d",&Test);
	for (int t=1;t<=Test;++t){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i) scanf("%lf",&p[i]);
		
		double R=1;
		for (int i=1;i<=n;++i){
			s[i]=s[i-1]+R*(1-p[i]);
			R*=p[i];
		}
		
		res=m+2;
		for (int i=0;i<=n;++i){
			xx=s[n-i]*(double)(2*i+2*m-n+2)+(1.0-s[n-i])*(double)(2*i+m-n+1);
			res=min(xx,res);
//			printf("%.6lf\n",xx);
		}
		
		printf("Case #%d: %.8lf\n",t,res);
	}
	
	return 0;
}
