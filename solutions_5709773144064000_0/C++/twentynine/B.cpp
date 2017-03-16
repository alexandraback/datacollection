#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	
//freopen("B-small-attempt0.in", "r", stdin);
//freopen("B-small-attempt0.out", "w", stdout);
    int tc;
    scanf("%d",&tc);
    for(int ii=1;ii<=tc;ii++){
		double C,F,X,n,ans=0;
		int i,j,m;
		scanf("%lf %lf %lf",&C,&F,&X);
		n=X/C-2/F-1;
		n=n+0.9999999;
		m=(int)n;
		if(n<0)m=0;
		
		for(i=0;i<=m-1;i++)ans+=(double)C/(2+i*F);
		ans+=(double)X/(2+m*F);
		
		printf("Case #%d: %.7lf\n",ii,ans);

	}
	return 0;
}		
             
			                  
