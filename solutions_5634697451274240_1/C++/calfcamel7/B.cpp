#include <stdio.h>
#include <string.h>

char str[1000];
int getans()
{
	scanf("%s",str);
	int n = strlen(str);
	int ret = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if(str[i] == '-')
		{
			ret++;
			for(int j = 0; j <= i; j++)
				if(str[j] == '-')
					str[j] = '+';
				else 
					str[j] = '-';
		}
	}
	return ret;
}
int main()
{
	int _T;
	scanf("%d",&_T);
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		printf("Case #%d: %d\n", CAS, getans());
	}
}