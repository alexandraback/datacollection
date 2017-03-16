#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>
   
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

using namespace std;

#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
#define fre(a,b) for(int a = adj[b]; ~a; a = ant[a])

#define iter(a) __typeof((a).begin())
#define fore(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++

const int oo = 0x3f3f3f3f;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n;
char a[30], b[30];
int BEST, BA, BB;
string ra, rb;

void bt(int i) {
  if (!a[i]) {
    int A = 0, B = 0;
    rp(x,n) A = A*10 + a[x] - '0';
    rp(x,n) B = B*10 + b[x] - '0';
    if (abs(A-B) < BEST) {
      BEST = abs(A-B);
      BA = A;
      BB = B;
      ra = string(a);
      rb = string(b);
    } else if (abs(A-B) == BEST) {
      if (A < BA) {
        BA = A, BB = B;
        ra = string(a);
        rb = string(b);
      } else if (A == BA && B < BB) {
        BB = B;
        ra = string(a);
        rb = string(b);
      }
    }
    return;
  }

  if (a[i] == '?' && b[i] == '?') {
    rp(x,10) rp(y,10) {
      a[i] = x+'0';
      b[i] = y+'0';
      bt(i+1);
    }
    a[i] = b[i] = '?';
  } else if (a[i] == '?') {
    rp(x,10) {
      a[i] = x + '0';
      bt(i+1);
    }
    a[i] = '?';
  } else if (b[i] == '?') {
    rp(y,10) {
      b[i] = y + '0';
      bt(i+1);
    }
    b[i] = '?';
  } else {
    bt(i+1);
  }
}

int main() {
  int t; sc(t);
  int cas = 1;
  rp(i,t) {
    scs(a); scs(b);
    n = strlen(a);
    BEST = 1000000000;
    bt(0);
    printf("Case #%d: %s %s\n", cas++, ra.c_str(), rb.c_str());
  }
  return 0;
}






