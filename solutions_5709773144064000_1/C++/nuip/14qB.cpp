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

int main(){
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++){
    double C,F,X,n=0,re=1e10,sec=0,cps=2;
    cin>>C>>F>>X;
    while(sec<=re){
      re=min(re,(X)/cps+sec);
      sec+=(C)/cps;
      cps+=F;
    }
    printf("Case #%d: %.7f\n",t,re);
  }
  return 0;
}