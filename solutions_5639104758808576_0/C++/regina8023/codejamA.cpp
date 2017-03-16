#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int T,sm;
char s[1005];
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
    scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%d",&sm);
		scanf("%s",s);
		int ans=0,now=0;
		for (int i=1;i<=sm;i++)
		{
			now=now+s[i-1]-'0';
			if (now<i) ans=ans+i-now,now=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
