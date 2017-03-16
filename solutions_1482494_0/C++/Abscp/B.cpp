#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010],b[1010],v[1010],n;
int main(){
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);
	int T;scanf("%d",&T);
	for(int t=1;t<=T;++t){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
		int now=0,ans=0,cnt=0;
		while(cnt<2*n){
			int f=0;
			for(int i=1;i<=n;++i)
				if(now>=b[i]){
					++ans;
					cnt+=2;
					f=1;now+=2;
					a[i]=b[i]=10000000;
				}
			if(f)continue;
			for(int i=1;i<=n;++i)
				if(now>=a[i]&&b[i]==10000000){
					++cnt;++ans;
					f=1;++now;
					a[i]=10000000;
				}
			if(f)continue;
			int tmp=0;
			for(int i=1;i<=n;++i)
				if(now>=a[i]){
					if(tmp==0||b[i]>=b[tmp])tmp=i;
					f=1;
				}
			if(!f)break;
			++cnt;++ans;
			++now;
			a[tmp]=b[tmp];b[tmp]=10000000;
		}
		if(cnt<n*2)printf("Case #%d: Too Bad\n",t);
		else printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
