#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<map>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long i64;typedef i64 int64;
typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

int K,L,S;
string key,tar;

int maxalls=0;

int cnt(string s){
  int ans=0;
  rep(i,s.size()){
    if(s.substr(i,tar.size())==tar){
      ans++;
    }
  }
  maxalls=max(maxalls,ans);
  return ans;
}


double rec(int n,string s){
  if(n==S){
    return cnt(s);
  }
  
  double ans=0;
  rep(i,K){
    string ss=s+key[i];
    double ret=rec(n+1,ss);
    ans+=ret/K;
  }
  return ans;
}


int main()
{
  int T;
  cin>>T;
  int cnt=1;
  while(T){
    maxalls=0;
    cin>>K>>L>>S;
    cin>>key;
    cin>>tar;

    double ret=rec(0,"");
    //printf("all %d ret %f\n",maxalls,ret);
    double ans=maxalls-ret;
    printf("Case #%d: %.10f\n",cnt,ans);
    T--;cnt++;
  }
  return 0;
}
