#include <cstdio>
#include <cstring>

char mapping[255];

int main()
{
    freopen("rule.in", "r",stdin);
    for (char i='a';i<='z';++i)
    {
        char src;
        scanf(" %c %c", &src, &mapping[i]);
        printf("%c",src);
    }
    mapping[' ']=' ';
    freopen("a.in", "r", stdin);
    freopen("a.out", "w",stdout);
    int n;
    scanf("%d\n",&n);
    for (int i=0;i<n;++i)
    {
        char buf[1000];
        gets(buf);
        for (int j=0;j<strlen(buf);++j)
            buf[j]=mapping[buf[j]];
        printf("Case #%d: ",i+1);
        puts(buf);
    }
    return 0;
}
/*int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int n;
	scanf("%d\n",&n);
	for (int i=0;i<255;++i)
		mapping[i]= '?';
	for (int i = 0; i < n; ++i)
	{
		char src[100],des[100];
		gets(src);
		gets(des);
		for (int j=0;j<strlen(src);++j)
			mapping[src[j]]=des[j];
	}
	for (char i='a';i<='z';++i)
        if (mapping[i] == '?')
            printf("%c %c\n", i, mapping[i]);
	return 0;
}
*/
