#include <iostream>
#include <stdio.h>
int   bbf[2000];
int chain[2000];
int  twin[2000];
int  flag[2000];
int main() {
  FILE *in = fopen("/Users/Basun/Downloads/C-large.in.txt","r");
  FILE *out = fopen("/Users/Basun/Desktop/ansc-large.txt", "w");
  int t,T,n,i,p,pp,max,cnt,ccc;
  fscanf(in,"%d",&T);
  for(t=1;t<=T;t++) {
    memset(bbf, 0, sizeof(bbf));
    memset(flag, 0, sizeof(flag));
    memset(chain, 0, sizeof(chain));
    memset(twin, 0, sizeof(twin));
    max=0;
    ccc=0;
    fscanf(in,"%d",&n);
    for(i=1;i<=n;i++)
      fscanf(in,"%d",&bbf[i]);
    for(i=1;i<=n;i++) {
      memset(flag, 0, sizeof(flag));
      pp = p = i;
      cnt=0;
      while (!flag[p]) {
        pp = p;
        flag[p]=1;
        p = bbf[p];
        cnt++;
      }
      if(bbf[p]==pp) {
        if (cnt==2) {
          if(p<pp)
            twin[p]=pp;
        }
        else {
          chain[p] = chain[p]>(cnt-2)?chain[p]:(cnt-2);
        }
      }
      else if(p==i)
        max = max>cnt?max:cnt;
    }
    for (i=1; i<=n; i++) {
      if(twin[i]!=0)
        ccc += (chain[i]+chain[twin[i]]+2);
        //max = max>(chain[i]+chain[twin[i]]+2)?max:(chain[i]+chain[twin[i]]+2);
    }
    max = max>ccc?max:ccc;
    fprintf(out,"Case #%d: %d\n",t,max);
  }
  return 0;
}
