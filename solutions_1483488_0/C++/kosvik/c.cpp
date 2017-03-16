#include <iostream>
//#include <vector>
//#include <algorithm>
#include <stdlib.h>

using namespace std;

#define ita(i_,f_,t_) for(int i_=f_;i_<t_;++i_)
#define itd(i_,f_,t_) for(int i_=f_;i_>t_;--i_)

int p10(int n)
{
    int p = 1;
    for (n = n / 10;n>0;n = n / 10)
        p = p * 10;
    return p;
}

int sl(int m, int p)
{
    int d = m % 10;
    m = m / 10;
    return m + (d * p);
}

int main()
{
    int T;
    cin>>T;
    for(int t=0; t<T; ++t)
    {
        int A,B;
        cin>>A>>B;

        int k=0;
        if (A>9)
        {
            ita(n,A,B)
            {
                int m=n;
                int p = p10(A);
                do
                {
                   m = sl(m,p);
                   if (m>n && m<=B)
                        ++k;
                } while(n!=m);
            }
        }

        cout<<"Case #"<<(t+1)<<": "<<k<<endl;
    }
    return 0;
}
