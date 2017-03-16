#include<iostream>
using namespace std;
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int t,T,n,x,y;
cin>>T;
for(t=1;t<=T;t++)
{
cin>>x>>y;
cout<<"Case #"<<t<<": ";
while(x>0) cout<<"WE",x--;
while(x<0) cout<<"EW",x++;
while(y>0) cout<<"SN",y--;
while(y<0) cout<<"NS",y++;
cout<<endl;
}
return 0;
}