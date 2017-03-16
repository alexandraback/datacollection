#include<stdio.h>
#include<vector>

using namespace std;

vector <int> s[1000001];
int a[21];

int main()
{
	int t,p;
	int n;
	int i,j,k;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		for (i=0;i<=1000000;i++)
			s[i].clear();
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		int tt=1<<n;
		for (i=0;i<tt;i++)
		{
			int sum=0;
			for (j=0;j<n;j++)
				if (i&(1<<j)) sum=sum+a[j];
			if (sum<=1000000) s[sum].push_back(i);
		}
		for (i=0;i<=1000000;i++)
		{
			for (j=0;j<s[i].size();j++)
			{
				for (k=j+1;k<s[i].size();k++)
					if (s[i][j]+s[i][k]==(s[i][j]^s[i][k])) break;
				if (k<s[i].size()) break;
			}
			if (j<s[i].size()) break;
		}
		printf("Case #%d:\n",p);
		if (i>1000000) printf("Impossible\n");
		else
		{
			bool flag=true;
			int r;
			for (r=0;r<n;r++)
				if (s[i][j]&(1<<r)) 
				{
					if (flag) printf("%d",a[r]);
					else printf(" %d",a[r]);
					flag=false;
				}
			printf("\n");
			flag=true;
			for (r=0;r<n;r++)
				if (s[i][k]&(1<<r)) 
				{
					if (flag) printf("%d",a[r]);
					else printf(" %d",a[r]);
					flag=false;
				}
			printf("\n");
		}
	}
	return 0;
}


