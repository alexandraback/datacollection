#include <iostream>
//#include <vector>
//#include <algorithm>
#include <stdlib.h>

using namespace std;

#define ita(i_,f_,t_) for(int i_=f_;i_<t_;++i_)
#define itd(i_,f_,t_) for(int i_=f_;i_>t_;--i_)

int ts[100];
int m[100];

int main()
{
    int T;
    cin>>T;
    for(int t=0; t<T; ++t)
    {
        int N,S,p;
        cin>>N>>S>>p;
        ita(n,0,N)
        {
            int t;
            cin>>t;
            ts[n]=t;
            m[n]=0;
        }
        int r = 0;
        int tl = 3 * p - 2;
        ita(n,0,N)
        {
            if (ts[n] >=tl )
            {
                ++r;
                m[n]=1;
            }
        }

        tl = (p>1)?(3 * p - 4):p;

        for(int n=0;n<N && S>0 ; ++n)
        {
            if (ts[n] >=tl && m[n]==0)
            {
                ++r;
                --S;
            }
        }

        cout<<"Case #"<<(t+1)<<": "<<r<<endl;
    }
    return 0;
}
