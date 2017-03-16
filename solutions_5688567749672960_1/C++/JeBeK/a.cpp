#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

long long dp[20],a[20],ans,MIN,x,y;
string s,s1;

int main()
{
  int qw;
  cin>>qw;
  dp[1]=9;
  a[0]=1;
  for(int i=1;i<18;i++)
    a[i]=a[i-1]*10;
  for(int i=2;i<18;i++)
    {
      dp[i]=dp[i-1]+a[i/2]+a[(i+1)/2]-1;
      //cout<<i<<" "<<dp[i]<<endl;
    }
  for(int q=1;q<=qw;q++)
    {
      ans=0;
      cin>>s;
      cout<<"Case #"<<q<<": ";
      int n=s.size();
      while(n>0 && s[n-1]=='0')
	n--;
      for(int i=n;i<s.size();i++)
	s[i]='9';
      if(n!=s.size())
	{
	  ans=1;
	  s[n-1]=char(int(s[n-1]-'0')-1+'0');
	}
      if(s[0]=='0')
	{
	  s1="";
	  for(int i=1;i<s.size();i++)
	    s1+=s[i];
	  s=s1;
	}
      n=s.size();
      if(n==1)
	{
	  cout<<ans+int(s[0]-'0')<<endl;
	  continue;
	}
      ans+=dp[n-1];
      MIN=(long long)1e18;
      for(int j=0;j<n-1;j++)
	{
	  x=y=0;
	  for(int i=j+1;i<n;i++)
	    x=x*10+int(s[i]-'0');
	  for(int i=j;i>-1;i--)
	    y=y*10+int(s[i]-'0');
	  MIN=min(MIN,x+y+1);
	  if(y==1)
	    MIN=min(MIN,x+1);
	  // cout<<x<<" "<<y<<" "<<j<<endl;
	}
      cout<<ans+MIN<<endl;
    }
}

