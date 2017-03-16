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
    ll i,j,k,re=1<<30;
    cin>>N>>M>>K;
   for(i=1;i<=K+4;i++)
     if(i<=N && (K+3+i)/i<=M)
       re=min(re,i*2+(K+3+i)/i*2-(i>2&&(K+3+i)/i>2)*4-4);
    cout<<re<<endl;
  }
  return 0;
}