// pre-written code {{{
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <numeric>
#include <iostream>
#include <cassert>
#include <set>
#define FOR(i,n) for(int _n=n,i=0;i<_n;++i)
#define FR(i,a,b) for(int _b=b,i=a;i<_b;++i)
#define CL(x) memset(x,0,sizeof(x))
#define PN printf("\n");
#define MP make_pair
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define FORSZ(i,v) FOR(i,v.size())
#define FORIT(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;
///////////////////////////////////////////////////////////////////////////////////
// }}}

string s[3] = {
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

string t[3] = {
"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"
};

char mapping[256];

void solve(){
  char r[10000];
  scanf("%[^\n]\n",r);
  string rr = r;
  FORSZ(i,rr) rr[i] = mapping[rr[i]];
  printf("%s\n",rr.c_str());
}

int main(){
  FOR(i,256) mapping[i] = '\0';
  FOR(i,3) FORSZ(j,s[i]) {
    char ss = s[i][j];
    char tt = t[i][j];
    mapping[ss] = tt;
  }
  mapping['z'] = 'q';
  mapping['q'] = 'z';
//  for(char x = 'a'; x <= 'z'; x++) printf("%c: %c %d\n",x,mapping[x],mapping[x]);
//  return 0;
  int pvs; scanf("%d\n",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
