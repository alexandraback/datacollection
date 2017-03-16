#include<iostream>
#include<cstdio>
using namespace std;
int T;
int n,s,p,t[111];

void init()
{
	scanf("%d %d %d",&n,&s,&p);
	for (int i=1;i<=n;i++)	scanf("%d",&t[i]);
}

bool better(int x)
{
	return (x>1) && (  ((x%3==0)&&(x/3+1==p)) or ((x%3==2)&&(x/3+2==p)) );
}

int work()
{
	int ans=0;
	for (int i=1;i<=n;i++)
		if (t[i]/3>=p) ans++;
			else if ( (t[i]%3) && (t[i]/3+1>=p) )ans++;
	
	for (int i=1;i<=n;i++)
		if (s>0 && better(t[i]))
		{
			ans++;
			s--;
		}
	return ans;
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		init();
		printf("Case #%d: %d\n",t,work());
	}
	fclose(stdin);	fclose(stdout);
	return 0;
}
		
	
	