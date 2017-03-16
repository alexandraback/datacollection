#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <vector>
//#define max 100
using namespace std;
//int numb=0;
//int max=0;
int j=0;
bool fl=false;
unsigned long long n,t,k,q,r,n1,n2,x;
string s,st;
char c;
int brr[30];
int crr[100];
int arr[100000];
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(j=0;j<30;j++)
      brr[j]=0;
    for(j=0;j<100;j++)
      crr[j]=0;
    for(j=0;j<100000;j++)
      arr[j]=0;
    fl=false;r=0;
    cin>>t>>x>>k;
    for(j=0;j<x;j++)
    {
      cin>>brr[j];
    }
    n1=0;
    for(j=0;j<x;j++)
    {
      for(n2=0;n2<n1;n2++)
      {
        arr[n1+n2]=arr[n2]+brr[j];
      }
      arr[2*n1]=brr[j];n1=2*n1+1;
    }
    sort(arr,arr+n1);
    do{fl=false;
    for(j=0;j<n1;j++)
    {
      crr[arr[j]-1]=1;
    }
    for(j=0;j<k;j++)
    {
      if(crr[j]==0)
      {
        brr[x+r]=j+1;
        r++;fl=true;
        break;
      }
    }
    for(n2=0;n2<n1;n2++)
    {
      arr[n1+n2]=arr[n2]+brr[x+r-1];
    }
    arr[2*n1]=brr[x+r-1];n1=2*n1+1;
    sort(arr,arr+n1);
    }while(fl);
    cout<<"Case #"<<(i+1)<<": "<<r;
    /*if(k==1)
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
    }*/
    cout<<endl;
  }
  return 0; 
}