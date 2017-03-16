#include <cstdio>
#include <vector>

using namespace std;

#define MAX_D 211

int N, K;
int keys[MAX_D][2*MAX_D];
int need[MAX_D];
int init[2*MAX_D];


// brute
int next[1<<20];
char ok[1<<20];

char rec(int mask) {
  if (ok[mask] >= 0)
    return ok[mask];
  
  if (mask == (1<<N) - 1)
    return (ok[mask] = 1);
  
  for (int i = 0; i < N; ++i) {
    if (!(mask >> i & 1)) {
      
      int so_far = 0;
      for (int k = 0; k < N; ++k)
        if (mask >> k & 1)
          so_far += keys[k+1][need[i+1]];
      
      so_far += init[need[i+1]];
      
      if (so_far >= 1) {
        //printf("mask %d -> %d\n", mask, i);
        
        if (rec(mask + (1<<i))) {
          next[mask] = i;
          return ok[mask] = 1;
        }
      }
    }
  }
  
  return ok[mask] = 0;
}

vector<int> brute() {
  vector<int> res;
/*
  for (int i = 0; i < N; ++i)
    printf("%d ", need[i + 1]);
  printf("\n");
*/
  memset(ok, -1, sizeof(ok));
  memset(next, -1, sizeof(next));
  
  if (rec(0)) {
    for (int mask = 0; mask != (1<<N) - 1; mask += (1<<next[mask])) {
      res.push_back(next[mask] + 1);
    }
  }
  
  return res;
}

void smart() {
  
}

int main() {
  int T, val, nr;
  vector<int> res;
  
  scanf("%d", &T);
  
  for (int i = 1; i <= T; ++i) {
    memset(init, 0, sizeof(init));
    memset(keys, 0, sizeof(keys));
    memset(need, 0, sizeof(need));
    
    scanf("%d %d", &K, &N);
    for (int j = 0; j < K; ++j) {
      scanf("%d", &val);
      init[val]++;
    }
    
    for (int j = 1; j <= N; ++j) {
      scanf("%d %d", &need[j], &nr);
      for (int k = 0; k < nr; ++k) {
        scanf("%d", &val);
        keys[j][val]++;
      }
      keys[j][need[j]]--;
    }
    
    res = brute();
    printf("Case #%d: ", i);
    if (res.size() == 0) {
      printf("IMPOSSIBLE\n");
    } else {
      printf("%d", res[0]);
      for (int j = 1; j < res.size(); ++j)
        printf(" %d", res[j]);
      printf("\n");
    }
    
  }
  
}