#include <stdio.h>
#include <string.h>

char s[1000005];
__int64 f[1000005];
__int64 p[1000005];

int ok(char c)
{
	if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return 0;
	else return 1;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("l.out", "w", stdout);

	int t, cas;
	__int64 n, l;
	__int64 res;
	__int64 com;

	scanf("%d\n", &t);
	for (cas=1; cas<=t; cas++)
	{
		scanf("%s %I64d\n", s, &n);
		l=strlen(s);
		memset(f, 0, sizeof(f));
		int j=0;
		for (int i=0; i<l; i++)
		{
			if (ok(s[i])) f[j++]=i;
		}
		res=0;
		com=0;
		for (int i=n-1; i<j; i++)
		{
			if (f[i]-f[i-n+1]==n-1) 
			{
				p[com++]=f[i];
			}
		}
		int tmp=0;
		for (int i=0; i<com; i++)
		{
			res+=(p[i]-n+2-tmp)*(l-p[i]);
			tmp=p[i]-n+2;
		}
		
		printf("Case #%d: %I64d\n", cas, res);
	}
	return 0;
}

