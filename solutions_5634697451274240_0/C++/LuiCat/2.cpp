#include <cstdio>
#include <cstring>

char s[200];

int main()
{
	int t;
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%s",s);
		int l=strlen(s),p=0,res=0;
		if(s[p]=='-')
		{
			while(p<l&&s[p]=='-')++p;
			++res;
		}
		while(p<l)
		{
			while(p<l&&s[p]!='-')++p;
			if(p==l)break;
			while(p<l&&s[p]=='-')++p;
			res+=2;
		}
		printf("Case #%d: %d\n",i,res);
	}
	return 0;
}


