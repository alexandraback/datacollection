#include<iostream>

using namespace std;

long long int a,b,t,gcd1,c,d,ret;
char ch;

long long gcd( long long a, long long b ) { return( b == 0 ? a : gcd( b, a % b ) ); }

long long int solve(long long int a,long long int b)
{
  if(a>b)
    return -1;
  if(b==1)
  {
    if(a==0)
      return -1;
    else
      return 1;
  }
  long long int mul=1,pow=-1;
  for(int i=1;i<=41;i++)
  {
    if(b==mul)
    {
      pow=(i-1);
      break;
    }
    mul*=2;
  }
  
  if(pow==-1)
    return -1;
  
  if(a==0)
    return -1;
  long long int pow2=pow;
  
  //cout<<"solve: a:"<<a<<" b:"<<b<<" pow:"<<pow<<"\n";
  while(pow)
  {
    //cout<<"(1<<(pow-1)) = "<<(1<<(pow-1))<<"\n";
    if(a >= (1<<(pow-1)))
      return (pow2-pow+1);
    pow--;
  }
}
  
  

int main()
{
  cin>>t;
  
  for(int q=1;q<=t;q++)
  {
    cin>>a>>ch>>b;
  
  
    gcd1=gcd(a,b);
    c=a/gcd1;
    d=b/gcd1;
    
    ret=solve(c,d);
    
    if(ret==-1)
      cout<<"Case #"<<q<<": "<<"impossible"<<"\n";
    else
      cout<<"Case #"<<q<<": "<<ret<<"\n";
  }
}
