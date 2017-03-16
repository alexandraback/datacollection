#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long md=1000000007;
int main()
{
  int t;
  long long n;
  //scanf("%d",&t);
  string a,b;
  std::ifstream in("A-large.in");
  //std::ifstream in("a.txt");
  std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
  std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

  std::ofstream out("a-out.txt");
  std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
  std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

  cin>>t;
  for(int test=1;test<=t;test++)
  {
      cin>>n;
      bool seen[10]={0};
      if(n!=0)
      {
        long long m=n,p,q;
        while(true)
        {
          p=m;
          while(p)
          {
            q=p%10;seen[q]=1;
            p/=10;
          }
          bool flag=true;
          for(int i=0;i<10;i++)if(seen[i]==0)flag=false;
          if(flag)break;
          m+=n;

        }
        cout<<"Case #"<<test<<": "<<m<<endl;

      }
      else cout<<"Case #"<<test<<": INSOMNIA"<<endl;
  }

}
