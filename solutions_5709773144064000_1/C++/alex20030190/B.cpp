#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B2.out","w",stdout);
	int T;
	double x,y,z;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%lf %lf %lf",&x,&y,&z); //cost, extra, goal
		double ans=z/2.0,CT=0;
		for(int fc=1;CT<ans;fc++){
			CT+=x/(2+(fc-1)*y);
			ans=min(ans,CT+z/(2+fc*y));
		}
		printf("Case #%d: %.10lf\n",i,ans);
	}
	return 0;
}
