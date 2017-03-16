//program B

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

int main()
{
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      char c;
      while(c=getchar(),c!='+'&&c!='-');
      int first=0,n=0,last=0;
      while(c=='+'||c=='-')
        {
          int x=(c=='+')?1:-1;
          if(!first)
            first=x;
          if(x!=last)
            {
              last=x;
              n++;
            }
          c=getchar();
        }
      int ans;
      if(first==1)
        ans=n/2*2;
      else
        ans=(n-1)/2*2+1;
      printf("Case #%d: %d\n",test,ans);
    }
  return 0;
}
