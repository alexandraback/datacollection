//shjj-B

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

char s[300];
int n,ans;

int main()
{
  freopen("B0.in","r",stdin);
  freopen("B0.out","w",stdout);
  int T,Tt=0;scanf("%d",&T);
  for (;T--;)
  {
    scanf("%s",s+1);
    n=strlen(s+1);
    ans=0;
    for (int i=n;i>=1;i--)
    {
      int x=(s[i]=='+');
      x^=(ans&1);
      if (!x) ans++;
    }
    printf("Case #%d: %d\n",++Tt,ans);
  }
}