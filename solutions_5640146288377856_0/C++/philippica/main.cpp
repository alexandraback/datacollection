#include<cstdio>
#include<iostream>
#include<fstream>
#define ll long long
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
int main()
{
	int t,cas=0,r,c,w;
	fin>>t;
	while(t--)
	{
		fin>>r>>c>>w;
		int u=c*r/(w)-1+w;
		if(c%w!=0)u++;
		fout<<"Case #"<<++cas<<": "<<u<<endl;
	}
	return 0;
}
