//Khagan

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#define  pb        push_back
using    namespace std;

int T,K,L,S,sz,mx;
string s1,s2;
vector<string>v;

int g(int id)
{
  string s=v[id];
  int cnt=0;
  for(int i=0 ; i<=S-L ; i++)
  {
    bool ok=true;
    for(int j=0 ; j<L && ok ; j++)
      if(s2[j]!=s[i+j])
        ok=false;
    if(ok)
      cnt++;
  }
  return cnt;
}

void f(int curr , string s)
{
  if(curr==S)
  {
    sz++;
    v.pb(s);
    return;
  }
  for(int i=0 ; i<K ; i++)
    f(curr+1,s+s1[i]);
}

int main()
{
  freopen("B-small-attempt0.in","r",stdin);
  freopen("cikti.txt","w",stdout);
  scanf("%d",&T);
  for(int t=1 ; t<=T ; t++)
  {
    scanf("%d%d%d",&K,&L,&S);
    cin >> s1 >> s2;
    sz=0;
    v.clear();
    string emptys="";
    f(0,emptys);
    int mx=0;
    int tot[8];
    memset(tot,0,sizeof(tot));
    for(int i=0 ; i<sz ; i++)
    {
      int cnt=g(i);
      mx=max(mx,cnt);
      tot[cnt]++;
    }
    int res=0;
    for(int i=0 ; i<mx ; i++)
      res+=(mx-i)*tot[i];
    printf("Case #%d: %.8lf\n",t,(double)res/(double)sz);
  }
  return 0;
}
