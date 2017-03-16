#include<stdio.h>
#include<string.h>
int a[2000000];
char s[2000000];
bool fuyin(char t)
{
	if (t=='a'||t=='e'||t=='i'||t=='o'||t=='u')
		return false;
	else
		return true;
}
int main()
{
	int T,n;
	scanf("%d",&T);
	for(int TT=1;TT<=T;TT++)
	{
		scanf("%s %d",s,&n);
		int L=strlen(s);
		int b=-1;
		int count=0;
		long long ans=0;
		for(int i=0;i<L;i++)
		{
			if (fuyin(s[i]))
			{
				count++;
			}
			else
			{
				count=0;
			}
			if (count>=n)
			{
				b=i-n+1;
			}
			ans+=b+1;
		}
		printf("Case #%d: %lld\n",TT,ans);
	}
}