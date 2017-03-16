#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int t,cas = 0;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		int cnt = 0;
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				if((i&j)<k)
					cnt++;
			}
		}
		printf("Case #%d: %d\n",++cas,cnt);
	}
}
