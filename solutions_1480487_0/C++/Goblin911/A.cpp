#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int i,n,a[1000],m,x;
double ans[1000];
bool v[1000],f;
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t,T;cin>>T;
	for (t=1;t<=T;t++){
		cin>>n;a[0]=0;m=n;
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			a[0]+=a[i];v[i]=0;
		}f=1;
		while (f){
			ans[0]=double(a[0]*2)/m;f=0;
			for (i=1;i<=n;i++) if (a[i]>ans[0] && !v[i]) {
				ans[i]=0;
				v[i]=1;f=1;m--;
			}
		}
		for (i=1,x=0;i<=n;i++) if (!v[i]) x+=a[i];
		ans[0]=double(a[0]+x)/m; // cout<<ans[0]<<" : ";
		//for (i=1;i<=n;i++) if 
		
		printf("Case #%d: ",t);
		for (i=1;i<=n;i++) if (!v[i]) ans[i]=double(ans[0]-a[i])/a[0]*100;
		//printf("%lf\n",double(ans[0]-a[i])/a[0]*100);
		for (int i=1;i<=n;i++) printf("%lf ",ans[i]);
		cout<<endl;
	}
}