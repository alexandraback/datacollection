#include <cstdio>
#include <cstring>

const char a[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char ch[500];
int T,len,CASE;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);	
	scanf("%d\n",&T);
	while (T--){
		printf("Case #%d: ",++CASE);
		gets(ch);
		len=strlen(ch);
		for (int i=0;i<len;i++)  if (ch[i]==' ')printf(" ");else printf("%c",a[ch[i]-'a']);
		printf("\n");
	}
}
