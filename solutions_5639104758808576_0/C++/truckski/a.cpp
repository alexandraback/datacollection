#include<cstdio>
#include<cstdlib>

using namespace std;

char input[1024];
int p[1024];

int solve()
{
	int ret=0, n;
	scanf("%d %s",&n, input);
	for(int i = 0; i <= n; i++)
		p[i]=input[i]-'0';
	int acc=p[0];
	for(int i = 1; i <= n; i++)
	{
		if(acc<=i)
		{
			ret+=i-acc;
			acc=i;
		}
		acc+=p[i];
	}
	return ret;
}

int main()
{
	int ncases;
	scanf("%d",&ncases);
	for(int i = 1; i <= ncases; i++)
		printf("Case #%d: %d\n",i,solve());
	return 0;
}
