#include <iostream>

using namespace std;

int main()
{
   int T,r,t,i;
   int p;
   cin>>T;
   p=1;
   while(T--)
   {   int c=0,sum=0;
       cin>>r>>t;
       for(int i=0;;i+=2)
       {
           sum+=((r+1+i)*(r+1+i))-((r+i)*(r+i));
           if(sum<=t)
           c++;
           else
           break;
       }
       cout<<"Case #"<<p<<": "<<c<<"\n";
       p++;
   }
    return 0;
}
