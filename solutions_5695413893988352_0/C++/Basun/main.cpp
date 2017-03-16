#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int h[26];
int d[10];
char C[21];
char J[21];
int l;
char tCC[21];
char tJJ[21];
char CC[21];
char JJ[21];
long long cc;
long long jj;
long long tc;
long long tj;
long long m;
long long labs(long long x)
{
  return x>0?x:((-1)*x);
}
void test(int p)
{
  int i;
  long long tm;
  if(p==l)
  {
    tc=0;
    tj=0;
    for(i=0;i<l;i++)
    {
      tc=tc*10+(tCC[i]-'0');
      tj=tj*10+(tJJ[i]-'0');
    }
    if(m==-1)
    {
      m = labs(tc-tj);
      for(i=0;i<l;i++)
      {
        CC[i] = tCC[i];
        JJ[i] = tJJ[i];
      }
      CC[i]='\0';
      JJ[i]='\0';
      cc=tc;
      jj=tj;
    }
    else
    {
      tm =labs(tc-tj);
      if(tm < m)
      {
        m = tm;
        for(i=0;i<l;i++)
        {
          CC[i] = tCC[i];
          JJ[i] = tJJ[i];
        }
        CC[i]='\0';
        JJ[i]='\0';
        cc=tc;
        jj=tj;
      }
      else if(tm == m)
      {
        if(tc < cc)
        {
          m = tm;
          for(i=0;i<l;i++)
          {
            CC[i] = tCC[i];
            JJ[i] = tJJ[i];
          }
          CC[i]='\0';
          JJ[i]='\0';
          cc=tc;
          jj=tj;

        }
        else if(tc == cc && tj < jj)
        {
          m = tm;
          for(i=0;i<l;i++)
          {
            CC[i] = tCC[i];
            JJ[i] = tJJ[i];
          }
          CC[i]='\0';
          JJ[i]='\0';
          cc=tc;
          jj=tj;
        }
      }
    }
  }
  else
  {
    if(C[p]=='?' && J[p]=='?')
    {
      tCC[p]='0';
      tJJ[p]='0';
      test(p+1);
      tCC[p]='1';
      tJJ[p]='0';
      test(p+1);
      tCC[p]='0';
      tJJ[p]='1';
      test(p+1);
      tCC[p]='0';
      tJJ[p]='9';
      test(p+1);
      tCC[p]='9';
      tJJ[p]='0';
      test(p+1);
    }
    else if(C[p]=='?' && J[p] !='?')
    {
      tCC[p]=J[p];
      tJJ[p]=J[p];
      test(p+1);
      if(J[p]!='0')
      {
        tCC[p]=J[p]-1;
        tJJ[p]=J[p];
        test(p+1);
      }
      if(J[p]!='9')
      {
        tCC[p]=J[p]+1;
        tJJ[p]=J[p];
        test(p+1);
      }
      tCC[p]='9';
      tJJ[p]=J[p];
      test(p+1);
      tCC[p]='0';
      tJJ[p]=J[p];
      test(p+1);
    }
    else if(C[p]!='?' && J[p] =='?')
    {
      tCC[p]=C[p];
      tJJ[p]=C[p];
      test(p+1);
      if(C[p]!='0')
      {
        tCC[p]=C[p];
        tJJ[p]=C[p]-1;
        test(p+1);
      }
      if(C[p]!='9')
      {
        tCC[p]=C[p];
        tJJ[p]=C[p]+1;
        test(p+1);
      }
      tCC[p]=C[p];
      tJJ[p]='9';
      test(p+1);
      tCC[p]=C[p];
      tJJ[p]='0';
      test(p+1);
    }
    else
    {
      tCC[p]=C[p];
      tJJ[p]=J[p];
      test(p+1);
    }
  }
}
int main()
{
  FILE *in = fopen("/Users/Basun/Desktop/test.txt","r");
  FILE *out = fopen("/Users/Basun/Desktop/b.txt", "w");
  int T,t;
  fscanf(in, "%d",&T);
  for(t=0;t<T;t++)
  {
    m = -1;
    fscanf(in, "%s%s",C,J);
    memset(CC, 0, sizeof(CC));
    memset(JJ, 0, sizeof(JJ));
    cc=0;
    jj=0;
    l=(int)strlen(C);
    
    test(0);
    
    fprintf(out, "Case #%d: ",t+1);
    fprintf(out, "%s %s",CC,JJ);
    fprintf(out, "\n");
  }
  return 0;
}
