#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int viz[1007],found=0;
int path[1007][1007],noduri;
vector<int> v[1007];

void dfs1(int nod)
{
	int sz=v[nod].size();

	viz[nod]=1;
	for(int i=0;i<sz;++i)
	{
			int node=v[nod][i];
			if(!path[nod][node])
				path[nod][node]=1;
			else
				found=1;
			if(!viz[node])
				dfs1(node);
			for(int j=0;j<noduri;++j)
			{
				if(path[node][j])
				{
					if(path[nod][j])
						found=1;
					else
						path[nod][j]=1;
				}
			}
	}
}

void dfs2()
{
	for(int i=0;i<noduri;++i)
	{
		if(!viz[i])
			dfs1(i);
	}
	for(int i=0;i<noduri;++i)
		v[i].clear();
}

int main()
{
	FILE *f=fopen("A.in","r");
	FILE *g=fopen("A.out","w");

	int t;

	fscanf(f,"%i",&t);
	for(int i=0;i<t;++i)
	{
		memset(viz,0,sizeof(viz));
		memset(path,0,sizeof(path));
		fscanf(f,"%i",&noduri);
		found=0;
		for(int j=0;j<noduri;++j)
		{
			int m;
			fscanf(f,"%i",&m);
			for(int k=0;k<m;++k)
			{
				int nod;
				fscanf(f,"%i",&nod);
				v[j].push_back(nod-1);
			}
		}
		dfs2();
		if(found)
			fprintf(g,"Case #%i: Yes\n",i+1);
		else
			fprintf(g,"Case #%i: No\n",i+1);
	}
	fclose(f);
	fclose(g);
}
