#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <stdlib.h>
#include <sstream>
#include <ctime>
#include <fstream>
using namespace std;
 
using namespace std;

 
#define INF 1000000000
#define PI acos(-1.0)
#define MP make_pair
long double EPS=1e-10;
#define MOD 1000000007 

 
pair<long long,long long> A[100],B[100];

void solve(){
 long long n,m;
 cin>>n>>m;

 for (long long i=0; i<n; i++){
  cin>>A[i].first>>A[i].second;
 }

 if (n==1) A[1]=MP(0,0),n++;
 if (n==2) A[2]=MP(0,0),n++;

 if (A[0].second==A[1].second){
  A[1].first+=A[0].first;
  A[0].first=0;
 }

 if (A[1].second==A[2].second){
  A[2].first+=A[1].first;
  A[1].first=0;
 }

 for (long long j=0; j<m; j++){
  cin>>B[j].first>>B[j].second;
 }

 long long res=0;

 for (long long i=0; i<=m; i++){
  for (long long j=i; j<=m; j++){
   

    long long c=0;
    long long X=A[0].first;
    for (long long g=0; g<i; g++){
     if (B[g].second==A[0].second){
      c+=min(X,B[g].first);
      X-=B[g].first;
      X=max(X,0ll);
     }
    }


    X=A[1].first;

    for (long long g=i; g<j; g++){
     if (B[g].second==A[1].second){
      c+=min(X,B[g].first);
      X-=B[g].first;
      X=max(X,0ll);
     }
    }


    X=A[2].first;
    for (long long g=j; g<m; g++){
     if (B[g].second==A[2].second){
      c+=min(X,B[g].first);
      X-=B[g].first;
      X=max(X,0ll);
     }
    }


    res=max(res,c);

   
  }
 }

 if (A[0].second==A[2].second){
  A[0].first+=A[2].first;
  A[1].first=0;
  A[2].first=0;

  long long c=0;

  for (long long i=0; i<m; i++){
   if (B[i].second==A[0].second){
    c+=min(A[0].first,B[i].first);
    A[0].first-=B[i].first;
    A[0].first=max(A[0].first,0ll);
   }
  }

  res=max(res,c);
 }

 cout<<res<<endl;
 cerr<<res<<endl;

}

int main(){

 freopen("inputC.txt","r",stdin);
 freopen("outputC.txt","w",stdout);

 long long tt;
 cin>>tt;
 for (long long t=1; t<=tt; t++){
  cerr<<"Case #"<<t<<endl;
  cout<<"Case #"<<t<<": ";
  solve();
 }

}