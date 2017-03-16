#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<fstream>
using namespace std;
int E,R,N,ans;
vector <int> v;
int s[10];
void process(int depth,int ener)
{
	if(depth==N)
	{
		int x=0;
		for(int i=0;i<N;i++)
		x+=(v[i]*s[i]);
		ans=max(ans,x);
		return;
	}
	for(int i=0;i<=ener;i++)
	{
		s[depth]=i;
		process(depth+1,min(ener+R-i,E));
	}
}
int main()
{
	ifstream fin("B.in");
	ofstream fout("B.out");
	int t;
	vector <int> fans;
	fin>>t;
	for(int i=0;i<t;i++)
	{
		fin>>E>>R>>N;
		v.clear();
		for(int j=0;j<N;j++)
		{
			int x;
			fin>>x;
			v.push_back(x);
		}
		ans=0;
		process(0,E);
		fans.push_back(ans);
	}
	for(int i=0;i<fans.size();i++)
	fout<<"Case #"<<i+1<<": "<<fans[i]<<"\n";
	return 0;
}
