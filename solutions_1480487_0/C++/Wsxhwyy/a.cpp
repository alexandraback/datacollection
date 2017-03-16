#include <iostream>
#include <iomanip>
using namespace std;
int a[1000];
int n;
int main()
{
int t;
cin>>t;
for(int x=0;x<t;x++)
{
cin>>n;
int sum=0;
for(int i=0;i<n;i++){
cin>>a[i];
sum+=a[i];
}
cout<<"Case #"<<x+1<<":";
double totalscore=sum+sum;
int p=n;
for(int i=0;i<n;i++){
double b=sum+sum;
b=b/n-a[i];
if(b<0) totalscore-=a[i],p--;
}
for(int i=0;i<n;i++){
double b=sum+sum;
b=totalscore/p-a[i];
b/=sum;
if(b<0) cout<<" "<<setprecision(10)<<0;
else cout<<" "<<setprecision(10)<<b*100;
}
cout<<endl;
}
}