#include<iostream>

using namespace std;

int a,b;

int bw(int n)
{
  if(a<=n && b>=n)
     return 1;
 return 0;
}

int main()
{
  int c, t, sum;
  cin>>t;
  c=1;
  while(t--)
  {
    cout<<"Case #"<<c<<": ";
    c++;
    cin>>a>>b;
    sum=bw(1)+bw(4)+bw(9)+bw(121)+bw(484);
    cout<<sum<<'\n';
  }
  return 0;
}