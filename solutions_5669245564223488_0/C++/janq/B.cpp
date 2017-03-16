// pre-written code {{{
#include <cstdio>
#include <cmath>
#include <cstring>
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

LL MOD = 1000000007;

LL fact(int x) {
  LL ret = 1;
  FOR(i,x) {
    ret *= (LL)(i+1);
    ret %= MOD;
  }
  return ret;
}

LL ret = 1;

VS a;

bool isUniform(string s) {
  if(s.size()==0) return false;
  FORSZ(i,s) if(s[i]!=s[0]) return false;
  return true;
}

void doUniform() {
  int uniform[255];
  FOR(i,255) uniform[i]=0;
  FORSZ(i,a) {
    if(isUniform(a[i])) {
      uniform[a[i][0]]++;  
    }
  }
  FOR(i,255) { ret*=fact(uniform[i]); ret%=MOD; }
}

void mergeUniform() {
  FORSZ(i,a) if(isUniform(a[i])) 
    FR(j,i+1,a.size()) if(isUniform(a[j])) if(a[i][0]==a[j][0]) {
      a[i]+=a[j];
      a[j]="";
    }
  
}

void mergeForcedUniform() {
  FOR(i,a.size()) if(a[i].size()) 
      FOR(j,a.size()) if(j!=i) if(a[j].size()) 
        if(isUniform(a[j])) {
        if(a[i][a[i].size()-1] == a[j][0]) {
          a[i]+=a[j];
          a[j]="";
        } else
        if(a[i][0] == a[j][a[j].size()-1]) {
          a[i]=a[j]+a[i];
          a[j]="";
        }
        }
}

void mergeForced() {
  FOR(i,a.size()) if(a[i].size())
      FOR(j,a.size()) if(j!=i) if(a[j].size()) 
      {
        if(a[i][a[i].size()-1] == a[j][0]) {
          a[i]+=a[j];
          a[j]="";
        } else
        if(a[i][0] == a[j][a[j].size()-1]) {
          a[i]=a[j]+a[i];
          a[j]="";
        }
      }
}

bool isValid() { 
  int occ[255];
  FOR(i,255) occ[i]=0;
  FORSZ(i,a) {
    FORSZ(j,a[i]) occ[a[i][j]]++;
  }
  FORSZ(i,a) {
    int poc=0;
    FORSZ(j,a[i]) {
      if(j==0) { poc++; continue; }
      if(a[i][j]!=a[i][j-1]) {
        if(occ[a[i][j-1]]!=poc) return false;
        poc=1;
      } else {
        poc++;
      }
    }
    if(a[i].size()) if(poc!=occ[a[i][a[i].size()-1]]) return false;
  }
  return true;
}

void solve(){
  a.clear();
  ret = 1;
  int n;
  scanf("%d\n",&n);
  char s[205];
  FOR(i,n) { scanf("%s\n",s); a.PB(s); }
  doUniform();
  mergeUniform();
  mergeForcedUniform();
  mergeForced();  
  if(!isValid()) { printf("0\n"); return; }
  int komp=0;
  FORSZ(i,a) if(a[i].size()) komp++;
  ret *= fact(komp); ret%=MOD; printf("%lld\n",ret);
  FORSZ(i,a) if(a[i].size()) printf("%s\n",a[i].c_str());
}


bool bolo[30];

void solveBT() {
  a.clear();
  int n;
  scanf("%d\n",&n);
  char s[205];
  FOR(i,n) { scanf("%s\n",s); a.PB(s); }  
  CL(bolo);
  VI perm;
  FOR(i,n) perm.PB(i);

  LL ret=0;
  do{
    char last=0;
    CL(bolo);
    FOR(i,n) {
      string &s=a[perm[i]];
      FORSZ(j,s) {        
        if(s[j]==last) continue;
        if(bolo[s[j]-'a']) goto nextperm;
        bolo[s[j]-'a']=true;
        last=s[j];
      }
    }
    ret++;
nextperm:
    ;
  }while(next_permutation(ALL(perm)));
  printf("%lld\n",ret);
}

int main(){
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solveBT();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
