#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<math.h>
using namespace std;
int main()
{
  fstream myf,f2;
  myf.open("input.txt",ios::in|ios::app);
  f2.open("output.txt",ios::out);
    int t;
    if(myf.is_open())
    {
        myf>>t;
        //cin>>t;
        //getline(cin,line);
        int test=0;
        while(t--)
        {
            test++;
            long double r,tt;
            myf>>r>>tt;
            //cout<<tt<<"\n";
            long double nn=(-(2.0*r-1.0)+sqrt(((2.0*r-1.0)*(2.0*r-1.0))+(8.0*tt)))/4.0;
            int ans=nn;
            f2<<"Case #"<<test<<": ";
            f2<<ans<<"\n";
            cout<<ans<<"\n";
        }
    }
    myf.close();
    f2.close();
    return 0;
}

