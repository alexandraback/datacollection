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

  std::ifstream in("B-large.in");
  //std::ifstream in("a.txt");
  std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
  std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

  std::ofstream out("b-out.txt");
  std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
  std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

  cin>>t;
  string s;

  for(int test=1;test<=t;test++)
  {
      cin>>s;
      int l=s.size();
      int count=0;
      while(true)
      {
        int i=1;
        while(i<l)
        {
          if(s[i]!=s[i-1])break;
          else i++;
        }
        if(i<l)
        {
          for(int j=0;j<i;j++)
          {
            if(s[j]=='+')s[j]='-';
            else s[j]='+';
          }
          count++;
        }
        else
        {
          if(s[0]=='-')count++;
          cout<<"Case #"<<test<<": "<<count<<endl;
          break;
        }
      }



  }
}
