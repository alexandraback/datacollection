// a.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
//#include <cmath>
#include <cstdlib>

using namespace std;

#define fori(i_,f_,t_) for(int i_=f_;i_<t_;++i_)
#define fore(i_,c_) for(auto i_=c_.begin();i_!=c_.end();++i_)
#define pb	push_back

int ns[20];

int sum(int k)
{
	int s=0;
	int n=0;
	while(k)
	{
		if (k&1)
			s+=ns[n];
		++n;
		k>>=1;
	}

	return s;
}

void print(int k)
{
	int s=0;
	int n=0;
	while(k)
	{
		if (k&1)
			cout<<ns[n]<<" ";
		++n;
		k>>=1;
	}
}


int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	fori(t,0,T)
	{
		int N;
		cin>>N;
		for(int n=0;n<20;++n)
		{
			cin>>ns[n];
		}

		cout<<"Case #"<<t+1<<": "<<std::endl;

		map<int,int> ms;
		int i=1;
		for(;i<(1<<20);++i)
		{
			int s = sum(i);
			if (ms[s]!=0)
			{
				print(ms[s]);
				cout<<std::endl;
				print(i);
				break;
			} else
				ms[s]=i;
		}
		if (i==(1<<20))
			cout<<"Impossible";
		cout<<std::endl;
	}

	return 0;
}

