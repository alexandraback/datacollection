#include <cstdio>

#define MAX_N 20

int a[MAX_N],b[MAX_N];
int ac, bc;
int at, bt;
int x[MAX_N];
int n;
int tt;
bool found;

void print_sol()
{
  printf("Case #%d:\n",tt);
  for(int i=0; i<ac; i++)
    printf("%d ",a[i]);
  printf("\n");
  for(int i=0; i<bc; i++)
    printf("%d ",b[i]);
  printf("\n");
}

void tryit(int i)
{
  if(i==n)
    return;
  if((at == bt) && (at!=0)) {
    found = true;
    print_sol();
    return;
  }

  a[ac] = x[i];
  ac++;
  at += x[i];
  tryit(i+1);
  ac--;
  at -= x[i];
  if(found)
    return;

  b[bc] = x[i];
  bc++;
  bt += x[i];
  tryit(i+1);
  bc--;
  bt -= x[i];
  if(found)
    return;

  tryit(i+1);
}

void solve()
{
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d",&x[i]);
  ac = bc = 0;
  at = bt = 0;
  found = false;
  tryit(0);
}

main()
{
  int t;
  scanf("%d",&t);
  for(tt=1; tt<=t; tt++)
    solve();
}
