#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <new>
#define see(x) cerr<<#x<<" = " << (x) << endl
using namespace std;
int n;
string S[120];
int full[200];
int Left[200];
int Right[200];
int middle[200];

int wl[200];
int wr[200];

long long fac[200];
const int MOD=1000000007;

bool same(string&s)
{
  for(int i=1;i<s.size();i++)
    if (s[i] != s[0])
      return false;
  return true;
}

bool lock[200];

void init()
{
  memset(wl,0,sizeof(wl));
  memset(wr,0,sizeof(wr));
  memset(full,0,sizeof(full));
  memset(Left,0,sizeof(Left));
  memset(Right,0,sizeof(Right));
  memset(middle,0,sizeof(middle));

  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>S[i];
    if (same(S[i]))
    {
      full[S[i][0]]++;
      continue;
    }

    int len=S[i].size();
    int le=0;
    while(le+1<len && S[i][le+1]==S[i][0])
      le++;
    int ri=len-1;
    while(ri-1>0 && S[i][ri-1]==S[i][len-1])
      ri--;
    Left[S[i][0]]++;
    Right[S[i][len-1]]++;
    for(int j=le+1; j<ri; j++)
      middle[S[i][j]]++;

    wl[S[i][0]] = i;
    wr[S[i][len-1]] = i;
  }
}
bool used[200];
char back(string&s)
{
  return s[s.size()-1];
}
int work()
{
  memset(used,0,sizeof(used));
  for(int c='a';c<='z';c++)
  {
    if (middle[c]>0)
    {
      if (full[c]+Left[c]+Right[c]>0)
        return 0;
    }
    if (Left[c]>1 || Right[c]>1) return 0;
  }
  int cnt_seg=0;
  for(int C='a'; C<='z'; C++)
  {
    int c=C;
    int rec=0;
    if (!used[c])
    {
      if (wl[c]==0 && wr[c]==0)
      {
        if (full[c]) cnt_seg++;
        continue;
      }
      while(wr[c]!=0)
      {
        c=S[wr[c]][0];
        used[c]=true;
        rec++;
        if (rec>100) return 0;
      }
      c=C;
      used[c]=true;
      c=back(S[wl[c]]);
      do
      {
        used[c]=true;
        c=back(S[wl[c]]);
        rec++;
        if (rec>100) return 0;
      } while(wl[c]!=0);
      used[c]=true;
      cnt_seg++;
    }
  }
  long long ans=fac[cnt_seg];
  for(int c='a';c<='z';c++)
    if (full[c]>0)
    {
      ans *= fac[full[c]];
      ans %= MOD;
    }
  return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("B-large.in","r",stdin);
  freopen("B-large.out","w",stdout);
  //freopen("in","r",stdin);
#endif
  fac[1]=1;
  for(int i=2;i<=120;i++)
    fac[i] = (fac[i-1]*i)%MOD;
  int T;
  cin>>T;
  for(int t=1;t<=T;t++)
  {
    printf("Case #%d: ", t);
    init();
    cout << work() << endl;
  }
  return 0;
}
