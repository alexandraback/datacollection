#include<map>
#include<stdio.h>
#include<vector>
#include<queue>
#include<list>
using namespace std;
void print(vector<list<int> >gra)
{
	for(int u=0;u<gra.size();u++)
	{
		for(list<int>::iterator i=gra[u].begin();i!=gra[u].end();i++)
			printf("%d ",*i);
		printf("\n");
	}
}
int bfs(vector<list<int> >gra,int u)
{
	//print(gra);
	queue<int>Q;
	Q.push(u);
	int N=gra.size();
	vector<int>col(N);
	col[u]=1;
	while(!(Q.empty()))
	{
		int v=Q.front();
		Q.pop();
		
		for(list<int>::iterator i=gra[v].begin();i!=gra[v].end();i++)
		{
			int fin=(*i);
			if(col[fin]==1)return 1;
			Q.push(fin);
			col[fin]=1;
		}
		
	}
	
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int itr=1;itr<=t;itr++)
	{
		int N,M;
		scanf("%d",&N);
		vector<list<int> >gra(N);
		
		for(int i=0;i<N;i++)
		{

			scanf("%d",&M);			
			for(int j=0;j<M;j++)
			{
				int t;
				scanf("%d",&t);
				t=t-1;
				gra[i].push_back(t);
			}
		}
		int flag=0;
		for(int i=0;i<N;i++)
		{
			if(bfs(gra,i)==1)
			{
				flag=1;
				break;
			}
		}
		printf("Case #%d: %s\n",itr,(flag==0)?"No":"Yes");
	}
	return  0;
}
