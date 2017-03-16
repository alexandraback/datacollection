#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<fstream>

using namespace std;

vector<vector<int> > pth;
vector<vector<int> > p;
int vex;

void existPath()
{
	int i,j,t;
	vector<int> v;

	for(i=1;i<=vex;++i)
	{
		v.push_back(i);

		while(v.size()>0)
		{
			t=v[0];

			for(j=1;j<=vex;++j)
			{
				if(pth[t][j])
				{
					p[i][j]=1;
					v.push_back(j);
				}
			}

			v.erase(v.begin());
		}
	}
}

void main()
{
	int i,j,t,num,temp,k,count;
	string ret;
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small.txt");
	
	fin>>num;

	for(i=1;i<=num;++i)
	{
		fin>>vex;
		pth.clear();
		p.clear();

		for(j=1;j<=vex+5;++j)
		{
			vector<int> vv(vex+5,0);
			pth.push_back(vv);
			p.push_back(vv);
		}

		for(j=1;j<=vex;++j)
		{
			fin>>k;

			for(t=1;t<=k;++t)
			{
				fin>>temp;
				pth[j][temp]=1;
			}
		}

		existPath();
		ret="No";

/*		for(j=1;j<=vex;++j)
		{
			for(k=1;k<=vex;++k)
				cout<<pth[j][k]<<" ";
			cout<<endl;
		}

		cout<<endl<<endl;
		for(j=1;j<=vex;++j)
		{
			for(k=1;k<=vex;++k)
				cout<<p[j][k]<<" ";
			cout<<endl;
		}*/

		for(j=1;j<=vex;++j)
		{
			for(k=1;k<=vex;++k)
			{
				count=0;

				for(t=1;t<=vex;++t)
					if(pth[j][t])
						++count;
			
				if(count<=1)
					continue;

				count=0;
				for(t=1;t<=vex;++t)
				{
					if(pth[j][t] && (p[t][k] || t==k))
						++count;

					if(count>=2)
					{
						ret="Yes";
						goto l;
					}
				}
			}
		}

l:		fout<<"Case #"<<i<<": ";

		fout<<ret<<endl;
		
	}
}
