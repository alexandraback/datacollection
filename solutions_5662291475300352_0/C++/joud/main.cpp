# include <iostream>
# include<algorithm>
#include <stdio.h>
# include <cstdlib>
# include <ios>
# include <vector>
using namespace std;
int main()
{
   freopen("out1.txt","w",stdout);
   long  t;
   cin>>t;

   for (long  gogo=1;gogo<=t;gogo++)
   {
        long double n;
        cin>>n;
       cout<<"Case #"<<gogo<<": ";
        if (n==1)
        {
            long double d,h,m;
            cin>>d>>h>>m;
            if (h==1)
                cout<<0<<endl;
            else
            {
                long double tim=(359-d)*((m+1)/360.0);
                long double tim1=(720-d)*(m/360.0);
                if (tim+0.00001<tim1)
                    cout<<0<<endl;
                else
                    cout<<1<<endl;
            }
        }
        else
        {
            long double d1,h,m1;
            long double d2,m2;
            cin>>d1>>h>>m1;
            cin>>d2>>h>>m2;
            if (d1>d2)
                swap(d1,d2),swap(m1,m2);
            long double d=d1-1;
            long double m=m1;
            long double tim=(360-d)*(m1/360.0);
            long double tim1=(720-d2)*(m2/360.0);
            if (tim+0.00001<tim1)
                cout<<0<<endl;
            else
                cout<<1<<endl;
        }
   }
}
