#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tc,a,n,m[101];
int dp(int s,int p, int cnt){
	if (p>n-1) return cnt;
	while (s>m[p]){
		s+=m[p];
		p++;
	}
	if (p>n-1) return cnt;
	if (s==1) return (n-p+cnt);
	return min(dp(2*s-1,p,cnt+1),n-p+cnt);
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&tc);
	for (int tcx=1; tcx<=tc; tcx++){
		memset(m,0,sizeof m);
		scanf("%d%d",&a,&n);
		for (int i=0; i<n; i++){
			scanf("%d",&m[i]);
		}
		sort(m,m+n);
		int ans=dp(a,0,0);
		printf("Case #%d: %d\n",tcx,ans);
	}
}