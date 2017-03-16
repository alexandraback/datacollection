#include<stdio.h>
double con[205];
int n;
int main(){
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	int t,ti;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++){
		printf("Case #%d:",ti); 
		scanf("%d",&n);
		int i,num;
		double sum,ssum=0;
		for(i=0;i<n;i++){
			scanf("%lf",&con[i]);
			ssum+=con[i];
		}
		num=n;
		sum=ssum;
		for(i=0;i<n;i++){
			//printf("%lf ",(2*ssum-n*con[i])/n/ssum);
			if((2*ssum-n*con[i])/n/ssum<0){
				num--;
				sum-=con[i];
				//printf("%lf\n",con[i]);
			}
		}
		for(i=0;i<n;i++){
			double ans;
			if((2*ssum-n*con[i])/n/ssum<0)
				ans=0;
			else
				ans=(ssum+sum-num*con[i])/num/ssum;
			printf(" %lf",ans*100);
		}		
		printf("\n");
	}
	return 0;
}