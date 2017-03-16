#include<cstdio>
#define N 1010
int a[N];
using namespace std;
int main(){
	int T,cs,n,mx,i,j,mv,ans;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++){
		scanf("%d",&n);
		mx=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]>mx) mx=a[i];
		}
		ans=mx;
		for(i=1;i<mx;i++){
			mv=0;
			for(j=0;j<n;j++){
				mv+=(a[j]-1)/i;
			}
			if(i+mv<ans){
				ans=i+mv;
			}
		}
		printf("Case #%d: %d\n",cs,ans);
	}
	return 0;
}