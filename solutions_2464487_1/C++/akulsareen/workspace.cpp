#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
int process(long double n,long double r,long double t)
{
	long double a=2,b=(2*r)-1;
	if(((a*n*n)+(b*n))<t)
	return -1;
	else if(((a*n*n)+(b*n))>t)
	return 1;
	else
	return 0;
}
int main()
{
	ifstream fin("Al.in");
	ofstream fout("Al.out");
	int T;
	vector <unsigned long long> ans;
	fin>>T;
	for(int i=0;i<T;i++)
	{
		long double r,t;
		unsigned long long n,f,l,m;
		fin>>r>>t;
		f=1;
		l=1000000000;
		while(f<=l)
		{
			m=(f+l)/2;
			long double N=m;
			int x=process(N,r,t);
			if(x==0)
			break;
			else if(x==1)
			l=m-1;
			else
			f=m+1;
		}
		long double N=m;
		int x=process(N,r,t);
		if(x==1)
		m--;		
		ans.push_back(m);
	}
	for(int i=0;i<ans.size();i++)
	fout<<"Case #"<<i+1<<": "<<ans[i]<<"\n";
	return 0;
}
