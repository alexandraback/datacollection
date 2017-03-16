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

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	fori(t,0,T)
	{
		int N;
		cin>>N;
		double ss=0;
		vector<double> s(N);
		fori(n,0,N)
		{
			cin>>s[n];
			ss+=s[n];
		}

		vector<double> s0=s;
		sort(s0.begin(),s0.end());
		double d = ss;
		double x=0;
		fori(n,0,N)
		{
			x+=s0[n];
			double d0=(x+ss)/(n+1);
			if (d0<s0[n])
				break;
			d=d0;
		}
		
		cout<<"Case #"<<t+1<<":";
		fori(n,0,N)
		{
			cout.setf(ios_base::fixed);
			cout.precision(6);
			double m = d>s[n]?((d-s[n])/ss * 100):0;
			cout<<" "<<m;
		}
		cout<<std::endl;
	}

	return 0;
}


