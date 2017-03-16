#include<cstdio>
#include<cstring>
const char p[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char s[1005];
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int test,Case; scanf("%d",&test); gets(s);
	for (Case=1;Case<=test;Case++){
		gets(s); int l=strlen(s);
		printf("Case #%d: ",Case);
		for (int i=0;i<l;i++)
			if (s[i]<='z' && s[i]>='a') printf("%c",p[s[i]-97]);
			else printf("%c",s[i]);
		printf("\n");
		}
	return 0;
}
