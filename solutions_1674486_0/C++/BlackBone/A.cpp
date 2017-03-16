#include<stdio.h>
#include<stack>

using namespace std;

short map1[1005][1005];
short map2[1005][1005];

int main()
{
	int t,n,l,i,j,k,temp,check;
//	freopen("input.txt","r",stdin);
	freopen("A-small-attempt3.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	stack<int> x,y;
	for(i=0;i<t;i++)//test case
	{
		check=0;

		scanf("%d",&n);//num of class

		for(j=0;j<n;j++) //initializing
			for(k=0;k<n;k++)
			{
				map1[j][k]=0;
			}

		for(j=0;j<n;j++)
		{
			scanf("%d",&l);//num of link
			for(k=0;k<l;k++)
			{
				scanf("%d",&temp);
				map1[temp-1][j]++;
			}
			if(l==0)
			{
				x.push(j);
				y.push(1);
			}
		}

		while(!x.empty())
		{
			temp=x.top();
			if(y.top())
				for(j=0;j<n;j++) //initializing
					for(k=0;k<n;k++)
						(j==k)? map2[j][k]=1 : map2[j][k]=0;
			x.pop();
			y.pop();

			for(j=0;j<n;j++)
				if(map1[temp][j])
				{
					x.push(j);
					y.push(0);
					for(k=0;k<n;k++)
						if((map2[j][k]+=map2[temp][k])>=2)
							check=1;
				}
		}

		if(check)
			printf("Case #%d: Yes\n",i+1);
		else
			printf("Case #%d: No\n",i+1);
	}
	return 0;
}