//program C

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

struct Num
{
  int x,y;
};

bool operator ==(Num a,Num b)
{
  return a.x==b.x&&a.y==b.y;
}

long long get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  long long x=0;
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

const int mult[4][4]={
{0,1,2,3},
{1,0,3,2},
{2,3,0,1},
{3,2,1,0}};

const int sign[4][4]={
{0,0,0,0},
{0,1,0,1},
{0,1,1,0},
{0,0,1,1}};

Num operator +(Num a,Num b)
{
  return (Num){mult[a.x][b.x],a.y^b.y^sign[a.x][b.x]};
}

Num Sum(Num a,long long b)
{
  if(b==1)
    return a;
  Num t=Sum(a+a,b/2);
  if(b&1)
    t=t+a;
  return t;
}

Num a[10000];

int main()
{
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      int n=get();
      long long m=get();
      for(int i=0;i<n;i++)
        {
          char c;
          while(c=getchar(),c!='i'&&c!='j'&&c!='k');
          a[i]=(Num){c-'i'+1,0};
        }
      Num sum={0,0};
      for(int i=0;i<n;i++)
        sum=sum+a[i];
      sum=Sum(sum,m);
      printf("Case #%d: ",test);
      if(!(sum==(Num){0,1}))
        {
          printf("NO\n");
          continue;
        }
      int l=-1,r=-1;
      sum=(Num){0,0};
      for(int i=0;i<n*4;i++)
        {
          sum=sum+a[i%n];
          if(sum==(Num){1,0})
            {
              l=i+1;
              break;
            }
        }
      sum=(Num){0,0};
      for(int i=n*4-1;i>=0;i--)
        {
          sum=a[i%n]+sum;
          if(sum==(Num){3,0})
            {
              r=n*4-i;
              break;
            }
        }
      if(l!=-1&&r!=-1&&l+r<m*n)
        printf("YES\n");
      else
        printf("NO\n");
    }
  return 0;
}
