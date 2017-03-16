#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#define INF 100000000
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
  int numTC, TC = 1, D, ans, arr[1000], lo, hi, mid, idx, temp;
  vii v;
  scanf("%d", &numTC);
  while(numTC--){
    scanf("%d", &D); v.clear();
    for(int i=0; i<D; i++) scanf("%d", &arr[i]); sort(arr, arr+D);
    ii cur = ii(arr[0], 1);
    for(int i=1; i<D; i++){
      if(arr[i]==cur.first) cur.second++;
      else{ v.push_back(cur); cur = ii(arr[i], 1); }
    }
    v.push_back(cur); D = v.size(); ans = cur.first; lo = 1; hi = cur.first;
    for(int i=1; i<cur.first; i++){
      temp = i; idx = lower_bound(v.begin(), v.end(), ii(i, 1))-v.begin();
      if(v[idx].first==i) idx++;
      for(; idx<D; idx++) temp+=(v[idx].first-1)/i*v[idx].second;
      //printf("%d %d\n", i, temp);
      ans = min(ans, temp);
    }
    printf("Case #%d: %d\n", TC++, ans);
  }
  return 0;
}
