#include<stdio.h>
int t;
double a[100005];
double b[100005]; // b[i]=i번째가 첫번째로 틀릴 확률
int main () {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	int i,j;
	for(j=1;j<=t;j++) {
		int x,y;
		scanf("%d %d",&x,&y);
		b[0]=1;
		int temp=0;
		double t=1; // 다맞을확률
		double ans;
		for(i=1;i<=x;i++) {
			scanf("%lf",&a[i]);
			t*=a[i];
			if (a[i]!=1) {
				if (temp!=0) b[i]=b[temp]/(1-a[temp])*a[temp]*(1-a[i]);
				else b[i]=1-a[i];
				temp=i;
			}
			else b[i]=0;
			if (i==1 && a[i]!=1) b[i]=1-a[i];
		}
		ans=t*(y-x+1)+(1-t)*(2*y-x+2);
		if (ans>y+2) ans=y+2;
		double al=0; // al=안되는 경운데?
		for(i=1;i<x;i++) al+=b[i];
		for(i=1;i<=x;i++) { // backspace를 i번 누름
			double temp;
			temp=(1-al)*(2*i+y-x+1)+(al)*(2*y-x+2*i+2);
			if (temp<ans) ans=temp;
			al-=b[x-i];
		}
		printf("Case #%d: %f\n",j,ans);
	}
	return 0;
}
