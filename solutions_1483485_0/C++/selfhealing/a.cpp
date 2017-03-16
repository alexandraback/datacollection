#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char *tt =
 "yhesocvxduiglbkrztnwjpfmaq";
//abcdefghijklmnopzrstuvwxyq
//q z
char to[27];
char s[1005],t[1005];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,cas=0;scanf("%d",&T);
	gets(s);
	while(T--)
	{
		gets(s);
		int n = strlen(s);
		printf("Case #%d: ",++cas);
		for(int i = 0; i < n; i++)
		{
			if(s[i]==' ')printf(" ");
			else printf("%c",tt[s[i]-'a']);
		}
		puts("");
	}

	return 0;
}
