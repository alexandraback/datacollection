#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
using namespace std;
const int maxn=15;
char c[maxn];
map<int,bool> hash;
int i,j,n,m,ii,tests;

int length(int x)
{
	int len=0;
	while (x)
	{
		x/=10;
		len++;
	}
	return len;
}

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&tests);
	for (ii=1;ii<=tests;ii++)
	{
		int ans=0;
		scanf("%d%d",&n,&m);
		for (i=n;i<=m;i++)
		{
			int len=length(i),mul=1,s=i;
			for (j=1;j<len;j++) 
				mul*=10;
			//printf("%d %d\n",i,mul);
			hash.clear();
			for (j=1;j<len;j++)
			{
				s=(s%10)*mul+s/10;
				if (s>=n && s<=m && s>i && hash[s]==false)
				{
					hash[s]=true;
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n",ii,ans);
	}
	return 0;
}
