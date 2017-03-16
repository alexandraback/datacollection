#include<iostream>
#include<queue>
#include<map>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stdio.h>
#include<string.h>

using namespace std;
vector<long long> arr;
long long start,end;
  
bool isPalin(long long n){
     long long temp=n,rev=0;
     while(n) rev=rev*10+n%10,n/=10;
     return temp==rev;
}

int findleft(int l, int r){
    int m=(l+r)/2;
    if(arr[m]==start||(arr[m]>start&&arr[m-1]<start))
      return m-1;
    if(arr[m]<start)
      return findleft(m+1,r);
    return findleft(l,m-1);
}

int findright(int l, int r){
    int m=(l+r)/2;
    if(arr[m]==end||(arr[m]<end&&arr[m+1]>end))
      return m+1;
    if(arr[m]<end)
       return findright(m+1,r);
    return findright(l,m-1);
}
int main(){
    int t,i,c=1; 
   // freopen("input.in","r",stdin);
   // freopen("output.out","w",stdout);
    long long x;
    int l,r;
    for(x=1;x<=(long long)1e7;x++)
     if(isPalin(x)&&isPalin(x*x))
       arr.push_back(x*x);
    arr.push_back(1000000000000000000LL);   
    //for(int i=0;i<arr.size();i++)
      //cout<<arr[i]<<endl;
    cin>>t;
    while(t--){
               cin>>start>>end;
               l=findleft(0,arr.size()-1);
               r=findright(0,arr.size()-1);
               cout<<"Case #"<<c++<<": "<<r-l-1<<endl;   
    }
    
    return 0;
}
