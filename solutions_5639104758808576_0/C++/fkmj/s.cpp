#include <cstdio>

int s;
char cstr[2000];
int scount[2000];

void read_input()
{
  scanf("%d",&s);
  scanf("%s",cstr);
  for(int i=0; i<=s; i++)
    scount[i] = cstr[i] - '0';
}

void solve(int tt)
{
  read_input();
  int acount = 0;
  int ccount = 0;
  for(int i=0; i<=s; i++) {
    if(ccount >= i) {
      ccount += scount[i];
    } else {
      if(scount[i] > 0) {
        acount += (i - ccount);
        ccount = i;
        ccount += scount[i];
      }
    }
  }
  printf("Case #%d: %d\n",tt+1,acount);
}

main()
{
  int t;
  scanf("%d",&t);
  for(int i=0; i<t; i++) {
    solve(i);
  }
}
