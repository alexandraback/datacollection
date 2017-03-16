#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define maxn
#define maxm
using namespace std;
int cnt[2000];
char s[2000];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int tt,cot=1;
	scanf("%d",&tt);
	while(tt--)
	{
		memset(cnt,0,sizeof(cnt));
		int mx;
		scanf("%d",&mx);
		scanf("%s",s);
		for(int i=0;i<=mx;i++)
			cnt[i]=s[i]-'0';
		for(int i=1;i<=mx;i++)
			cnt[i]+=cnt[i-1];
		int ans=0;
		for(int i=1;i<=mx;i++)
		{
			if(cnt[i-1]<i)
				ans=max(ans,i-cnt[i-1]);
		}
		printf("Case #%d: %d\n",cot++,ans);
	}
	//system("pause");
	return 0;
}