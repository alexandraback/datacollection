#include<stdio.h>
main(){
	
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small-attempt2.out","w",stdout);
	//freopen("A-small-attempt1.txt","w",stdout);
	
	int a[1001];
	int T,n,m,sum,c,i;
	double tmp,ans[1001];
	scanf("%d",&T);
	for(c=1;c<=T;c++){
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		printf("Case #%d: ",c);
		m=n;
		tmp=0.0;
		for(i=0;i<n;i++){
			ans[i]=100*(2.0*sum/n-a[i])/sum;
			if(ans[i]<0){
				tmp-=ans[i];
				ans[i]=0;
				m--;
			}
		}
		for(i=0;i<n;i++){
			if(ans[i]==0.0) printf("0.000000 ");
			else printf("%lf ",ans[i]-tmp/m);
		} 	
		printf("\n");
	}
}
