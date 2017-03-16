#include<iostream>
#include<algorithm>

using namespace std;

int n,dp[1000000];
string a[20],b[20];

int main()
{
  int qw;
  cin>>qw;
  for(int q=1;q<=qw;q++)
    {
      cin>>n;
      for(int i=0;i<n;i++)
	cin>>a[i]>>b[i];
      for(int i=0;i<(1<<n);i++)
	{
	  dp[i]=0;
	  for(int j=0;j<n;j++)
	    if((1<<j)&i)
	      {
		int ret=dp[i-(1<<j)];
		bool mark1=false,mark2=false;
		for(int x=0;x<n;x++)
		  if(x!=j && ((1<<x)&i))
		    {
		      if(a[x]==a[j]) mark1=true;
		      if(b[x]==b[j]) mark2=true;
		    }
		if(mark1 && mark2)
		  ret++;
		dp[i]=max(dp[i],ret);
	      }
	}
      cout<<"Case #"<<q<<": "<<dp[(1<<n)-1]<<endl;
    }
}
