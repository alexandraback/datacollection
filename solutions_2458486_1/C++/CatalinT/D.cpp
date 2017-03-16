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

char tmp[2*MAX_D];
int tmp_key[2*MAX_D];
int of_type[MAX_D];

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

  memset(ok, -1, sizeof(ok));
  memset(next, -1, sizeof(next));
  
  if (rec(0)) {
    for (int mask = 0; mask != (1<<N) - 1; mask += (1<<next[mask])) {
      res.push_back(next[mask] + 1);
      //res.push_back(need[next[mask] + 1]);
    }
  }
  
  return res;
}

int df(int chest, int ini_chest) {
  int val = 0;
  tmp[chest] = 1;
  
  if (keys[chest][need[ini_chest]] + (need[chest] == need[ini_chest]) > 0)    return 1;
  
  if (chest == ini_chest) {
    for (int i = 1; i <= N; ++i) {
      if (!tmp[i] && tmp_key[need[i]] > 0) {
        val = df(i, ini_chest);
        if (val) return 1;
      }
    }
  }
  
  for (int i = 1; i <= N; ++i)
    if (!tmp[i] && keys[chest][need[i]] > 0) {
      val = df(i, ini_chest);
      if (val) return 1;
    }
  
  return 0;
}

int can_use(int chest) {
  if (of_type[need[chest]] == 1 || init[need[chest]] > 1)
    return 1;
  
  if (init[need[chest]] == 0)
    return 0;
  
  // doesn't consume key
  if (keys[chest][need[chest]] >= 0)
    return 1;
  
  //printf("doing df for chest: %d\n", chest);
  
  for (int i = 1; i < MAX_D; ++i)
    tmp_key[i] = init[i];
  for (int i = 1; i <= N; ++i)
    tmp[i] = ok[i];
  
  tmp_key[need[chest]]--;
  
  return df(chest, chest);
  
  //return 0;
}

vector<int> smart() {
  vector<int> res;
  
  memset(ok, 0, sizeof(ok));
/*
  for (int j = 1; j < MAX_D; ++j)
    if (init[j] > 0)
      printf("(%d, %d) ", j, init[j]);
  printf("\n");
*/
  for (int step = 0; step < N; ++step) {
    bool found = false;
    
    for (int i = 1; !found && i <= N; ++i) {
      if (!ok[i] && init[need[i]] >= 1 && can_use(i)) {
        //        printf("can use %d\n", i);
        
        res.push_back(i);
        
        for (int j = 1; j < MAX_D; ++j)
          init[j] += keys[i][j];
        ok[i] = 1;
        of_type[need[i]]--;
        /*
        for (int j = 1; j < MAX_D; ++j)
          if (init[j] > 0)
            printf("(%d, %d) ", j, init[j]);
        printf("\n");
        */
        found = true;
      }
    }
    
    if (!found) {
      res.clear();
      break;
    }
  }
  
  return res;
}

int main() {
  int T, val, nr;
  vector<int> res;
  
  scanf("%d", &T);
  
  for (int i = 1; i <= T; ++i) {
    memset(init, 0, sizeof(init));
    memset(keys, 0, sizeof(keys));
    memset(need, 0, sizeof(need));
    memset(of_type, 0, sizeof(of_type));
    
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
      
      of_type[need[j]]++;
    }
    
    //res = brute();
    res = smart();
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