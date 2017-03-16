#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

const char in_name[]="A-large(2).in";
const char out_name[]="out.txt";

ifstream c_in(in_name);
ofstream c_out(out_name);

int main()
{
	int n;
	int m;
	vector<vector<int> > G;
	vector<int> upper;
	bool found;

	int t;
	c_in>>t;
	for(int test=1;test<=t;test++)
	{
		c_in>>n;
		upper.assign(n,1);
		G.assign(n,vector<int>());
		for(int i=0;i<n;i++)
		{
			c_in>>m;
			G[i].assign(m,0);
			for(int j=0;j<m;j++)
			{
				c_in>>G[i][j];
				G[i][j]--;
				upper[G[i][j]]=0;
			}
		}

		found=false;
		for(int i=0;i<n && !found;i++)
		{
			if(upper[i])
			{
				queue<int> Q;
				vector<int> used(n,0);

				Q.push(i);
				used[i]=1;
				int cur;
				while(Q.size()!=0 && !found)
				{
					cur=Q.front();
					Q.pop();
					for(int v=0;v<G[cur].size();v++)
					{
						if(used[G[cur][v]])
						{
							found=true;
							break;
						}
						Q.push(G[cur][v]);
						used[G[cur][v]]=1;
					}
				}

				if(found)
					break;
			}
		}
		c_out<<"Case #"<<test<<": "<<((found)?("Yes"):("No"))<<"\n";
	}

	return 0;
}