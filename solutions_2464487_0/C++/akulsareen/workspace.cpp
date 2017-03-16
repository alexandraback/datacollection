#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	ifstream fin("A.in");
	ofstream fout("A.out");
	int T;
	vector <int> ans;
	fin>>T;
	for(int i=0;i<T;i++)
	{
		int r,t,n=0;
		long long A;
		fin>>r>>t;
		for(n=1;;n++)
		{
			A=(2*n*n)+(n*((2*r)-1));
			if(A>t)
			break;
		}
		ans.push_back(n-1);
	}
	for(int i=0;i<ans.size();i++)
	fout<<"Case #"<<i+1<<": "<<ans[i]<<"\n";
	return 0;
}
