#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

template <typename T>
inline void upd_max(T &dest,const T& src){if(dest<src)dest=src;return ;}
template <typename T>
inline void upd_min(T &dest,const T& src){if(dest>src)dest=src;return ;}

const int maxN=1000+13;

char s[maxN];
int T;
string ans;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("A-large.in","r",stdin);
  freopen("A.out","w",stdout);
#endif
  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++)
  {
    scanf("%s",s);
    //cout<<s<<endl;
    int n=strlen(s);
    ans="";
    ans=s[0];
    for(int i=1;i<n;i++)
    {
      string st1=s[i]+ans;
      string st2=ans+s[i];
      if(st1>st2)
        ans=s[i]+ans;
      else
        ans=ans+s[i];
    }
    printf("Case #%d: ",cas);
    printf("%s\n",ans.c_str());
  }
  return 0;
}

