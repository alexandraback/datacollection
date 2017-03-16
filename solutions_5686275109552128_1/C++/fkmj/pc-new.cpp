#include <cstdio>

int d;
int p[10000];

void read_input()
{
  scanf("%d",&d);
  for(int i=0; i<d; i++)
    scanf("%d",&p[i]);
}

void solve(int tt)
{
  read_input();
  int pmax = 0;
  int best;
  for(int i=0; i<d; i++)
    if(p[i] > pmax)
      pmax = p[i];
  best = pmax;
  for(int i=1; i<pmax; i++) {
    int added = 0;
    for(int j=0; j<d; j++)
      if(p[j] > i) {
        added += ((p[j] + i - 1) / i) - 1;
      }
    if(added + i < best)
      best = added + i;
  }
  
  printf("Case #%d: %d\n",tt+1,best);
}

main()
{
  int t;
  scanf("%d",&t);
  for(int i=0; i<t; i++) {
    solve(i);
  }
}
