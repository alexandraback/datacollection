#include <stdio.h>
int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);
	int T,n,s,p,x,ans;
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++) {
		ans=0;
		scanf("%d%d%d",&n,&s,&p);
		for (int i=0;i<n;i++) {
			scanf("%d",&x);
			if (x>3*(p-1)) ans++;
			else if (s>0&&(3*p-4>=0&&x>=3*p-4)) {
				ans++;
				s--;
			}
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
