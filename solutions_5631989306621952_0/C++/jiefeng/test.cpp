#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int i = 0;i<tc;i++)
	{
		char str[1005];
		scanf("%s",str);
		int len = strlen(str);
		char build[2005]={0};
		int start = 1003, end = 1004;
		build[1003] = str[0];
		for(int j = 1;j<len;j++)
		{	
			if(str[j] >= build[start])
			{
				start--;
				build[start] = str[j];
			}
			else
			{
				build[end] = str[j];
				end++;
			}
		}
		printf("Case #%d: %s\n",i+1,build+start);
	}
}
