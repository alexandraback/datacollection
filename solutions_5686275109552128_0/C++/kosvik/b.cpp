// c.cpp : Defines the entry point for the console application.
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
        int D;
        cin>>D;

        std::vector<int> ds(D);

        fori(i,0,D)
        {
            int v;
            cin>>v;
            ds[i]=v;
        }

        std::sort(ds.begin(), ds.end(), std::greater<int>());

        int g = ds[0];
        int d = 2;
        int m = g;
        while(d*d <= g)
        {
            int a = (g + d-1)/d;
            
            
            fori(i,1,(D+1))
            {
                bool e=false;
                int c = a + d-1;
                fori(k,1,i)
                {
                    int b = ds[k];
                    if (b<=a)
                    {
                        e=true;
                        break;
                    }
                    int x = (b + a -1)/a;
                    c+=x-1;
                }

                if (i<D && ds[i]>a)
                    c=ds[i]-a+c;

                if (c<m)
                      m=c;

            }

            ++d;

        }

		cout<<"Case #"<<t+1<<": ";

        cout<<m<<std::endl;
	}

	return 0;
}

