// I am doing this round on an Android tablet
// but I had to debug this on an Android phone

#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//#include <iostream>
//#include <set>
//#include <map>
//#include <sstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<string> vs;

#define LS <
#define Size(x) (int(x.size()))
#define LET(k,val) typeof(val) k = (val)
#define CLC(act,val) (*({act; static typeof(val) CLCR; CLCR = (val); &CLCR;}))

#define FOR(k,a,b) for(typeof(a) k=(a); k LS (b); ++k)
#define FORREV(k,a,b) for(typeof(b) k=(b); (a) <= (--k);)

#define FIRST(k,a,b,cond) CLC(LET(k, a); for(; k LS (b); ++k) if(cond) break, k)
#define LAST(k,a,b,cond) CLC(LET(k, b); while((a) <= (--k)) if(cond) break, k)
#define EXISTS(k,a,b,cond) (FIRST(k,a,b,cond) LS (b))
#define FORALL(k,a,b,cond) (!EXISTS(k,a,b,!(cond)))
#define FOLD0(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(; k LS (b); ++k) {act;}, R##k)
#define SUMTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k += (x))
#define SUM(k,a,b,x) SUMTO(k,a,b,(typeof(x)) (0), x)
#define PRODTO(k,a,b,init,x) FOLD0(k,a,b,init,R##k *= (x))
#define PROD(k,a,b,x) PRODTO(k,a,b,(typeof(x)) (1), x)
#define MAXTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k >?= (x))
#define MINTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k <?= (x))
#define QXOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (0), R##k ^= x)
#define QAND(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k &= x)
#define QOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k |= x)
#define FOLD1(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(++k; k LS (b); ++k) act, R##k)
#define MAX(k,a,b,x) FOLD1(k,a,b,x, R##k >?= (x))
#define MIN(k,a,b,x) FOLD1(k,a,b,x, R##k <?= (x))
#define FIRSTMIN(k,a,b,x) (MIN(k,a,b,make_pair(x,k)).second)

int bitc(ll r) {return r == 0 ? 0 : (bitc(r>>1) + (r&1));}
ll gcd(ll x, ll y) {return x ? gcd(y%x,x) : y;}

#define Pa(xy) ((xy).first)
#define Ir(xy) ((xy).second)

string cts(char c) {string s=""; s+=c; return s;}

int cnum, Tests, err;

//Eryx
// (th

/// ----

#define BUFSIZE 1000000
char buf[BUFSIZE];

#ifdef DEBUG
#define DEB(x) x
#else
#define DEB(x)
#endif

string getLine() {
  string s;
  while(!feof(stdin)) {
    char c = fgetc(stdin);
    if(c == 13) continue;
    if(c == 10) return s;
    s += c;
    }
  return s;
  }

int getNum() {
  string s = getLine();
  return atoi(s.c_str());
  }

int g() {int r=0; err=scanf("%d", &r);// printf("%d ", r); 
 return r;}
vi parsevi(string s) {
  s = s + " ";
  int q = 0;
  bool minus = false;
  vi res;
  FOR(l,0, Size(s)) {
    if(s[l] == ' ') { res.push_back(minus?-q:q); q = 0; minus = false;}
    else if(s[l] == '-') { minus = true; }
    else { q = q * 10 + s[l] - '0'; }
    }
  return res;
  }

int kc[300];
int req[300];
int ikc[300];
int id[300][300];

bool op[300];
int bal[300];

vector<int> r[300];

// I have written two research papers based on this algorithm!

int hk[300];
bool vis[300];
int N,K;

void dfskey(int ki);

void dfschest(int n) {
  if(vis[n]) return;
  vis[n]=true;
  FOR(a,0,ikc[n]) {
    int ki=id[n][a];
    hk[ki]++;
    if(hk[ki]==1) dfskey(ki);
    }
  }

void dfskey(int k) {
  FOR(a,0,Size(r[k])) dfschest(r[k][a]);
}

bool ver(int z) {
  FOR(q,0,300) hk[q]=kc[q];
  FOR(a,0,N) if(op[a]) {
    hk[req[a]]--;
    FOR(b,0,ikc[a]) hk[id[a][b]]++;
    }
  if(z>=0) {if(hk[req[z]]<=0) return false;
  hk[req[z]]--;
  FOR(b,0,ikc[z]) hk[id[z][b]]++; }
  FOR(q,0,N) vis[q] = op[q]||q==z;
  FOR(q,0,300) if(hk[q]>0) dfskey(q);
  FOR(q,0,N) if(!vis[q]) return false;
  return true;
  }

void solveCase() {
  int res = 0;
  // proceed
  K=g();
  N=g();
  FOR(a,0,300) kc[a]=0, bal[a]=0, r[a].clear();;
  FOR(a,0,K) {
    int i=g(); kc[i]++; bal[i]++;
    }

  FOR(a,0,N) { //printf("\n");
    req[a]=g(); bal[req[a]]--;
    r[req[a]].push_back(a);
    ikc[a]=g(); op[a]=false;
    FOR(b,0,ikc[a]) {int j=g(); bal[j]++; id[a][b]=j;}
  }
  bool bb=true;
  FOR(q,0,300) if(bal[q]<0) bb=false;

  //FOR(q,0,300) 

  if(bb && ver(-1)) {
    printf("Case #%d:", cnum+1);
    int left=N, at=-1;
    while(left) {
      at++;
      if(at==N) { printf("X"); break; }
      at%=N;
      if(op[at]) continue;
      if(ver(at)) { op[at]=true; left--; printf(" %d", at+1); at=-1; }
      else op[at]=false;
      }
    printf("\n");
    }

  else printf("Case #%d: IMPOSSIBLE\n", cnum+1);
  }

int main() {
  if(0) Tests = 1;
  else if(0) {
    string Nstr = getLine();
    Tests = atoi(Nstr.c_str());
    }
  else {
    err = scanf("%d", &Tests);
    }

  for(cnum=0; cnum<Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

// I also have a preprocessor which turns this solution into one that
// runs test cases in separate processes in order to make it faster
