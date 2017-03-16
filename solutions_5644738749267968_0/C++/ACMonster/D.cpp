//program D

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
  freopen("D.in","r",stdin);
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      int n=get();
      static double x[1000],y[1000];
      for(int i=0;i<n;i++)
        cin>>x[i];
      for(int i=0;i<n;i++)
        cin>>y[i];
      sort(x,x+n);
      sort(y,y+n);
      static bool flag[1000];
      memset(flag,0,sizeof(flag));
      int ans_0=0,p0=0,q0=n-1,p1=0,q1=n-1;
      while(p0<=q0)
        {
          if(x[q0]>y[q1])
            {
              ans_0++;
              q0--;
              q1--;
            }
          else
            {
              p0++;
              q1--;
            }
        }
      memset(flag,0,sizeof(flag));
      int ans_1=0;
      for(int i=0;i<n;i++)
        {
          bool win=true;
          for(int j=0;win&&j<n;j++)
            if(!flag[j]&&y[j]>x[i])
              {
                flag[j]=true;
                win=false;
              }
          if(win)
            {
              ans_1++;
              for(int j=0;win&&j<n;j++)
                if(!flag[j])
                  {
                    win=false;
                    flag[j]=true;
                  }
            }
        }
      printf("Case #%d: %d %d\n",test,ans_0,ans_1);
    }
  return 0;
}
