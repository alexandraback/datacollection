//program B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

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
  freopen("B.in","r",stdin);
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      double cost,speed,target;
      cin>>cost>>speed>>target;
      double rate=2,ans=target/2,current=0;
      while(true)
        {
          current+=cost/rate;
          rate+=speed;
          if(current+target/rate>ans)
            break;
          ans=current+target/rate;
        }
      printf("Case #%d: %0.10lf\n",test,ans);
    }
  return 0;
}
