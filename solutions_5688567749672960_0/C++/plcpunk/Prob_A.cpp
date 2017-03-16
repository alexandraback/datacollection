#include <iostream>
#include <fstream>
using namespace std;

int reverse(int n)
{
int res=0;
while(n!=0)
{
res=res*10+(n%10);
n=n/10;
}
return res;
}
int dp[1000009];

int main()
{
ifstream in("A-small-attempt0.in");
ofstream out("A-small-attempt0.out");
dp[1]=1;
for(int i=2;i<=1000000;i++)
{
dp[i]=dp[i-1]+1;
int k=reverse(i);
if(k<i && i%10!=0)
dp[i]=min(dp[i],dp[k]+1);
}
int t;
in>>t;
for(int y=1;y<=t;y++)
{
int n;
in>>n;
out<<"Case #"<<y<<": ";
out<<dp[n]<<"\n";
}
}
