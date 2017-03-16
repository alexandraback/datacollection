// a.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
//#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

#define fori(i_,f_,t_) for(int i_=f_;i_<t_;++i_)
#define fore(i_,c_) for(auto i_=c_.begin();i_!=c_.end();++i_)
#define pb	push_back

int search(const string& s,int f,int n)
{
	int k=0;
	int j=f;
	fori(i,f,int(s.size()))
	{
		char c= s[i];
		if (c=='a' || c=='i' || c=='e' || c=='o' || c=='u' )
		{
			k=0;
		} else
		{
			++k;
			if (k==1)
			{
				j=i;
			}

			if (k==n)
			{
				return j;
			}
		}
	}
	return -1;
}

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	fori(t,0,T)
	{
		string s;
		cin>>s;
		int n;
		cin>>n;

		
		__int64 ss = 0;
		int pp = 0;
		if (n==0)
		{
			ss= __int64(s.size());
			ss= ss*(ss+1) / 2;
		} else
		for(;;)
		{
			int p=search(s,pp,n);
			if (p<0)
				break;
			ss += __int64(int(s.size())-(p + n) + 1)*__int64(p-pp+1);
			pp=p+1;
		}
		cout<<"Case #"<<t+1<<": ";

        cout<<ss<<std::endl;
	}

	return 0;
}

