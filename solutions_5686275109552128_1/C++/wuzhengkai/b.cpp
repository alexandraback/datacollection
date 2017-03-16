#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int tt;
int n;
int a[1010];

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d",&tt);

	for (int ii=1;ii<=tt;++ii) {
		scanf("%d",&n);
		int ans=0,maxi=0;
		for (int i=0;i<n;++i) {
			scanf("%d",&a[i]);
			maxi=max(maxi,a[i]);
		}

		ans=maxi;

		for (int i=1;i<=maxi;++i) {
			int cur=0;
			for (int j=0;j<n;++j)
				 cur+=(a[j]-1)/i;
			ans=min(ans,cur+i);
		}

		printf("Case #%d: %d\n",ii,ans);
	}

}

