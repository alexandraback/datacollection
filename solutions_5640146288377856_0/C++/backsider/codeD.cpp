#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
//#define max 100
using namespace std;
//int numb=0;
//int max=0;
unsigned long long n,t,k,q,r,n1,n2,x;
string s,st;
char c;
int arr[100000];
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>t>>x>>k;
    cout<<"Case #"<<(i+1)<<": ";
    if(k==1)
      cout<<t*x;
    else if(t==1)
    {
      if(x==k)
        cout<<k;
      else
        cout<<((x%k)==0?0:1)+(x/k)+(k-1);
    }
    else
    {
      if(x==k)
        cout<<(t-1)+k;
      else
        cout<<t*(x/k)+((x%k)==0?0:1)+(k-1);
    }
    cout<<endl;
  }
  return 0; 
}