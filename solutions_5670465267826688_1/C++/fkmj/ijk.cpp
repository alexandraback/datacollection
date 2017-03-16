#include <cstdio>
#include <cstdlib>

#define I 2
#define J 3
#define K 4

int l;
long long x;
char st[20000];
int v[20000];

int rmap[4][4] = {{1,2,3,4},
                  {2,-1,4,-3},
                  {3,-4,-1,2},
                  {4,3,-2,-1}};

int mult(int a, int b)
{
  int ua = abs(a);
  int ub = abs(b);

  int r = rmap[ua-1][ub-1];
  if(a*b > 0)
    return r;
  else
    return -r;
}

void read_input()
{
  scanf("%d %lld",&l,&x);
  if(x > 12) {
    x = 12 + (x - 12)%12;
  }
  scanf("%s",st);
  for(int i=0; i<l; i++) {
    switch(st[i]) {
    case 'i':
      v[i] = I;
      break;
    case 'j':
      v[i] = J;
      break;
    case 'k':
      v[i] = K;
      break;
    }
  }
}

void solve(int tt)
{
  read_input();
  int res = 1;
  int state = 0;
  
  for(long long i=0; i<x; i++)
    for(int j=0; j<l; j++) {
      res = mult(res,v[j]);
      //printf("%d\n",res);
      if((state == 0) && (res == I)) {
        state = 1;
      } else if((state == 1) && (res == K)) {
        state = 2;
      }
    }
  if((state == 2) && (res == -1))
    printf("Case #%d: YES\n",tt+1);
  else
    printf("Case #%d: NO\n",tt+1);
}

main()
{
  int t;
  scanf("%d",&t);
  for(int i=0; i<t; i++) {
    solve(i);
  }
}
