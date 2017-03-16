#include<cstdio>
#include<cstring>
using namespace std;
int T,t;
char c, g[102], flag[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
	freopen("AIn.txt","r",stdin);
	freopen("AOut.txt","w",stdout);
	scanf("%d\n",&T);
	for (;T>0;T--)
	{
		//scanf("%s\n",g);
		printf("Case #%d: ",++t);
		//for (char *i=g;*i!='\0';i++)
		//	if (*i==' ') printf(" "); else puts(&flag[*i-97]);
		//printf("\n");
		while (true)
		{
			c=getchar();
			if (c==-1) break;
			if (c==' ' || c=='\n') putchar(c); else putchar(flag[c-97]);
			if (c=='\n') break;
		}
	}
	return 0;
}
