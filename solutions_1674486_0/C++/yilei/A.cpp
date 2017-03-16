#include <iostream>
#include <stdio.h>
#include <list>
#include <queue>
using namespace std;

list<int> father[1005];
int numf[1005];
int nums[1005];
bool visit[1005];

int main()
{
	int t;
	int n;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		for (int j=0;j<1005;j++)
			father[j].clear();
		cin>>n;
		for (int j=1;j<=n;j++)
		{
			cin>>numf[j];
			for (int k=1;k<=numf[j];k++)
			{
				int tmp;
				cin>>tmp;
				father[j].push_back(tmp);
				nums[tmp]++;
			}
		}
		bool flag=false;
		for (int j=1;j<=n;j++)
		{
			//if (nums[j]==0)
			{
				memset(visit,0,sizeof(visit));
				visit[j]=true;
				queue<int> path;
				path.push(j);
				bool f=false;
				while(!path.empty())
				{
					int cur=path.front();
					path.pop();
					list<int>::iterator ls;
					for (ls=father[cur].begin();ls!=father[cur].end();ls++)
					{
						int c=*ls;
						if (visit[c])
						{
							f=true;
							flag=true;
							//cout<<j<<' '<<c<<endl;
							break;
						}
						path.push(c);
						visit[c]=true;
					}
					if (f)
						break;
				}
				if (flag)
					break;
			}
		}

		printf("Case #%d: ",i);
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
		//cout<<"Case #"<<i<<": "<<mini<<endl;
	}
	return 0;
}
