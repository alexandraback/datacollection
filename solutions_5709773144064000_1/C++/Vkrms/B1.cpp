#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main(){
	int T,l,m,n;
	scanf("%d",&T);
	for (int t=1;t<=T;t++){
		double c,f,x;
		double ans=10000000;
		scanf("%lf%lf%lf",&c,&f,&x);
		double cook=0,pro=2,time=0;
		while (1){
			if (ans>time+x/pro)
				ans=time+x/pro;
			else break;
			time+=c/pro;
			pro+=f;
		}
		printf("Case #%d: %.7lf\n",t,ans);
	}
	return 0;
}
