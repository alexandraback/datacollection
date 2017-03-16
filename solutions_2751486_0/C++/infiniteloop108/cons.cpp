#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main()
{int T;
int t;
cin>>t;
T=t;
while(t)
{
char s[1000001];
int n;
cin>>s>>n;
int q=0;
int start=0;
vector<int> pos(1000001,0);
for(int i=0;i<strlen(s);++i)
{
if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
{q=0;
start=i;
}
else
q++;
if(q>=n)
{
pos[i]=1;
}
}
long long ans=0;
int prev=n-1;
for(int i=0;i<strlen(s)-n+1;++i)
{
int sch=i+n-1;
int j;
for(j=prev;j<strlen(s);++j)
{
if(j>=sch&&pos[j])break;
}
if(j==strlen(s))break;
prev=j;
ans+=strlen(s)-j;
}
cout<<"Case #"<<T-t+1<<": "<<ans<<endl;
t--;
}
return 0;
}
