#include <iostream>
#include <vector>
using namespace std;

int t,i,j,k,n,m,x;
vector<vector<int> > graph;
vector<bool> wasHere;
bool czy;
bool troll;

void cdi(int st) // contains diamond inheritance
{
	if(wasHere[st]) {troll=true;}
	wasHere[st]=true;
	int size=graph[st].size();
	for(int h=0;h<size;++h)
	{
		cdi(graph[st][h]);
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin>>t;
	for(k=0;k<t;++k)
	{
		cin>>n;
		for(j=0;j<n;++j)
		{
			cin>>m;
			graph.push_back(vector<int>());
			wasHere.push_back(false);
			for(i=0;i<m;++i)
			{
				cin>>x;
				graph[j].push_back(x-1);
			}
		}
		czy=false;
		for(j=0;j<n;++j)
		{
			troll=false;
			for(i=0;i<n;++i)
			{
				wasHere[i]=false;
			}
			cdi(j);
			if(troll) {czy=true;}
		}
		cout<<"Case #"<<k+1<<": ";
		if(czy) {cout<<"Yes";} else {cout<<"No";}
		cout<<endl;
		for(j=0;j<n;++j)
		{
			graph[j].clear();
		}
		graph.clear();
	}
	return 0;
}
