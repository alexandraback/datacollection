#include<stdio.h>
int a[30],n,flag=0;
int b[30];
void f(int k, int sum1, int sum2) {
	if (flag==1) return;
	if (k==n+1) {
		if (sum1==sum2 && sum1!=0) {
			int i;
			for(i=1;i<=n;i++) {
				if (b[i]==1) printf("%d ",a[i]);
			}
			printf("\n");
			for(i=1;i<=n;i++) {
				if (b[i]==2) printf("%d ",a[i]);
			}
			printf("\n");
			flag=1;
		}
	}
	else {
		b[k]=0;
		f(k+1,sum1,sum2);
		if (flag==1) return;
		b[k]=1;
		f(k+1,sum1+a[k],sum2);
		if (flag==1) return;
		b[k]=2;
		f(k+1,sum1,sum2+a[k]);
	}
}
int main () {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,i,j;
	scanf("%d",&t);
	for(i=1;i<=t;i++) {
		scanf("%d",&n);
		for(j=1;j<=n;j++) scanf("%d",&a[j]);
		flag=0;
		printf("Case #%d: \n",i);
		f(1,0,0);
	}
	return 0;
}
