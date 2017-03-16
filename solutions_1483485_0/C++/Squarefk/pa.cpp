#include <cstdio>

using namespace std;

const char change[26]={'y','h','e','s','o','c','v','x','d','u',
	'i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int n;

void work(int number)
{
	printf("Case #%d: ",number);
	while (1)
	{
		char c=getchar();
		if (c=='\n'){printf("\n");return;}
		if (((int)'a'<=(int)c)&&((int)c<=(int)'z'))
			printf("%c",change[(int)c-(int)'a']);
		else printf("%c",c);
	}
}

int main()
{
	scanf("%d\n",&n);
	for (int i=1;i<=n;++i) work(i);
	return 0;
}
