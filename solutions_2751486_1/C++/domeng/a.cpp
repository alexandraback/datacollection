#include <stdio.h>
#include <string.h>
#define NMAX 1000005
char str[NMAX];
int  cons[NMAX];
int  seen[NMAX];
int  hold;
bool isVowel(char x)
{
	return (x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		scanf("%s %d",str,&hold);
		int n = strlen(str);
		int last = 0;
		for (int i=n-1;i>=0;--i)
		{
			if (isVowel(str[i])) cons[i] = 0;
			else cons[i] = last+1;
			last = cons[i];
		}
		last = -1;
		for (int i=n-1;i>=0;--i)
		{
			if (cons[i]>=hold) last = i;
			seen[i] = last;
		}
		long long ret = 0;
		for (int i=0;i<n;++i)
		{
			if (seen[i]<0) break;
			int  j = seen[i] + hold - 1;
			ret += n - j;
		}
		printf("Case #%d: %lld\n",kase,ret);
	}
	return 0;
}

