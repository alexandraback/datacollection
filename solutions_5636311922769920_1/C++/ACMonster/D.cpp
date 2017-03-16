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
      int K=get(),C=get(),S=get();
      printf("Case #%d:",test);
      if(C*S<K)
        printf("IMPOSSIBLE\n");
      else
        {
          set<long long> all;
          all.clear();
          int cnt=0;
          for(int i=0;i<S;i++)
            {
              long long ans=0;
              for(int j=0;j<C;j++)
                {
                  ans=ans*K+cnt;
                  cnt=(cnt+1)%K;
                }
              if(!all.count(ans))
                {
                  all.insert(ans);
                  cout<<' '<<ans+1;
                }
            }
          putchar('\n');
        }
    }
  return 0;
}
