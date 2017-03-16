#include<stdio.h>
int main () {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,i,j;
	scanf("%d",&t);
	for(i=1;i<=t;i++) {
		int n;
		scanf("%d",&n);
		double a[1000],sum=0;
		int chk[1005];
		for(j=1;j<=1000;j++) chk[j]=0;
		for(j=1;j<=n;j++) {
			scanf("%lf",&a[j]);
			sum+=a[j];
		}
		double tempsum1=sum; // sum 숫자 기록
		double tempsum=sum; // 남아있는 사람들의 judge 합
		double person=n;
		sum*=2;
		sum/=person;
		while(1) {
			int flag=0;
			for(j=1;j<=n;j++) {
				if (a[j]>sum && chk[j]==0) {
					chk[j]=1;
					flag=1;
					tempsum-=a[j];
					person--;
				}
			}
			if (flag==0) break;
			sum=(tempsum1+tempsum)/person;
		}
		printf("Case #%d: ",i);
		for(j=1;j<=n;j++) {
			if (sum-a[j]<0) printf("0.000000 ");
			else printf("%f ",(sum-a[j])/tempsum1*100);
		}
		printf("\n");
	}
	return 0;
}
