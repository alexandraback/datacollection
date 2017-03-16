#include <cstdio>
#include <cstring>

char ch[27]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

void work()
{
	int T;
	int cas;
	int i;
	char s[256];
	
	scanf("%d",&T);
	gets(s);
	for (cas=1;cas<=T;cas++)
	{
		gets(s);
		for (i=0;s[i]!='\0';i++)
		{
			if (s[i]!=' ')
			{
				s[i] = ch[s[i]-'a'];
			}
		}
		printf("Case #%d: %s\n",cas,s);
	
	}
}

int main()
{
	//int i;
	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	
	
	work();

	
	return 0;
}
