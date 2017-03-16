#include <cstring>
#include <cstdio>

int K,N;
int kn[200], ks[200][200];
int key[200];
int maxkey;
int sol[200];
int opened[200];
int cur[201];
int usen[201], use[201][200];
int reachable[200], usedkey[201];
int need[201];

void findreachable(int k) {
  usedkey[k] = 1;
  for (int i = 0; i < usen[k]; ++i) {
    int box = use[k][i];
    if (!opened[box] && !reachable[box]) {
      reachable[box] = 1;
      for (int j = 0; j < kn[box]; ++j) {
        int kk = ks[box][j];
        if (!usedkey[kk])
          findreachable(kk);
      }
    }
  }
}

bool search(int soli) {
  if (soli==N)
    return true;
  memset(reachable,0,sizeof(reachable));
  memset(usedkey,0,sizeof(usedkey));
  for (int i = 1; i <= maxkey; ++i)
    if (cur[i] && !usedkey[i])
      findreachable(i);
  for (int i = 0; i < N; ++i)
    if (!opened[i] && !reachable[i])
      return false;
  memset(need,0,sizeof(need));
  for (int i = 0; i < N; ++i) {
    if (!opened[i]) {
      ++need[key[i]];
      for (int j = 0; j < kn[i]; ++j)
        --need[ks[i][j]];
    }
  }
  for (int i = 1; i <= maxkey; ++i)
    if (need[i] > cur[i])
      return false;

  for (int i = 0; i < N; ++i)
    if (!opened[i] && cur[key[i]]>0) {
      opened[i] = 1;
      --cur[key[i]];
      for (int j = 0; j < kn[i]; ++j)
        ++cur[ks[i][j]];
      sol[soli] = i;
      if (search(soli+1))
        return true;
      for (int j = 0; j < kn[i]; ++j)
        --cur[ks[i][j]];
      ++cur[key[i]];
      opened[i] = 0;
    }
  return false;

}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    maxkey = 0;
    scanf("%d%d", &K, &N);
    memset(opened,0,sizeof(opened));
    memset(cur,0,sizeof(cur));
    memset(usen,0,sizeof(usen));
    memset(use,0,sizeof(use));
    for (int i = 0; i < K; ++i) {
      int k;
      scanf("%d",&k);
      ++cur[k];
      if (k>maxkey)
        maxkey = k;
    }
    for (int i = 0; i < N; ++i) {
      scanf("%d%d", &key[i], &kn[i]);
      use[key[i]][usen[key[i]]++] = i;
      for (int j = 0; j < kn[i]; ++j) {
        scanf("%d", &ks[i][j]);
        if (ks[i][j]>maxkey)
          maxkey = ks[i][j];
      }
    }

    printf("Case #%d:", t);
    if (search(0)) {
      for (int i = 0; i < N; ++i)
        printf(" %d", sol[i]+1);
    }
    else
      printf(" IMPOSSIBLE");
    printf("\n");
  }
  return 0; 
}

