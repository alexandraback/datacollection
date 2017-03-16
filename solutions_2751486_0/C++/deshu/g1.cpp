#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	freopen("A-small-attempt.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int x=1;x<=t;x++)
	{
		int n;
		char a[1001];
		int con=0;
		long long int ans=0;
		int index = -1;
		scanf("%s%d",a,&n);
		for(int i=0;a[i];i++)
		{
			if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u')
			{
				con=0;
			}
			else
			{
				con++;
				if(con>=n)
				{
					index = i;
				}
			}
			if(index>=0)ans += index-n+2;
		}
		printf("Case #%d: %lld\n",x,ans);
	}
	return 0;
}