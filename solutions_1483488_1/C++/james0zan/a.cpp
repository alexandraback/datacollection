#include<cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
const int N = 2000100;
vector<int> key[N];
int main() {
  int T, x, ans, a, t, i, p, s, n, j;
  for (i=1; i<N; i++) {
    char tem[30];
    sprintf(tem, "%d", i);
    for (j=1; tem[j]; j++) if (tem[j] != '0') {
      string tt = tem;
      int aa = atoi((tt.substr(j) + tt.substr(0, j)).c_str());
      if (i < aa) key[i].push_back(aa);
    }
  }
  for (i=1; i<N; i++) {
    sort(key[i].begin(), key[i].end());
    key[i].resize(unique (key[i].begin(), key[i].end()) - key[i].begin());
  }
  cout<<"here"<<endl;
  
  
  
  scanf("%d", &T);
  for  (int TC=1; TC<=T; TC++) {
    scanf("%d%d", &s, &t);
    ans = 0;
    for (i=s; i<=t; i++)
      ans += (upper_bound (key[i].begin(), key[i].end(), t) - key[i].begin());
    printf("Case #%d: %d\n", TC, ans);
  }
}
