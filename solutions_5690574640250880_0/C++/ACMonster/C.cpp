//program C

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

void solve_k_1(int n,int m)
{
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        putchar((i||j)?'*':'c');
      putchar('\n');
    }
}

void solve_n_1(int m,int k)
{
  for(int i=0;i<m;i++)
    if(!i)
      putchar('c');
    else if(i<k)
      putchar('.');
    else
      putchar('*');
  putchar('\n');
}

void solve_m_1(int n,int k)
{
  for(int i=0;i<n;i++)
    {
      if(!i)
        putchar('c');
      else if(i<k)
        putchar('.');
      else
        putchar('*');
      putchar('\n');
    }
}

void solve_usual(int n,int m,int k)
{
  int mine=n*m-k;
  if(mine<=(n-2)*(m-2))//雷的数量较少
    {
      for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
            if(i==n-1&&j==m-1)
              putchar('c');
            else if(j<m-2&&i*(m-2)+j<mine)
              putchar('*');
            else
              putchar('.');
          putchar('\n');
        }
      return;
    }
  if(k>2&&(~k&1))//L形
    {
      static string ans[50];
      for(int i=0;i<n;i++)
        {
          ans[i]="";
          for(int j=0;j<m;j++)
            ans[i]+='*';
        }
      if(k<=n*2)
        {
          for(int i=0;i<k/2;i++)
            ans[i][0]=ans[i][1]='.';
        }
      else
        {
          for(int i=0;i<n;i++)
            ans[i][0]=ans[i][1]='.';
          for(int i=2;i<k/2-n+2;i++)
            ans[0][i]=ans[1][i]='.';
        }
      ans[0][0]='c';
      for(int i=0;i<n;i++)
        cout<<ans[i]<<endl;
      return;
    }
  if(k==2)//特判2个空位
    {
      printf("Impossible\n");
      return;
    }
  if(n==2||m==2)//奇数个空位，特判2*k的情况
    {
      printf("Impossible\n");
      return;
    }
  if(k>=9)//L形拓展
    {
      static string ans[50];
      for(int i=0;i<n;i++)
        {
          ans[i]="";
          for(int j=0;j<m;j++)
            ans[i]+='*';
        }
      ans[0][0]='c';
      ans[0][1]=ans[0][2]='.';
      ans[1][0]=ans[1][1]=ans[1][2]='.';
      ans[2][0]=ans[2][1]=ans[2][2]='.';
      k-=9;
      for(int p=3,q=3;k>0;k-=2)
        if(p<n)
          {
            ans[p][0]=ans[p][1]='.';
            p++;
          }
        else
          {
            ans[0][q]=ans[1][q]='.';
            q++;
          }
      for(int i=0;i<n;i++)
        cout<<ans[i]<<endl;
      return;
    }
  printf("Impossible\n");
}

int main()
{
  freopen("C.in","r",stdin);
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      printf("Case #%d:\n",test);
      int n=get(),m=get(),k=n*m-get();
      if(k==1)
        solve_k_1(n,m);
      else if(n==1)
        solve_n_1(m,k);
      else if(m==1)
        solve_m_1(n,k);
      else
        solve_usual(n,m,k);
    }
  return 0;
}
