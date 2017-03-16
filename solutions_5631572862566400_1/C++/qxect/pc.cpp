#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<cmath>

#include<algorithm>
#include<bitset>
#include<complex>
#include<deque>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<vector>
using namespace std;

int use[2000], bff[2000];
vector<int> E[2000];
int lv;

int dfs(int now, int myLv){
  use[now] = 1;
  lv = max(lv, myLv);
  for(int i=0; i < int(E[now].size()); i++){
    if(!use[E[now][i]])
      dfs(E[now][i], myLv+1);
  }

  return 0;
}
int main()
{
  int tn;
  int z, i,j, now;
  int ans, ans2;
  int n;
  vector<int> arr;
  cin >> tn;
  for (z = 1; z <= tn ; z++) {
    ans = 1;
    cin >> n;
    for(i=0; i<n; i++) E[i].clear();
    for(i=0; i<n; i++){
      scanf("%d", &bff[i]), bff[i]--;
      E[bff[i]].push_back(i);
    }

    /* Single Circle */
    for(i=0; i<n; i++){
      memset(use, 0, sizeof(use));
      use[i] = 1;
      for(j = 2, now = bff[i]; !use[now]; j++, now = bff[now])
        use[now] = j;
      //printf("j %d - use[now] %d: %d\n", j, use[now], j - use[now]);
      ans = max(ans, j - use[now]);
    }
    arr.clear();
    for(i=0; i<n; i++)
      for(j=0; j<n; j++){
        if(i==j) continue;
        if(bff[i] == j && bff[j] == i){
          arr.push_back(i);
          arr.push_back(j);
        }
      }
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    ans2 = 0;
    for(i=0; i < int(arr.size()); i++){
      memset(use,0,sizeof(use));
      for(j=0; j < int(arr.size()); j++) use[arr[j]] = 1;
      lv = 0;
      dfs(arr[i], 1);
      ans2 += lv;
      //printf("arr %d lv %d\n", arr[i], lv);
    }
    printf("Case #%d: %d\n", z, max(ans, ans2));
  }
  return 0;
}
