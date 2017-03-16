#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int ttt;
cin>>ttt;
for(int tttt=1;tttt<=ttt;tttt++)
{
int n;
cin>>n;
int s;
cin>>s;
int p;
cin>>p;
int a[1000];
for(int i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
int max[31]={0,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,10,10};
int min[31]={0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10};
int ans=0;
for(int i=n-1;i>=0;i--)
{
if(min[a[i]] >= p)ans++;
else if(s>0 && max[a[i]] >= p){s--; ans++;}
else break;
}
cout<<"Case #"<<tttt<<": "<<ans<<endl;

}
}
