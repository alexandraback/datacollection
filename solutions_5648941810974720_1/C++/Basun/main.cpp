#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int h[26];
int d[10];
char s[2010];
int main()
{
  int i,j;
  int l;
  FILE *in = fopen("/Users/Basun/Desktop/test.txt","r");
  FILE *out = fopen("/Users/Basun/Desktop/a.txt", "w");
  int T,t;
  fscanf(in, "%d",&T);
  for(t=0;t<T;t++)
  {
    memset(h, 0, sizeof(h));
    memset(d, 0, sizeof(d));
    fscanf(in, "%s", s);
    l = (int)strlen(s);
    for(i=0;i<l;i++)
      h[s[i]-'A']++;
    d[0] = h['Z'-'A'];
    h['Z'-'A'] -= d[0];
    h['E'-'A'] -= d[0];
    h['R'-'A'] -= d[0];
    h['O'-'A'] -= d[0];
    
    d[2] = h['W'-'A'];
    h['T'-'A'] -= d[2];
    h['W'-'A'] -= d[2];
    h['O'-'A'] -= d[2];
    
    d[4] = h['U'-'A'];
    h['F'-'A'] -= d[4];
    h['O'-'A'] -= d[4];
    h['U'-'A'] -= d[4];
    h['R'-'A'] -= d[4];
    
    d[6] = h['X'-'A'];
    h['S'-'A'] -= d[6];
    h['I'-'A'] -= d[6];
    h['X'-'A'] -= d[6];

    d[8] = h['G'-'A'];
    h['E'-'A'] -= d[8];
    h['I'-'A'] -= d[8];
    h['G'-'A'] -= d[8];
    h['H'-'A'] -= d[8];
    h['T'-'A'] -= d[8];
    
    d[5] = h['F'-'A'];
    h['F'-'A'] -= d[5];
    h['I'-'A'] -= d[5];
    h['V'-'A'] -= d[5];
    h['E'-'A'] -= d[5];

    d[7] = h['V'-'A'];
    h['S'-'A'] -= d[7];
    h['E'-'A'] -= d[7];
    h['V'-'A'] -= d[7];
    h['E'-'A'] -= d[7];
    h['N'-'A'] -= d[7];

    d[3] = h['R'-'A'];
    h['T'-'A'] -= d[3];
    h['H'-'A'] -= d[3];
    h['R'-'A'] -= d[3];
    h['E'-'A'] -= d[3];
    h['E'-'A'] -= d[3];

    d[1] = h['O'-'A'];
    h['O'-'A'] -= d[1];
    h['N'-'A'] -= d[1];
    h['E'-'A'] -= d[1];
    
    d[9] = h['E'-'A'];
    
    fprintf(out, "Case #%d: ",t+1);
    for (i=0; i<10; i++) {
      for(j=0;j<d[i];j++)
        fprintf(out, "%d", i);
    }
    fprintf(out, "\n");
  }
  return 0;
}
