#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long md=1000000007;

long long expo(long long x,long long p)
{
  if(p==0)return 1;
  if(p==1)return x;
  long long ans=expo(x,p/2);
  ans*=ans;
  if(p%2)ans*=x;
  return ans;
}
int main()
{
  int t;
  long long n;
  //scanf("%d",&t);

  std::ifstream in("D-small-attempt0.in");
  //std::ifstream in("a.txt");
  std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
  std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

  std::ofstream out("temp-out.txt");
  std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
  std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

  cin>>t;
  for(int test=1;test<=t;test++)
  {
    long long  k,c,s,a,b,d;
    cin>>k>>c>>s;
    long long min=k/c;
    if(k%c!=0)min++;
    if(s>=min)
    {
      long long i=0;
      cout<<"Case #"<<test<<": ";
      for(int j=0;j<min;j++)
      {
        a=0;
        for(int l=1;l<=c;l++)
        {
          a+=i*expo(k,c-l);
          i++;if(i>=k)i=0;
        }
        cout<<a+1<<" ";
      }
      cout<<endl;
    }
    else cout<<"Case #"<<test<<": IMPOSSIBLE"<<endl;


  }

}
