#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn	=	1005;

int n,level[maxn],a[maxn],b[maxn];

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B.out","w",stdout);
	
	int T,test=1;
	for (scanf("%d",&T);test<=T;++test){
		scanf("%d",&n);
		for (int i=0;i<n;++i){
			scanf("%d%d",&a[i],&b[i]);
			level[i]=0;
		}
		int star=0,cnt=0,ans=0;
		while (cnt<n){
			bool change=false;
			for (int i=0;i<n;++i)
			if (level[i]<2 && star>=b[i]){
				++cnt;
				star+=2-level[i];
				level[i]=2;
				change=true;
				++ans;
			}
			if (change) continue;
			
			int best=-1;
			for (int i=0;i<n;++i)
			if (level[i]==0 && star>=a[i]){
				if (best==-1 || b[i]>b[best]){
					best=i;
				}
			}
			if (best==-1) break;
			level[best]=1;
			++star;
			++ans;
		}
		if (cnt<n) printf("Case #%d: Too Bad\n",test);
		else printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}
