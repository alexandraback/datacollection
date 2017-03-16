#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
using namespace std;
#define inf 0x7fffffff
#define eps 1e-9
#define ll long long
#define ld long double
#define pii pair<int,int>
#define x first
#define y second
#define sf scanf
#define pf printf
#define vec vector
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define bin_cnt(x) __builtin_popcount(x)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define irep(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl
//#pragma comment(linker, "/STACK:32505856")

template<class T> inline void gmin(T&a,T b) {if(a>b)a=b;}
template<class T> inline void gmax(T&a,T b) {if(a<b)a=b;}
inline int sign(const double &a) {return a>eps?1:(a<-eps?-1:0);}
struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){}}initializer;

#define D 521196
#define S5 0b11111
set<string> dict;
int f[400][11][1031];
vec<int> word[11];
char s[400];

inline int check_num(int num) {
  int cnt=bin_cnt(num);
  if (cnt>2) return 0;
  if (cnt<=1) return 1;
  int i,j;
  for (i=0;;i++) if (num&(1<<i)) break;
  for (j=i+1;;j++) if (num&(1<<j)) break;
  return abs(j-i)>=5;
}

inline int check_num2(int len1,int num1,int len2,int num2) {
  int i,j=50000;
  for (i=len1-1;i>=0;i--)
    if (num1&(1<<i)) {
      if (abs(len1-1-i - j)<5) return 0;
      j=len1-1-i;
    }
  for (i=len2-1;i>=0;i--)
    if (num2&(1<<i)) {
      if (abs(len1+len2-1-i - j)<5) return 0;
      j=len1+len2-1-i;
    }
  return 1;
}

int check_dic(int l,int r,int len,int num) {
  string st;
  rep(i,l,r) st+=s[i];

  int cnt=bin_cnt(num),i,j;

  if (cnt==0)
    return dict.find(st)!=dict.end();

  if (cnt==1) {
    for (i=0;i<len;i++)
      if (num&(1<<i)) break;
    i=len-1-i;

    rep(c,'a','z') {
      st[i]=c;
      if (dict.find(st)!=dict.end()) return 1;
    }
  }

  if (cnt==2) {
    for (i=0;i<len;i++)
      if (num&(1<<i)) break;
    for (j=i+1;j<len;j++)
      if (num&(1<<j)) break;
    i=len-1-i;
    j=len-1-j;

    rep(c1,'a','z') {
      st[i]=c1;
      rep(c2,'a','z') {
        st[j]=c2;
        if (dict.find(st)!=dict.end()) return 1;
      }
    }
  }

  return 0;
}


int main() {
  freopen("dict.txt","r",stdin);

  char st[16];
  while (~sf("%s",st)) {
    dict.insert(st);
  }

  word[0].pb(0);
  rep(l,1,10)
    rrep(i,(1<<l)-1,0)
      if (check_num(i))
        word[l].pb(i);


  //freopen("CON","r",stdin);
  freopen("C-small-attempt4.in","r",stdin);
  //freopen("C-small.out","w",stdout);

  int T;
  sf("%d",&T);
  rep(t,1,T) {
    int ans=inf;

    sf("%s",s+1);
    int n=strlen(s+1);

    memset(f,0x7f,sizeof(f));
    f[0][0][0]=0;
    int s1,s0;

    rep(i,1,10) {

      rep(l1,1,10) {
        if (i-l1<0) break;
        rep(t1,0,sz(word[l1])-1) {
          s1=word[l1][t1];

          rep(l0,0,0) {
            if (i-l1-l0<0) break;
            rep(t0,0,sz(word[l0])-1) {
              s0=word[l0][t0];

              if (check_num2(l0,s0,l1,s1) && check_dic(i-l1+1,i,l1,s1))
                gmin(f[i][min(l1,5)][s1&S5],f[i-l1][l0][s0]+bin_cnt(s1));
            }

          }
        }
      }
    }

    rep(i,2,n) {

      rep(l1,1,10) {
        if (i-l1<0) break;
        rep(t1,0,sz(word[l1])-1) {
          s1=word[l1][t1];

          rep(l0,1,5) {
            if (i-l1-l0<0) break;
            rep(t0,0,sz(word[l0])-1) {
              s0=word[l0][t0];

              if (check_num2(l0,s0,l1,s1) && check_dic(i-l1+1,i,l1,s1))
                gmin(f[i][min(l1,5)][s1&S5],f[i-l1][l0][s0]+bin_cnt(s1));
            }

          }
        }
      }
    }

    ans=*min_element(&f[n][0][0],&f[n][10][1030]+1);

    freopen("CON","a",stdout);
    pf("Case #%d: %d\n",t,ans);

    freopen("C-small.out","a",stdout);
    pf("Case #%d: %d\n",t,ans);
  }

  return 0;
}
