#include <iostream>
#include <vector>
using namespace std;

	
vector<int> a[1005];
int b[1005];

int dep(int i)
{
//	printf("dep:%d\n",i);
	int j;
	for(j=0;j<a[i].size();j++)
	{
	//	printf("a[%d][%d]: %d\n",i,j,a[i][j]);
		if(b[a[i][j]]==0)
		{
			b[a[i][j]]=1;
			int mm=dep(a[i][j]);
			if(mm==1)
				return 1;
		}
		else
		{
			return 1;
		}


	}
	return 0;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	int it,i,j,n;

	scanf("%d",&t);
	for(it=1;it<=t;it++)
	{

		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			int temp;
			scanf("%d",&temp);
			for(j=0;j<temp;j++)
			{
				int m;
				scanf("%d",&m);
				a[i].push_back(m);
			}
		}
		bool flag=false;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=n;j++)
				b[j]=0;
			int mm=dep(i);
			if(mm==1)
			{
				flag=true;
			   break;
			}
		}
		if(flag==true)
			printf("Case #%d: Yes\n",it);
		else
			printf("Case #%d: No\n",it);

		for(i=1;i<=n;i++)
		{
			a[i].clear();
		}

	}
	return 0;
}