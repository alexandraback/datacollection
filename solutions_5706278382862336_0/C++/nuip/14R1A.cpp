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

ll gcd(ll a,ll b){
  return b?gcd(b,a%b):a;
}

int main(){
  int t,T;
  cin>>T;
  for(t=1;t<=T;t++){
    ll P,Q,i,j,k,p,q;
    scanf("%I64d/%I64d",&P,&Q);
    cout<<"Case #"<<t<<": ";
 //   cout<<P<<","<<Q<<endl;
//    cout<<gcd(P,Q)<<endl;
    p=P/gcd(P,Q);
    q=Q/gcd(P,Q);
    if(p==1 && q==1){
      cout<<0<<endl;
    }else if(q&(q-1)){
      cout<<"impossible"<<endl;
      continue;
    }else{
      int re=0;
      while(1){
        re++;
        if(q/2<=p)
          break;
        q/=2;
      }
      cout<<re<<endl;
    }
  //  cout<<p<<","<<q<<endl;
  }
  return 0;
}