#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int Maxn=110;

char f[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char st[Maxn];
int n,Test;

int main()
{
	//freopen("x.in","r",stdin);
	//freopen("a.out","w",stdout);
	
	scanf("%d\n",&Test);
	for (int ii=1;ii<=Test;++ii)
	{
		gets(st);
		n=strlen(st);
		for (int i=0;i<n;++i)
			if (st[i]!=' ')
				st[i]=f[st[i]-'a'];
		printf("Case #%d: %s\n",ii,st);
	}
	
	return 0;
}