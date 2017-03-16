#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<complex>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
using namespace std;

#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

bool isCnt(string s , int n){
  bool alp[256];
  memset(alp , 0 ,sizeof(alp));
  alp['a'] = alp['i'] = alp['u'] = alp['e'] = alp['o'] = true;
  int cnt = 0;
  rep(i,s.size()){
    if(alp[s[i]]){
      if(cnt >= n)return true;
      cnt = 0;
    }
    else cnt++;
  }
  return cnt >= n;
}

int main(){
  int T;
  cin>>T;
  int C = 1;
  while(T--){
    string s;
    int n;
    cin>>s>>n;
    int res = 0;
    for(int i = 0; i < s.size() ; i++){
      for(int j = 0 ; j <= s.size()-i; j++){
        string ss = s.substr(i,j);
        if(ss.size() < n)continue;
        if(isCnt(ss,n))res++;
      }
    }
    cout<<"Case #"<<C<<": ";
    cout<<res<<endl;
    C++;
  }
}
