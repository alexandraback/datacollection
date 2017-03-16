#include <stdio.h>
#include <string.h>
#include <math.h>

int A,B;

bool isRe(int n)
{
	static char s[20];
	snprintf(s,sizeof(s),"%d",n);
	int len = strlen(s);
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-1-i]) return false;
	}
	return true;
}

bool isR(int n)
{
	int sqrN = (int)(sqrt(n+0.0) + 1e-7);
	if( sqrN * sqrN != n ) return false;
	return isRe(sqrN) && isRe(n);
}

int main()
{
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&A,&B);
		int cnt=0;
		for(int i=A;i<=B;i++)
		{
			if(isR(i)) cnt++;
		}
		printf("Case #%d: %d\n",ca++,cnt);
	}
	return 0;
}

