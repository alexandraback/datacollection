#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long md=1000000007;



void swap(int &x,int &y)
{
  x+=y;y=x-y;x-=y;
}
long long dp(int a[],int n,int j)
{
  int x=j;int z=2;
  while(x)
  {
    int y=x%2;a[z]=y;a[z+1]=y;z+=2;
    x/=2;
  }
  for(;z<n-2;z++)a[z]=0;
}
int main()
{
  int t;
  int n,j;
  //scanf("%d",&t);

  std::ifstream in("C-small-attempt0.in");
  //std::ifstream in("a.txt");
  std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
  std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

  std::ofstream out("temp-out.txt");
  std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
  std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

  cin>>t;
  int a[32]={0};

  for(int test=1;test<=t;test++)
  {
    cin>>n>>j;
    cout<<"Case #"<<test<<":"<<endl;
    a[0]=1;a[1]=1;
    a[n-1]=a[n-2]=1;
    for(int i=0;i<j;i++)
    {
      dp(a,n,i);
      for(int k=n-1;k>=0;k--)cout<<a[k];

      for(int k=2;k<=10;k++)cout<<" "<<k+1;
      cout<<endl;
    }



  }



}
