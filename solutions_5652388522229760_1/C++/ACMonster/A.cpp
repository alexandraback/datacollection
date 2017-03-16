//program A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<bitset>
#include<ctime>

using namespace std;

int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}

void output(int x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[10];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

const int maxn=1000000;

int ans[maxn+1];

int main()
{
  for(int i=0;i<=maxn;i++)
    {
      ans[i]=-1;
      int mask=0,s=0;
      for(int j=1;j<=100;j++)
        {
          s+=i;
          int t=s;
          while(t)
            {
              mask|=1<<(t%10);
              t/=10;
            }
          if(mask==1023)
            {
              ans[i]=j;
              break;
            }
        }
    }
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      int n=get();
      printf("Case #%d: ",test);
      if(ans[n]==-1)
        printf("INSOMNIA\n");
      else
        printf("%d\n",ans[n]*n);
    }
  return 0;
}
