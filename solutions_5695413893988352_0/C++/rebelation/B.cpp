#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <cmath>
#include <algorithm>

#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

bool can(string s, int val){
  int n = s.size();
  for(int i = n-1; i >= 0; i--){
    if(s[i] != '?' && s[i] - '0' != val % 10)return false;
    val /= 10;
  }
  return true;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for(int o = 1; o <= T; o++){
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int limit = 1;
    for(int i = 0; i < n; i++)limit *= 10;
    int cv = 0, jv = limit*10-1;
    for(int i = 0; i < limit; i++)
      if(can(a, i))
        for(int j = 0; j < limit; j++)
          if(can(b, j)){
            int cd = abs(cv - jv);
            int d = abs(i - j);
            if(cd > d || (cd == d && cv > i) || (cd == d && cv == i && jv > j)){
              cv = i; jv = j;
            }
          }
    string ansa = "" + to_string(cv);
    string ansb = "" + to_string(jv);
    while(ansa.size() < a.size())ansa = "0" + ansa;
    while(ansb.size() < b.size())ansb = "0" + ansb;
    printf("Case #%d: %s %s\n", o, ansa.c_str(), ansb.c_str());
  }

  return 0;
}
