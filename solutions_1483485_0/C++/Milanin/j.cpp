#include <stdio.h>
#define N 1010
int p[26]={24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 19, 13, 22, 9, 15, 5, 12, 0, 16};
char a[N];
int main()
{
	int i, t, ts;
	for(gets(a), sscanf(a, "%d", &ts), t=1; t<=ts; printf("Case #%d: %s\n", t, a), t++)
		for(gets(a), i=0; a[i]; i++)
			if(a[i]!=' ') a[i]='a'+p[a[i]-'a'];
	return 0;
}