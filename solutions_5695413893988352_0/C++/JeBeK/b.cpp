#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

long long p[30],a,b,x,y,now;

string st(long long k,long long t)
{
  string ret="";
  for(int i=t-1;i>-1;i--)
    ret+=char((k/p[i])%10+'0');
  return ret;
}

long long f(string s,long long k)
{
  long long ret=0;
  for(int i=0;i<s.size();i++)
    {
      ret*=10;
      if(s[i]=='?') ret+=k;
      else ret+=int(s[i]-'0');
    }
  return ret;
}

void check()
{
  x+=now,y+=now;
  if(abs(a-b)>abs(x-y)) a=x,b=y;
  if(abs(a-b)<abs(x-y)) return;
  if(x<a || (a==x && y<b)) a=x,b=y;
}  

int main()
{
  int qw;
  cin>>qw;
  p[0]=1;
  for(int i=1;i<=20;i++)
    p[i]=p[i-1]*10;
  for(int q=1;q<=qw;q++)
    {
      string s,t;
      cin>>s>>t;
      a=f(s,0),b=f(t,0);
      now=0;
      for(int i=0;i<=s.size();i++)
	{
	  if(i==s.size())
	    {
	      x=y=0;
	      check();
	      break;
	    }
	  if(s[i]=='?' && t[i]=='?')
	    {
	      x=f(s.substr(i+1,s.size()-i-1),9);
	      y=f(t.substr(i+1,t.size()-i-1),0)+p[s.size()-i-1];
	      check();
	      x=f(s.substr(i+1,s.size()-i-1),0)+p[s.size()-i-1];
	      y=f(t.substr(i+1,t.size()-i-1),9);
	      check();
	      continue;
	    }
	  if(t[i]=='?')
	    {
	      if(int(s[i]-'0')<9)
		{
		  t[i]=char(int(s[i])+1);
		  x=f(s.substr(i,s.size()-i),9);
		  y=f(t.substr(i,t.size()-i),0);
		  // cout<<i<<" "<<x<<" "<<y<<endl;
		  check();
		}
	      if(int(s[i]-'0')>0)
		{
		  t[i]=char(int(s[i])-1);
		  x=f(s.substr(i,s.size()-i),0);
		  y=f(t.substr(i,t.size()-i),9);
		  check();
		}
	      t[i]='?';
	      now+=int(s[i]-'0')*p[s.size()-i-1];
	      continue;
	    }
	  if(s[i]=='?')
	    {
	      if(int(t[i]-'0')<9)
		{
		  s[i]=char(int(t[i])+1);
		  x=f(s.substr(i,s.size()-i),0);
		  y=f(t.substr(i,t.size()-i),9);
		  check();
		}
	      if(int(t[i]-'0')>0)
		{
		  s[i]=char(int(t[i])-1);
		  x=f(s.substr(i,s.size()-i),9);
		  y=f(t.substr(i,t.size()-i),0);
		  check();
		}
	      s[i]='?';
	      now+=int(t[i]-'0')*p[s.size()-i-1];
	      continue;
	    }
	  if(s[i]!=t[i])
	    {	   
	      if(s[i]<t[i])
		{
		  x=f(s.substr(i,s.size()-i),9);
		  y=f(t.substr(i,s.size()-i),0);
		}
	      else
		{
		  x=f(s.substr(i,s.size()-i),0);
		  y=f(t.substr(i,s.size()-i),9);
		}
	      check();
	      break;
	    }
	  now+=int(s[i]-'0')*p[s.size()-i-1];
	}
      cout<<"Case #"<<q<<": "<<st(a,s.size())<<" "<<st(b,s.size())<<endl;
    }
}
