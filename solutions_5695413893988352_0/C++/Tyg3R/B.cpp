#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int,int>

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

string C,J;
string c,j;
int L;

ll D,cc,jj;
string ccc,jjj;

void mn(string& s, string& S, int pos) {
  FOR(i,pos,L) {
    if(S[i] == '?') s[i] = '0';
    else s[i] = S[i];
  }
}

void mx(string& s, string& S, int pos) {
  FOR(i,pos,L) {
    if(S[i] == '?') s[i] = '9';
    else s[i] = S[i];
  }
}

void eval() {
  ll a = 0;
  FOR(i,0,L) {
    a *= 10LL;
    a += (ll)(c[i]-'0');
  }
  ll b = 0;
  FOR(i,0,L) {
    b *= 10LL;
    b += (ll)(j[i]-'0');
  }
  ll d = llabs(a-b);
  if(d < D) {
    D = d;
    cc = a;
    jj = b;
    ccc = c;
    jjj = j;
  } else if(d == D) {
    if(a < cc) {
      D = d;
      cc = a;
      jj = b;
      ccc = c;
      jjj = j;
    } else if(a == cc) {
      if(b < jj) {
        D = d;
        cc = a;
        jj = b;
        ccc = c;
        jjj = j;
      }
    }
  }
}

void rec(int pos) {
  if(pos >= L) {
    eval();
    return;
  }
  if(C[pos] == '?' && J[pos] == '?') {
    j[pos] = '0';
    c[pos] = '1';
    mx(j,J,pos+1);
    mn(c,C,pos+1);
    eval();
    c[pos] = '0';
    j[pos] = '1';
    mx(c,C,pos+1);
    mn(j,J,pos+1);
    eval();
    j[pos] = c[pos] = '0';
    rec(pos+1);
  } else if(C[pos] == '?') {
    j[pos] = J[pos];
    if(J[pos] < '9') {
      c[pos] = J[pos]+1;
      mn(c,C,pos+1);
      mx(j,J,pos+1);
      eval();
    }
    if(J[pos] > '0') {
      c[pos] = J[pos]-1;
      mx(c,C,pos+1);
      mn(j,J,pos+1);
      eval();
    }
    c[pos] = j[pos];
    rec(pos+1);
  } else if(J[pos] == '?') {
    c[pos] = C[pos];
    if(C[pos] < '9') {
      j[pos] = C[pos]+1;
      mn(j,J,pos+1);
      mx(c,C,pos+1);
      eval();
    }
    if(C[pos] > '0') {
      j[pos] = C[pos]-1;
      mx(j,J,pos+1);
      mn(c,C,pos+1);
      eval();
    }
    j[pos] = c[pos];
    rec(pos+1);
  } else {
    if(J[pos] == C[pos]) {
      c[pos] = C[pos];
      j[pos] = J[pos];
      rec(pos+1);
    }
    else if(J[pos] < C[pos]) {
      mx(j,J,pos+1);
      mn(c,C,pos+1);
      eval();
    } else {
      mn(j,J,pos+1);
      mx(c,C,pos+1);
      eval();
    }
  }
}

int main ()
{
  DRI(T);
  FOR(t,0,T) {
    cin >> C >> J;
    c = C, j = J;
    L = C.size();
    D = (ll)1e18+7;
    rec(0);
    printf("Case #%d: %s %s\n", t+1, ccc.c_str(), jjj.c_str());
    FOR(i,0,L) {
      
    }
  }
  return 0;
}
