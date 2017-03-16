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

// (Z)ERO, T(W)O, FO(U)R SI(X) EI(G)HT
// (O)NE, T(H)REE, (F)IVE, (S)EVEN
// NINE

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

string S[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int qnt[300];
char str[30000];
int main() {
  int cas = 1;
  int t; sc(t);
  rp(i,t) {
    scs(str);
    int n = strlen(str);
    cl(qnt,0);
    rp(i,n) {
      qnt[str[i]]++;
    }

    printf("Case #%d: ", cas++);
    vi ans;
    while (qnt['Z'] > 0) {
      rp(i,S[0].size()) qnt[S[0][i]]--;
      ans.pb(0);
    }
    while (qnt['W'] > 0) {
      rp(i,S[2].size()) qnt[S[2][i]]--;
      ans.pb(2);
    }
    while (qnt['U'] > 0) {
      rp(i,S[4].size()) qnt[S[4][i]]--;
      ans.pb(4);
    }
    while (qnt['X'] > 0) {
      rp(i,S[6].size()) qnt[S[6][i]]--;
      ans.pb(6);
    }
    while (qnt['G'] > 0) {
      rp(i,S[8].size()) qnt[S[8][i]]--;
      ans.pb(8);
    }
    while (qnt['O'] > 0) {
      rp(i,S[1].size()) qnt[S[1][i]]--;
      ans.pb(1);
    }
    while (qnt['H'] > 0) {
      rp(i,S[3].size()) qnt[S[3][i]]--;
      ans.pb(3);
    }
    while (qnt['F'] > 0) {
      rp(i,S[5].size()) qnt[S[5][i]]--;
      ans.pb(5);
    }
    while (qnt['S'] > 0) {
      rp(i,S[7].size()) qnt[S[7][i]]--;
      ans.pb(7);
    }
    while (qnt['N'] > 0) {
      rp(i,S[9].size()) qnt[S[9][i]]--;
      ans.pb(9);
    }
    sort(ans.begin(), ans.end());
    rp(i,ans.size()) printf("%d", ans[i]);
    puts("");
  }
  return 0;
}






