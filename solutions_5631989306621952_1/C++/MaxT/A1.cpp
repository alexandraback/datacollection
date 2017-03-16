#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
int ans[3002];
char s[1002];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	
	scanf("%d",&T);
	for (int k=1;k<=T;k++)
	{
		scanf("%s",&s);
		int len=strlen(s);
		{
			int head=1000, tail=1000;
			ans[head]=s[0];
			for (int i=1;i<len;i++)
			if (s[i]>=ans[head])
			{
				head--;
				ans[head]=s[i];
			}
			else
			{
				tail++;
				ans[tail]=s[i];
			}
			printf("Case #%d: ",k);
			for (int i=head;i<=tail;i++)
				printf("%c",ans[i]);
			printf("\n");
			for (int i=head;i<=tail;i++)
				ans[i]=0;
		}
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}






