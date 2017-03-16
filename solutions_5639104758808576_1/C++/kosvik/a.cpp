// a.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
//#include <cmath>
#include <cstdlib>
#include <string>

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
        int n;
        string s;
        cin>>n>>s;
        n++;
        if ((int)s.size()!=n) { cerr<<"e1\n";return -1; }
        int a=0;
        int r=0;
        fori(i,0,n)
        {
            int d = s[i]-'0';
            if (d<0 || d>9) { cerr<<"e2\n";return -1; }
            if (d >0 && i>a)
            {
                r += i-a;
                a += i-a;
            }

            a += d;

        }

		cout<<"Case #"<<t+1<<": ";

        cout<<r<<std::endl;
	}

	return 0;
}

