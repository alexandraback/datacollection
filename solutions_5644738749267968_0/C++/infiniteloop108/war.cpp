#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void doit(int tc)
{
int n;
cin>>n;
vector<double> naomi(n),ken(n);
for(int i=0;i<n;++i)cin>>naomi[i];
for(int i=0;i<n;++i)cin>>ken[i];
sort(naomi.begin(),naomi.end());
sort(ken.begin(),ken.end());
int a1,a2;
//for(int i=0;i<n;++i)cout<<naomi[i]<<" ";
//cout<<endl;
//for(int i=0;i<n;++i)cout<<ken[i]<<" ";
//cout<<endl;
a1=0;
for(int i=0;i<n;++i)
{
if(naomi[i]>ken[a1])a1++;
}
a2=0;
for(int i=n-1;i>=0;i--)
{
int done=n-i-1;
if(naomi[i]>ken[n-done+a2-1])a2++;
}
cout<<"Case #"<<tc<<": "<<a1<<" "<<a2<<endl;
}
int main()
{
int t;
cin>>t;
int i=1;
while(t--)
{
doit(i++);
}
return 0;
}
