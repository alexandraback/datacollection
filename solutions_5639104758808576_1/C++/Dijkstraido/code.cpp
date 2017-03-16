#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T,n,cur,ans,ntest=1;
	char s[1005];
	scanf("%d\n",&T);
	while(T--)
	{
		scanf("%d %s\n",&n,s); 
		cur = ans = 0;
		for(int i = 0; i < n + 1; i++)
		{
			if(cur < i)
			{
				ans += i - cur;
				cur = i;
			}
			cur += s[i] - '0';
		}
		printf("Case #%d: %d\n",ntest++,ans);
	}
    return 0;
}