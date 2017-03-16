#include <cstdio>
#include <cstring>

using namespace std;

char a[110];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;scanf("%d",&test);
	for (int T=1;T<=test;T++)
	{
		scanf("%s",a);int n=strlen(a);
		a[n]='+';int ans=0;
		for (int i=0;i<n;i++) if (a[i]!=a[i+1]) ans++;
		printf("Case #%d: %d\n",T,ans);
	}
	return 0;
}

