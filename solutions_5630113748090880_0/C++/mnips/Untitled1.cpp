#include<iostream>
#include<string.h>
#include<iomanip>
#include<math.h>
using namespace std;
typedef long long int ll;
int main()
{ freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
ll l,t;
cin>>t;
for(l=1;l<=t;l++)
{
int i,n,r,j;
cin>>n;
int hash[2501]={0};
for(i=0;i<2*n-1;i++)
{for(j=0;j<n;j++)
{
cin>>r;
hash[r]++;
}
}
cout<<"Case #"<<l<<": ";
for(i=0;i<2501;i++)
{if(hash[i]%2!=0)
 cout<<i<<" ";
}
cout<<endl;

}
return 0;
}
