//shjj-aa

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

char s[1003],ans[3003];
int n,L,R;

int main()
{
	freopen("A1.in","r",stdin);
	freopen("A1.out","w",stdout);
	int T,Tt=0;scanf("%d",&T);
	for (;T--;)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		L=R=1000;
		ans[1000]=s[1];
		for (int i=2;i<=n;i++)
			if (s[i]>=ans[L]) ans[--L]=s[i];
				else ans[++R]=s[i];
		printf("Case #%d: ",++Tt);
		for (int i=L;i<=R;i++) printf("%c",ans[i]);
		puts("");
	}
}
