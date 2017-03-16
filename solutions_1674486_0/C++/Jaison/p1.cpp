#include<iostream>
#include<vector>
using namespace std;

bool isDiamond(vector<vector<int> > adj, int x)
{
bool ans = false;
int sz = adj.size();
int *pathCount = new int[sz];
for(int i=0;i<sz;i++)
	pathCount[i] = 0;

pathCount[x] =1;
int iter =0;
vector<int> cl, pl;
cl.push_back(x);
while(iter < sz)
	{
	pl = cl;
	cl.clear();
	for(int i=0;i<pl.size();i++)
		{
		for(int j=0;j<adj[pl[i]].size();j++)
			{
			pathCount[adj[pl[i]][j]]++;
			cl.push_back(adj[pl[i]][j]);
			}
		}
	iter++;
	}

//cout<<" PC : ";
for(int i=0;i<sz;i++)
	{
	if(pathCount[i]>1)
		ans = true;
	//cout<<pathCount[i]<<" ";
	}
return ans;
}

int main()
{
int T,N;	
cin>>T;

for(int i=1;i<=T;i++)
	{
	cin>>N;
	vector<vector<int> > adjList;
	int sz, tmp;
	for(int j=0;j<N;j++)
		{
		cin>>sz;
		vector<int> tlist;
		for(int k =0;k<sz;k++)
			{
				cin>>tmp;
				tlist.push_back(tmp-1);
			}
		adjList.push_back(tlist);
		}
	bool diamond = false;
	for(int j=0;j<N;j++)
		diamond |= isDiamond(adjList, j);
	cout<<"Case #"<<i<<": ";
	if(diamond) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	}
return 0;
}
