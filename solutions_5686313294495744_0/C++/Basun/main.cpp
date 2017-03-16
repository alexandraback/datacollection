#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[1010][1010];
char s[1010][2][22];
long long m;
int n;
int main()
{
  int i,j,bj1,bj2,cnt;
  FILE *in = fopen("/Users/Basun/Desktop/test.txt","r");
  FILE *out = fopen("/Users/Basun/Desktop/c.txt", "w");
  int T,t;
  fscanf(in, "%d",&T);
  for(t=0;t<T;t++)
  {
    cnt=0;
    memset(a, 0, sizeof(a));
    fscanf(in, "%d", &n);
    for(i=0;i<n;i++)
    {
      fscanf(in, "%s%s",s[i][0],s[i][1]);
      for(j=0;j<i;j++)
      {
        if(strcmp(s[j][0],s[i][0]) == 0)
          a[i][j] = 1;
        if(strcmp(s[j][1],s[i][1]) == 0)
          a[i][j] = 2;
      }
    }
    for(i=0;i<n;i++)
    {
      bj1=0;
      bj2=0;
      for(j=0;j<n;j++)
      {
        if(a[i][j]==1)
          bj1=1;
        if(a[i][j]==2)
          bj2=1;
      }
      if(bj1&&bj2)
        cnt++;
    }
    fprintf(out, "Case #%d: ",t+1);
    fprintf(out, "%d",cnt);
    fprintf(out, "\n");
    cout<<t+1<<endl;
  }
  return 0;
}
