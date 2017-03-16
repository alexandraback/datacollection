
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;


int main()
{
	int T,N;

	scanf("%d\n", &T);
	int C=0;
	while(T--)
	{	C++;

		int v[1001],p[1001];
		int l[1001];
		queue<int> bfs;
		vector<int> edge[1001];


		scanf("%d\n", &N);

		for(int i=1;i<=N;i++)
		{
			int e,node;
			scanf("%d",&e);
			for(int j=1;j<=e;j++)
			{	
				scanf("%d",&node);
				edge[i].push_back(node);
			}
		}

		// cout<<"Adacency List"<<endl;
		// for(int i=1;i<=N;i++)
		// {	cout<<"Vertex "<<i<<endl;
		//  	for(int j=0;j<edge[i].size();j++)
		// 	 cout<<edge[i][j]<<"  ";
		// 	 cout<<endl;	 
		// }

		int startbfs;
		bool result=false;
		for(startbfs=1;startbfs<=N;startbfs++)
		{	
			for(int i=1;i<=N;i++)
			{	
				v[i]=0;
				l[i]=0;
			}

			v[startbfs]=1;
			l[startbfs]=1;
			bfs.push(startbfs);
			while(!bfs.empty())
			{	
				int now=bfs.front();
				//cout<<"Processing "<<now<<endl;	
				bfs.pop();
				for(int j=0;j<edge[now].size();j++)
				{
					if(v[edge[now][j]]==0)
					{
					 	bfs.push(edge[now][j]);
						//cout<<"Inserting "<<edge[now][j]<<" into Q"<<endl;
						v[edge[now][j]]=1;
						l[edge[now][j]]=l[now]+1;
						//cout<<"Level of "<<edge[now][j]<<" is "<<l[edge[now][j]]<<endl;
						p[edge[now][j]]=now;
						//cout<<"Parent of "<<edge[now][j]<<" is "<<p[edge[now][j]]<<endl;
					 
					}
					else
					{
						if(l[edge[now][j]]!=1)
							result=true;

					}
				}
			}
			if(result==true)
				break;

			// for(int i=1;i<=N;i++)
			// cout<<v[i]<<" ";
			// cout<<endl;
			// cout<<"l"<<endl;
			// for(int i=1;i<=N;i++)
			// cout<<l[i]<<" ";
			// cout<<endl;
			// cout<<"Parent"<<endl;
			// for(int i=1;i<=N;i++)
			// cout<<p[i]<<" ";
			// cout<<endl;
		}
		if(result==true)
			cout<<"Case #"<<C<<": "<<"Yes"<<endl;
		else
			cout<<"Case #"<<C<<": "<<"No"<<endl;
	}
	return 0;
}

