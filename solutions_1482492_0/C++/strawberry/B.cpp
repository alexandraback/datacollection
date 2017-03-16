#include<iostream>
#include<cmath>
using namespace std;
double Time[3000],Dis[3000],acc;

int main(){
	int i,j,np,na;
	int c,cas;
	double high,v,answer,tmp;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&cas);
	for(c=1;c<=cas;c++){
		scanf("%lf%d%d",&high,&np,&na);
		for(i=0;i<np;i++)
			scanf("%lf%lf",&Time[i],&Dis[i]);
		printf("Case #%d:\n",c);
		for(i=0;i<na;i++){
			scanf("%lf",&acc);
			if(Dis[0]>high)
				answer=sqrt(2.0*high/acc);
			else{		
				v=(0.0+Dis[1]-Dis[0])/(0.0+Time[1]-Time[0]);					
				tmp=(high-Dis[0])/v;
				answer=sqrt(2.0*high/acc);
				if(answer<=tmp)
					answer=tmp;
			}
			printf("%lf\n",answer);
		}
	}
	return 0;
}
