// c.cpp : Defines the entry point for the console application.
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


int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	fori(t,0,T)
	{
		int X,Y;
		cin>>X>>Y;

		string p;
		if (X>=0)
		{
			fori(i,0,X)
			{
				p.append("WE");
			}
		} else
		{
			fori(i,0,-X)
			{
				p.append("EW");
			}
		}

		if (Y>=0)
		{
			fori(i,0,Y)
			{
				p.append("SN");
			}
		} else
		{
			fori(i,0,-Y)
			{
				p.append("NS");
			}
		}

		cout<<"Case #"<<t+1<<": ";

        cout<<p<<std::endl;
	}

	return 0;
}

