#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 10000

void solve(){
  char s[SIZE];
  int cc[256] = {};
  string ans;
  
  scanf("%s",s);

  for(int i=0;s[i]!='\0';i++){
    cc[s[i]]++;
  }

  while(1){
    if(cc['Z'] > 0){
      for(int i=0;i<4;i++) cc["ZERO"[i]]--;
      ans += "0";
      continue;
    }

    if(cc['W'] > 0){
      for(int i=0;i<3;i++) cc["TWO"[i]]--;
      ans += "2";
      continue;
    }

    if(cc['G'] > 0){
      for(int i=0;i<5;i++) cc["EIGHT"[i]]--;
      ans += "8";
      continue;
    }

    if(cc['X'] > 0){
      for(int i=0;i<3;i++) cc["SIX"[i]]--;
      ans += "6";
      continue;
    }

    if(cc['H'] > 0){
      for(int i=0;i<5;i++) cc["THREE"[i]]--;
      ans += "3";
      continue;
    }

    if(cc['R'] > 0){
      for(int i=0;i<4;i++) cc["FOUR"[i]]--;
      ans += "4";
      continue;
    }

    if(cc['F'] > 0){
      for(int i=0;i<4;i++) cc["FIVE"[i]]--;
      ans += "5";
      continue;
    }

    if(cc['V'] > 0){
      for(int i=0;i<5;i++) cc["SEVEN"[i]]--;
      ans += "7";
      continue;
    }

    if(cc['I'] > 0){
      for(int i=0;i<5;i++) cc["NINE"[i]]--;
      ans += "9";
      continue;
    }

    if(cc['O'] > 0){
      for(int i=0;i<5;i++) cc["ONE"[i]]--;
      ans += "1";
      continue;
    }

    break;
  }

  sort(ans.begin(),ans.end());

  cout << ans << endl;
}


int main(){
  int T;

  scanf("%d",&T);

  for(int i=1;i<=T;i++){

    printf("Case #%d: ",i);

    solve();
  }
  
  return 0;
}
