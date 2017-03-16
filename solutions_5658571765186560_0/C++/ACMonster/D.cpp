//program D

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
      int k=get(),n=get(),m=get();
      if(n>m)
        swap(n,m);
      printf("Case #%d: ",test);
      if(k==1)
        printf("GABRIEL\n");
      else if(k==2)
        printf((n*m%2)?"RICHARD\n":"GABRIEL\n");
      else if(n*m%k||(n<k&&m<k))
        printf("RICHARD\n");
      else if(k==3&&n==1&&m==3)
        printf("RICHARD\n");
      else if(k==4&&n==1&&m==4)
        printf("RICHARD\n");
      else if(k==4&&n==2&&m==4)
        printf("RICHARD\n");
      else
        printf("GABRIEL\n");
    }
  return 0;
}
