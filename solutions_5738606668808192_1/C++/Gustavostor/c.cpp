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

int fastexpo(int b, int e, int m) {
  int a = 1;
  for (; e; e>>=1, b=(b*b)%m) if (e&1) a=(a*b)%m;
  return a;
}

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
int ps;

set<ll> fs;
int pre[20][200];
bool gen(int n) {
  fr(i,2,11) {
    rp(j,ps) pre[i][j] = (fastexpo(i,n-1,p[j])+1)%p[j];
  }
  ll num = (1LL<<(n-1)) + 1;
  fr(k,1,n-1) {
    if (rand()%2 == 1) {
      num |= (1LL<<k);
      fr(i,2,11) {
        rp(j,ps) pre[i][j] = (pre[i][j] + fastexpo(i,k,p[j]))%p[j];
      }
    }
  }
  if (fs.count(num)) return 0;
  fr(i,2,11) {
    bool ok = 0;
    rp(j,ps) if (pre[i][j] == 0) {
      ok = 1;
      break;
    }
    if (!ok) return 0;
  }
  fs.insert(num);
  for (int i = n-1; i >= 0; i--) if (num&(1LL<<i)) printf("1"); else printf("0");
  fr(i,2,11) {
    rp(j,ps) if (pre[i][j] == 0) {
      printf(" %d", p[j]);
      break;
    }
  }
  puts("");
  return 1;
}

int main() {
  srand(time(NULL));
  ps = sizeof(p) / sizeof(int);
  int t; sc(t);
  int cas = 1;
  while (t--) {
    fs.clear();
    int n, j;
    sc2(n,j);
    printf("Case #%d:\n", cas++);
    rp(i,j) if (!gen(n)) i--;
  }
}




