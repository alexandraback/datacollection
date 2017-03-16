#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <utility>

using namespace std;

void search(vector<int> acts, int e, int r, int eng, int i, int got, int& max) {
  for(int spend = 0; spend <= eng; ++spend) {
    int got_now = got + spend*acts[i];
    if (i == acts.size()-1) {
      if (got_now > max) {
	max = got_now;
      }
    } else {
      search(acts, e, r, min(e, eng-spend+r), i+1, got_now, max);
    }
  }
}

void make(){
  int e, r, n;
  scanf("%d%d%d", &e, &r, &n);
  vector<int> acts(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &acts[i]);
  }
  int max = 0;
  search(acts, e, r, e, 0, 0, max);
  printf("%d\n", max);
}

int main(){
  freopen("B-small-attempt1.in", "r", stdin);
  freopen("B-small1.out", "w", stdout);
  
  int test_n;
  scanf("%d", &test_n);
  for (int test_i = 1; test_i <= test_n; ++test_i) {
    printf("Case #%d: ", test_i);
    make();
  }
  return 0;
}
