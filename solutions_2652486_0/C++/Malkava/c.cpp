#include <cstdio>
#include <map>

using namespace std;

int T, R, N, M, K;


int digs[4];
int ks[10];

map<int, bool> prods;

bool go(int idx)
{
  if(idx == N)
  {
    int qt = 0;
    for(int s = 0; s < (1<<N); s++)
    {
      int p = 1;
      for(int i = 0; i < N; i++)
      {
        if(s & (1<<i)) p *= digs[i];
      }
      
      if(prods.find(p) != prods.end())
      {
        if(!prods[p])
        {
          prods[p] = true;
          qt++;
        }
      }

    }

    if(qt == prods.size()) return true;
    for(int i = 0; i < K; i++) prods[ks[i]] = false;
    return false;
  }

  for(int i = 2; i <= M; i++)
  {
    digs[idx] = i;
    if(go(idx+1)) return true;
  }
  return false;
}

int main(void)
{
  scanf("%d\n", &T);

  scanf("%d %d %d %d\n", &R, &N, &M, &K);

  printf("Case #1:\n");
  for(int cas = 0; cas < R; cas++)
  {
    prods = map<int, bool>();
    for(int i = 0; i < K; i++)
    {
      int k;
      scanf("%d", &k);
      prods[k] = false;
      ks[i] = k;
    }
    go(0);
    for(int i = 0; i < N; i++)
    {
      printf("%d", digs[i]);
    }
    printf("\n");
  }
  return 0;

}

