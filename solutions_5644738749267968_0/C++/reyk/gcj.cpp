#include<stdio.h>
#include<algorithm>
using namespace std;
double a[1000];
double b[1000];
int main(){
	int dn;
	scanf("%d",&dn);
	for(int di=0;di<dn;di++){
		int n,i;
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%lf",&a[i]);
		for(i=0;i<n;i++)scanf("%lf",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		int p=0;
		int ans1=0,ans2=0;
		for(i=0;i<n;i++){
			while(p<n&&a[i]>b[p])p++;
			if(p<n)ans1++;
			p++;
		}
		p=0;
		for(i=0;i<n;i++){
			while(p<n&&a[p]<b[i])p++;
			if(p<n)ans2++;
			p++;
		}
		printf("Case #%d: %d %d\n",di+1,ans2,n-ans1);
	}
	return 0;
}
