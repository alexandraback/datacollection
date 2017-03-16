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

const int n=16;
const int m=50;
const int len=40;

int ans[n];

string proof(int n)
{
  string s="";
  for(int i=2;i<=10;i++)
    {
      s+=" ";
      int a[len];
      memset(a,0,sizeof(a));
      a[0]=1;
      for(int j=0;j<n;j++)
        for(int k=0,g=0;k<len;k++)
          {
            a[k]=a[k]*i+g;
            g=a[k]/10;
            a[k]%=10;
          }
      int p=0;
      while(a[p]==9)
        {
          a[p]=0;
          p++;
        }
      a[p]++;
      p=len-1;
      while(!a[p])
        p--;
      while(p>=0)
        {
          s+=(char)(a[p]+48);
          p--;
        }
    }
  return s;
}

int main()
{
  string s=proof(n/2);
  printf("Case #1:\n");
  for(int mask=0;mask<m;mask++)
    {
      memset(ans,0,sizeof(ans));
      ans[0]=ans[n/2-1]=ans[n/2]=ans[n-1]=1;
      for(int i=0;i<(n/2-2);i++)
        ans[n/2-2-i]=ans[n-2-i]=(mask>>i)&1;
      for(int i=0;i<n;i++)
        putchar(ans[i]+'0');
      cout<<s<<endl;
    }
  return 0;
}
