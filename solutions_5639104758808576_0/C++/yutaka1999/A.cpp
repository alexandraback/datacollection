#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1005

using namespace std;

char str[SIZE];

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",&str);
		int now=0,ret=0;
		for(int i=0;i<=n;i++)
		{
			int c=str[i]-'0';
			if(c>0&&now<i)
			{
				ret+=i-now;
				now=i;
			}
			now+=c;
		}
		printf("Case #%d: %d\n",t,ret);
	}
	return 0;
}
