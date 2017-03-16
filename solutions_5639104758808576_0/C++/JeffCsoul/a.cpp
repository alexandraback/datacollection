#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
char s[1050];
int main() 
{
	freopen("aout.txt","w",stdout);
	int T,n;
	cin >> T;
	for (int TT= 1;TT<= T;TT++) 
	{
		int ans = 0,now = 0;
		scanf("%d%s",&n,s); 
		for (int i = 0;i <= n;i++) 
		{
			if (s[i]!='0')
			{
				if(now < i) 
				{
					ans += i - now;
					now = i;
				}
				now += s[i] - '0';
			}
		}
		printf("Case #%d: %d\n",TT,ans);
	}
	return 0;
}
