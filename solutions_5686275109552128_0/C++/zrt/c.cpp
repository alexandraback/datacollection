#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tt;
int a[1005];
int kase;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&tt);
	while(tt--){
		int mx=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
		int ans=0x7fffffff;
		for(int i=1;i<=mx;i++){
			int c=0;
			for(int j=1;j<=n;j++){
				if(a[j]>i){
					c+=(a[j]-1)/i;
				}
			}
			ans=min(ans,c+i);
		}
		printf("Case #%d: %d\n",++kase,ans);
	}
	
	return 0;
}
