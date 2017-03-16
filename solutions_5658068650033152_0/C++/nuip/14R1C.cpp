#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

int N,M,K;

bool chk(int a,int b,int c){
  if(b<0 || N<=b || c<0 || M<=c)
    return 0;
  return (a&(1<<(b*M+c)))>0;
}

int check(int a,int b,int c){
  return (chk(a,b+1,c)+chk(a,b-1,c)+chk(a,b,c+1)+chk(a,b,c-1)<4);
}
int main(){
  int t,T;
  cin>>T;
  for(t=1;t<=T;t++){
    cout<<"Case #"<<t<<": ";
    ll i,j,k;
    cin>>N>>M>>K;
    if(N*M>20){
      cout<<0<<endl;
      continue;
    }
    int sum=0,sm=0,mp[21],re=2000;
    for(i=0;i<(1<<(N*M));i++){
      sum=0;
      for(int a=i;a;a/=2)
        sum+=(a%2);
      if(sum<K)continue;
    //  cout<<sum<<",";
      sm=0;
  //    fill(mp,mp+21,0);
      for(j=0;j<N;j++){
        for(k=0;k<M;k++){
          if(check(i,j,k) && (i&(1<<(j*M+k)))>0)
            sm++;;
        }
      }
  //    cout<<sm<<endl;
      re=min(re,sm);
    }
    cout<<re<<endl;
  }
  return 0;
}