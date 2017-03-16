#include <cstdio>

//#define DEBUG

int n,m,k;
int best;

void read_input()
{
  scanf("%d %d %d",&n,&m,&k);
}

char map[100][100];

void process(int w, int h, int tl, int tr, int bl, int br)
{
  if(w*h < k)
    return;
  if(br + tr + 1 > n)
    return;

  int num = w*h;
  num -= tl*(tl+1)/2;
  num -= tr*(tr+1)/2;
  num -= bl*(bl+1)/2;
  num -= br*(br+1)/2;
#ifdef DEBUG
  printf("%d\n",num);
#endif
  if(num < k)
    return;

  int bcount = 0;
  if(tl > 0)
    bcount += tl - 1;
  if(tr > 0)
    bcount += tr - 1;
  if(bl > 0)
    bcount += bl - 1;
  if(br > 0)
    bcount += br - 1;
  bcount += w - tl - tr;
  bcount += w - bl - br;
  bcount += h - tl - bl;
  bcount += h - tr - br;
  if(bcount < best)
    best = bcount;
}

void solve(int t)
{
  read_input();
  
  int ms = m;
  if(ms > n)
    ms = n;

  best = 1000000000;
  for(int w=1; w<=m; w++)
    for(int h=1; h<=n; h++)
      for(int tl=0; tl < ms; tl++)
        for(int tr=0; tr < ms - tl; tr++)
          for(int bl=0; bl < ms - tl; bl++)
            for(int br=0; br < ms - bl; br++) {
              process(w,h,tl,tr,bl,br);
            }
  printf("Case #%d: %d\n",t+1,best);
}

main()
{
  int tt;
  scanf("%d",&tt);
  for(int i=0; i<tt; i++)
    solve(i);  
}
