#include<cstdio>

using namespace std;

int T,a[1000],b[1000];
int n,now,ans;
int I=0;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=0;i<n;++i)
			scanf("%d%d",&a[i],&b[i]);
		now=0;
		ans=0;
		while (now<n*2){
			bool update=false;
			for (int i=0;i<n;++i)
				if (b[i]!=-1 && b[i]<=now){
					++ans;
					++now;
					if (a[i]!=-1){
						++now;
						a[i]=-1;
					}
					b[i]=-1;
					update=true;
				}
			if (update) continue;
			int maxn=-1;
			for (int i=0;i<n;++i)
				if (a[i]!=-1 && a[i]<=now){
					if (maxn==-1 || (b[maxn]<b[i]))
						maxn=i;
				}
			if (maxn==-1) break;
			a[maxn]=-1;
			++ans;
			++now;
		}
		printf("Case #%d: ", ++I);
		if (now<2*n)
			puts("Too Bad");
		else printf("%d\n",ans);
	}
}
