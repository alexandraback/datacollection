#include<iostream>
using namespace std;
int main()
{
int t;
cin>>t;
for(int q=1;q<=t;++q)
{
int x,y;
cin>>x>>y;
cout<<"Case #"<<q<<": ";
if(x<0)
{for(int j=0;j<(0-x);++j)
cout<<"EW";}
else
{for(int j=0;j<(x);++j)
cout<<"WE";}
if(y<0)
{for(int j=0;j<(0-y);++j)
cout<<"NS";}
else
{for(int j=0;j<(y);++j)
cout<<"SN";}
cout<<endl;
}
return 0;
}
