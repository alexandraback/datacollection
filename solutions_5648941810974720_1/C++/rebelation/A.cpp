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

int calc(vector<int>& f, string s){
  int n = s.size();
  map<char, int> g;
  for(int i = 0; i < n; i++)g[s[i]]++;
  int mx = 1<<20;
  for(int i = 0; i < n; i++)mx = min(mx, f[s[i] - 'A'] / g[s[i]]);
  for(int i = 0; i < n; i++)f[s[i] - 'A'] -= mx;
  return mx;
}

string dic[10] = {"ZERO", "TWO", "FOUR", "SIX", "EIGHT", "ONE", "THREE", "FIVE", "SEVEN", "NINE" };
int v[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for(int o = 1; o <= T; o++){
    printf("Case #%d: ", o);
    string s;
    cin >> s;
    vector<int> f(26, 0);
    int n = s.size();
    for(int i = 0; i < n; i++)f[s[i] - 'A']++;
    vector<int> ans(10, 0);
    for(int t = 0; t < 5; t++){
      for(int i = 0; i < 10; i++)ans[v[i]] += calc(f, dic[i]);
      int rest = 0; for(int i = 0; i < f.size(); i++)rest += f[i];// if(rest > 0)printf("ERROR");
      if(rest == 0)break;
      printf("rest=%d\n", rest);
    }
    for(int i = 0; i < 10; i++)for(int j = 0; j < ans[i]; j++)printf("%d", i);
    printf("\n");
  }

  return 0;
}
