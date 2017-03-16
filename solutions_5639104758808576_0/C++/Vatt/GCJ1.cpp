#include <stdio.h>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
	int t,n,now,ans;
	char in[1005];
	scanf("%d",&t);
	for(int r=1;r<=t;r++) {
		scanf("%d",&n);
		scanf("%s",in);
		now = 0;
		ans = 0;
		for(int i=0;i<=n;i++) {
			//printf("%d %d\n",now,i);
			if(now<i) {
				ans+=i-now;
				now = i;
			}
			now+=in[i]-'0';
		}
		printf("Case #%d: %d\n",r,ans);
	}
	return 0;
}
