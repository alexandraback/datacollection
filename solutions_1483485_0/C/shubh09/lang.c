#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)

typedef long long int ll;

char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

char line[100];

int main()
{
	int t;
	s(t);
	int i,j;
	gets(line);
	FOR(i,0,t)
	{
		gets(line);
		//printf("%s\n",line);
		printf("Case #%d: ",i+1);
		int l=strlen(line);
		FOR(j,0,l)
		{
			if (line[j]==' ') printf(" ");
			else
			{
				if (line[j]=='\n') printf("\n");
				else
				{
					int t1 = (int)line[j]-97;
					printf("%c",map[t1]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
