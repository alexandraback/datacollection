#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long LINT;


void main()
{
	int t;
	cin>>t;
	for(int ii=0; ii<t; ii++)
	{
		int n,m;
		cin>>n>>m;

		vector<string> v;

		int graph[50][50]={0,};
		for(int i=0; i<n; i++)
		{
			string s;
			cin>>s;
			v.push_back(s);
		}
		for(int i=0; i<m; i++)
		{
			int x,y;
			cin>>x>>y;
			graph[x-1][y-1]=graph[y-1][x-1]=1;
		}

		int st=min_element(v.begin(),v.end())-v.begin();

		vector<int> seq;
		seq.push_back(st);
		for(int i=0; i<n; i++)
		{
			if(i!=st)
				seq.push_back(i);
		}

		string minss="a";
		do
		{
			string ss;
			for(int i=0; i<seq.size(); i++)
				ss+=v[seq[i]];

			if(ss=="1095328444366422965150012")
				int gg=1;


			if(ss>minss)
				continue;

			vector<int> pp;
			pp.push_back(st);

			bool pos=true;
			for(int i=1; i<seq.size(); i++)
			{
				for(int j=pp.size()-1; j>=0; j--)
				{
					if(graph[pp[j]][seq[i]]==1)
					{
						pp.push_back(seq[i]);
						break;
					}
					else
						pp.pop_back();
				}
				if(pp.empty())
				{
					pos=false;
					break;
				}
			}
			if(!pos)
				continue;
			minss=ss;

		} while(next_permutation(seq.begin()+1,seq.end()));

		cout<<"Case #"<<ii+1<<": "<<minss<<endl;
	}
}
