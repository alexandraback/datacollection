#include <cstdio>
#include <algorithm>
using namespace std;

const int N=1005;

int m,a[N];

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen(".out","w",stdout);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		scanf("%d",&m);
		for(int i=1;i<N;i++) a[i]=0;
		while(m--){
			int n; scanf("%d",&n);
			for(int i=1;i<N;i++) a[i]+=n/i+bool(n%i)-1;
		}
		int ans=0x7fffffff;
		for(int i=1;i<N;i++) ans=min(ans,i+a[i]);
		printf("Case #%d: %d\n",Case,ans);
	}
	scanf("\n");
}
