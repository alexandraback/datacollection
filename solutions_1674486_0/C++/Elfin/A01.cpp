#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<cstring>

using namespace std;


void input(vector< vector<int> > &father, vector< vector<int> > &son, vector<int> &nofather)
{
	for(int j=0;j<father.size();j++)
	{
		int M;
		cin>>M;
		for(int i=0; i<M; i++)
		{
			int tmp;
			cin>>tmp;
			father[j].push_back(tmp-1);
			son[tmp-1].push_back(j);
		}
		if(M==0) nofather.push_back(j);
	}
}

bool dsearch(int p , vector<int> &map, const vector< vector<int> > &son)
{
	map[p]++;
	if(map[p]>1) return true;
	for(int i=0; i<son[p].size(); i++)
	{
		if(dsearch(son[p][i], map, son)) return true;
	}
	return false;
}

bool begin_dsearch(vector< vector<int> > &son, vector<int> &nofather)
{
	for(int i=0;i<nofather.size(); i++)
	{
		vector< int > map(son.size(), 0);
		if(dsearch(nofather[i], map, son)) return true;
	}
	return false;
}

int main()
{
	freopen("C:\\Documents and Settings\\theaa\\My Documents\\Downloads\\A-small-attempt3.in","r",stdin);
	freopen("C:\\Documents and Settings\\theaa\\My Documents\\Downloads\\A-small-attempt3.out","w",stdout);
	int T;
	cin>>T;
	
	for(int caseno=1; caseno<=T; caseno++)
	{
		int N;
		cin>>N;
		vector< vector<int> > father(N);
		vector< vector<int> > son(N);
		vector<int> nofather;
		input(father, son, nofather);

		bool ans = begin_dsearch(son, nofather);
		
		if(ans)
			cout<<"Case #"<<caseno<<": "<<"Yes"<<endl;
		else
			cout<<"Case #"<<caseno<<": "<<"No"<<endl;
	}


	return 0;
}