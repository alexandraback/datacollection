#include<cstdio>
using namespace std;
char s[10000000];
bool b[10000000];

int main()
{
int t;
scanf("%d", &t);
for (int tt = 1; tt<=t; tt++)
{
	int n, i, j;
	scanf("%s", s);
	scanf("%d", &n);
	
	int lv = -1;
	for (i=0; s[i]; i++)
	{
		switch(s[i])
		{
			case 'a': case 'e': case 'i': case 'o': case 'u':
				lv = i;
			default:
				if(i-lv >= n) b[i] = 1;
				else b[i] = 0;
		}
	}
	
	/*for (i=0; s[i]; i++)
		printf("%d", b[i]);
	printf("\n");
	*/
	long long wyn = 0;
	int lg;
	for (i=0; s[i]; i++)
		if(b[i]) break;
	for (   ; s[i]; i++)
	{
		if(b[i]) lg = i;
		wyn += lg-n+2;
	}
	printf("Case #%d: %lld\n", tt, wyn);
	
	
	
			
}
return 0;
}
