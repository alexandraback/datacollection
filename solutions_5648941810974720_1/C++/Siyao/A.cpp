#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char tmp[3000];
int c[30];
int ans[10];

void deal()
{
  int i;
  int len;
  for(i=0;i<10;++i) ans[i]=0;
  for(i=0;i<30;++i) c[i]=0;
  len=strlen(tmp);
  for(i=0;i<len;++i) ++c[tmp[i]-'A'];

  while(c['Z'-'A']!=0)
  {
      ++ans[0];
      --c['Z'-'A'];
      --c['E'-'A'];
       --c['R'-'A'];
       --c['O'-'A'];
  }
   while(c['W'-'A']!=0)
  {
      ++ans[2];
      --c['T'-'A'];
      --c['W'-'A'];
      --c['O'-'A'];
  }
    while(c['U'-'A']!=0)
  {
      ++ans[4];
      --c['F'-'A'];
      --c['U'-'A'];
      --c['O'-'A'];
      --c['R'-'A'];
  }
   while(c['X'-'A']!=0)
  {
      ++ans[6];
      --c['S'-'A'];
      --c['I'-'A'];
      --c['X'-'A'];
  }
   while(c['G'-'A']!=0)
  {
      ++ans[8];
      --c['E'-'A'];
      --c['I'-'A'];
      --c['G'-'A'];
       --c['H'-'A'];
        --c['T'-'A'];
  }
  while(c['F'-'A']!=0)
  {
      ++ans[5];
      --c['F'-'A'];
      --c['I'-'A'];
      --c['V'-'A'];
       --c['E'-'A'];
  }
   while(c['S'-'A']!=0)
  {
      ++ans[7];
      --c['S'-'A'];
      --c['E'-'A'];
      --c['V'-'A'];
       --c['E'-'A'];
         --c['N'-'A'];
  }

     while(c['O'-'A']!=0)
  {
      ++ans[1];
      --c['O'-'A'];
      --c['N'-'A'];
      --c['E'-'A'];

  }
  while(c['H'-'A']!=0)
  {
      ++ans[3];
      --c['T'-'A'];
      --c['H'-'A'];
      --c['R'-'A'];
       --c['E'-'A'];
        --c['E'-'A'];

  }
   while(c['E'-'A']!=0)
  {
      ++ans[9];
      --c['N'-'A'];
      --c['I'-'A'];
      --c['N'-'A'];
       --c['E'-'A'];
  }
}

int main()
{
  int  T;
  scanf("%d",&T);
  for(int i=1;i<=T;++i)
  {
    printf("Case #%d: ", i);
    scanf("%s",tmp);
    deal();
    for(int j=0;j<10;++j)
      {
	while(ans[j]--) printf("%d",j);
      }
    printf("\n");
  
  }
  //printf("%d\n",maxt);
  return 0;
}
