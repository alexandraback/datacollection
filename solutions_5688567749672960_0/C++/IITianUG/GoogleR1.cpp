#include<bits/stdc++.h>
using namespace std;
int dp[1000010];
int reversex(int n)
 {    int sum=0;
     while(n>0)
     {
     int r=n%10;

     sum=sum*10+r;
     n=n/10;
     }

     return sum;
 }
 int main()
 {
    ifstream IF;
     ofstream OF;
     int t,i,trm,n;
     IF.open("input.txt");
     OF.open("output.txt");

     for(i=1;i<=9;i++)
        dp[i]=i;
     for(i=10;i<=1000010;i++){
            if(reversex(i)<i && i%10!=0)
        dp[i]=1+min(dp[i-1],dp[reversex(i)]);
     else dp[i]=1+dp[i-1];
     }


IF>>t;
for(trm=1;trm<=t;trm++)
{
    IF>>n;
    OF<<"Case #"<<trm<<": "<<dp[n]<<endl;
}
IF.close();
OF.close();
return 0;
 }
