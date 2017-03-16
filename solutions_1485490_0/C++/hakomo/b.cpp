#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
long long a[100],b[100],c[100][100];
int A[100],B[100],n,m;
long long fn(int p,int q){
  int i;
  if(p==n||q==m)
    return 0;
  //if(c[p][q]>=0)
  //return c[p][q];
  long long mx=0,sm=0;
  for(i=0;i<=m-q;++i){
    if(a[p]<sm&&A[p]==B[q+i-1]){
      long long t=b[q+i-1];
      b[q+i-1]=sm-a[p];
      mx=max(mx,min(a[p],sm)+fn(p+1,q+i-1));
      b[q+i-1]=t;
    }else{
      mx=max(mx,min(a[p],sm)+fn(p+1,q+i));
    }
    if(A[p]==B[q+i])
      sm+=b[q+i];
  }
  return c[p][q]=mx;
}
int main(){
  int h,i;
  int t;
  cin>>t;
  for(h=1;h<=t;++h){
    cin>>n>>m;
    for(i=0;i<n;++i)
      cin>>a[i]>>A[i];
    for(i=0;i<m;++i)
      cin>>b[i]>>B[i];
    memset(c,-1,sizeof(c));
    cout<<"Case #"<<h<<": "<<fn(0,0)<<endl;
  }
  return 0;
}
