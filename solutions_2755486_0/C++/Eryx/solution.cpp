#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
//#include <iostream>
#include <set>
#include <map>
//#include <sstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<string> vs;

int err;

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

// template<class T> T& operator >?= (T& x, T y) {if(y>x) x=y; return x;}
// template<class T> T& operator <?= (T& x, T y) {if(y<x) x=y; return x;}
// template<class T> T operator >? (T x, T y) {return x>y?x:y;}
// template<class T> T operator <? (T x, T y) {return x<y?x:y;}

#define Pa(xy) ((xy).first)
#define Ir(xy) ((xy).second)

string cts(char c) {string s=""; s+=c; return s;}

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

int Tests, cnum;

//Eryx

// !FDI

struct attack {
  int d, x0, x1, s;
  };

vector<attack> v;

set<int> S;
map<int, int> M;

const int maxw = (1<<21);

int wallh[maxw*2], minh[maxw*2];

bool asort(attack a1, attack a2) {
  return a1.d < a2.d;
  }

bool testpoint(int x, int s) {
  int smax = 0;
  int sx = x;
  while(x) {
    //printf("x=%d [%d]\n", x, minh[x]);
    if(minh[x] > smax) smax = minh[x];
    x >>= 1;
    }
  //printf("point %d: %d\n", sx, smax);
  return smax < s;
  }

bool testwall(int x0, int x1, int s) {
//printf("test\n");
  if(x0 == x1) return false;
  if((x0&1) && testpoint(x0, s)) return true;
  if((x1&1) && testpoint(x1-1, s)) return true;
  if(x0&1) x0++;
  if(x1&1) x1--;
  testwall(x0>>1, x1>>1, s);
  }

void buildpoint(int x, int s) {
  wallh[x] = max(wallh[x], s);
  minh[x] = max(minh[x], s);
  x >>= 1;
  while(x) {
    minh[x] = max(minh[x], min(minh[2*x], minh[2*x+1]));
    x >>= 1;
    }
  }

void buildwall(int x0, int x1, int s) {
//printf("build %d-%d\n", x0, x1);
  while(x0 != x1) {
    if(x0&1) buildpoint(x0, s), x0++;
    if(x1&1) x1--, buildpoint(x1, s);
    x0 >>= 1; x1 >>= 1;
    }
  }

void viewwall() {
  for(int i=0; i<2*maxw; i++) if(minh[i]) printf("%d:%d:%d ", i, wallh[i], minh[i]);
  printf("\n");
  }

void solveCase() {
  int res = 0;

  int N;
  
  int di, ni, wi, ei, si, ddi, dpi, dsi;
  
  err = scanf("%d", &N);
  
  S.clear(); M.clear();
    
  for(int nn=0; nn<N; nn++) {
  
    err = scanf("%d%d%d%d%d%d%d%d", &di, &ni, &wi, &ei, &si, &ddi, &dpi, &dsi);
    
    for(int i=0; i<ni; i++) {
      attack a;
      a.d = di + ddi * i;
      a.x0 = wi + dpi * i;
      a.x1 = ei + dpi * i;
      a.s = si + dsi * i;
      v.push_back(a);
      S.insert(a.x0);
      S.insert(a.x1);
      }
    }
  
  int At = Size(v);
  int id = 0;
  for(set<int>::iterator it = S.begin(); it != S.end(); it++) {
    M[*it] = maxw + (id++);
    }

  fprintf(stderr, "id = %d At = %d\n", id, At);
  if(id > maxw) exit(1);
  
  for(int i=0; i<At; i++) v[i].x0 = M[v[i].x0], v[i].x1 = M[v[i].x1];
  
  for(int i=0; i<maxw*2; i++) wallh[i] = minh[i] = 0;
  
  sort(v.begin(), v.end(), asort);
  
  int score = 0;
  
  int lastd = -1;
  int lasti = 0;

  for(int i=0; i<At; i++) {
    attack& a(v[i]);
    //printf("day %d: %d-%d S%d\n", a.d, a.x0, a.x1, a.s);
    if(a.d != lastd) {
      lastd = a.d;
      for(int j=lasti; j<i; j++)
        buildwall(v[j].x0, v[j].x1, v[j].s);
      lasti = i;
      //viewwall();
      }
    
    bool te = testwall(v[i].x0, v[i].x1, v[i].s);
    //printf("test: %d\n", te);
    if(te) score++;
    }
  
  printf("Case #%d: %d\n", cnum, score);
  }

int main() {

  if(0)
    Tests = 1;
  else if(1)
    err = scanf("%d", &Tests);
  else {
    string Nstr = getLine();
    Tests = atoi(Nstr.c_str());
    }
  
  //Tests=1;
  for(cnum=1; cnum<=Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

// This solution includes hidden routines to solve test cases in separate
// processes in order to make it faster. I will update them to run on a
// cluster if I get one ;)
