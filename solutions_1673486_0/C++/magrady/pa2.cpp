#include<stdio.h>
double f[100001];
double pb[100001];
double pre[100001],suf[100001];
double num[100002];
main(){
	int i,j,k;
	int T,TN;
	int n,m;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%lf",&f[i]);
		}
		pre[0]=f[0];
		for(i=1;i<n;i++){
			pre[i]=pre[i-1]*f[i];
		}
		suf[n-1]=f[n-1];
		for(i=n-2;i>=0;i--){
			suf[i]=suf[i+1]*f[i];
		}
		suf[n]=1;
		double ttt=0;
		for(i=0;i<=n;i++){
			num[i]=0;
			for(j=0;j<n;j++){
				num[i]+=((1-f[j])*(j==0?1:pre[j-1]))*((n-j)<=i?(m-n+1+i+i):(m-n+1+m+1+i+i));
				ttt+=((1-f[j])*(j==0?1:pre[j-1]));
			}
			num[i]+=(suf[0])*(m-n+1+i+i);
			ttt+=suf[0];
		}
		
		num[n+1]=1+m+1;
		double mm=99999999;
		for(i=0;i<=n+1;i++){
			mm<?=num[i];
		}
		printf("Case #%d: %lf\n",T,mm);
	}
}
