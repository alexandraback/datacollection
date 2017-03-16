#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 1000+10;
int main()
{
	int T;
	int p=1;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,k;
		int ans = 0;
		scanf("%d%d%d",&a,&b,&k);
		for(int i = a-1; i >= 0; i--)
		{
			for(int j = b-1; j >= 0; j--)
			{
				int cur = i&j;
				if(cur < k)
					ans++;
			}
		}
		printf("Case #%d: %d\n",p++, ans);
	}
	return 0;
}