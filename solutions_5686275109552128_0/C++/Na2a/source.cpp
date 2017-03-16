#include <bits/stdc++.h>

using namespace std;

typedef vector<int> big;

const int MAXN = (int) 2e3 + 7;
const int INF = (int) 1e9 + 7;

int t, n;
map<vector<int>, int> u;

vector<int> a;

int ans;

void go(int len) {
  if(len>=ans)return;
  int mx = max_element(a.begin(),a.end())-a.begin();
  ans=min(ans, a[mx] + len);
  if(a[mx] <= 0)
    return;

  for(int i=0;i<a.size();i++)--a[i];
  go(len+1);
  for(int i=0;i<a.size();i++)++a[i];
  
  int p=mx;
  int x=a[p];
  for(int j=1;j<x;j++){
    a[p]=j;
    a.push_back(x-j);
    go(len+1);
    a.pop_back();
    a[p]=x;
  }
  /*for(int i=0;i<a.size();i++){
    if(a[i]>0&&i!=p){
      for(int j=1;j<x;j++){
        a[p]=j,a[i]+=x-j;
        go(len+1);
        a[p]=x,a[i]-=x-j;
      }
    }
  a[p]=x;
  }*/
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("outSlow", "w", stdout);
  #endif

  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    scanf("%d", &n);
    a.resize(n);
    ans=0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      ans=max(ans,a[i]);
    }
    go(0);
    u.clear();
    printf("Case #%d: %d\n", cases, ans);
  }
  //cout<<"ok";
  return 0;
}