#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace pb_ds;

#define PB push_back
#define MP make_pair
#define SZ size()
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ITR(i, j, n) for(int i = (j); i < (n); i++)
#define mem(array, val) memset(array, val, sizeof(array))
#define READ(filename) freopen(filename, "r", stdin)
#define WRITE(filename) freopen(filename, "w", stdout)
#define Fr first
#define Sc second
#define si(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define sd(a) scanf("%lf", &a)
#define ss(a) scanf("%s", a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define sdd(a, b) scanf("%lf%lf", &a, &b)
#define debug(x) cout << #x << ": " << x << endl
#define Fast_IO ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long Long;
typedef pair <int, int> Pii;
///<-------------------------------------------------END OF TEMPLATE-------------------------------------------------->

#define MAX 20
int N;
char C[MAX], J[MAX];

bool valid(int a, char *s) {
   int x = N-1;
   while(x >= 0) {
      int md = a % 10;
      if(s[x] != ('0' + md) && s[x] != '?') return false;
      a /= 10;
      x--;
   }
   return true;
}

int main() {
   READ("B-small-attempt1.in");
   WRITE("answer1.out");
   int t, ca = 1;
   si(t);

   while(t--) {
      Long xc = 0, xj = 0;
      ss(C);
      ss(J);
      N = strlen(C);

      Long ans = 100000, ac = 0, aj = 0, mx = 1;
      REP(i, N) mx *= 10;

      REP(i, mx) REP(j, mx) if(valid(i, C) && valid(j, J)) {
         //cout << i << ' ' << j << endl;
         if(abs(i - j) < ans) {
            ans = abs(i - j);
            ac = i;
            aj = j;
         }
      }

      string sc = "", sj = "";
      while(ac > 0) {
         Long md = ac % 10;
         sc += char('0' + md);
         ac /= 10;
      }
      while(aj > 0) {
         Long md = aj % 10;
         sj += char('0' + md);
         aj /= 10;
      }
      while(sc.SZ < N) sc += '0';
      while(sj.SZ < N) sj += '0';
      reverse(sc.begin(), sc.end());
      reverse(sj.begin(), sj.end());
      printf("Case #%d: %s %s\n", ca++, sc.c_str(), sj.c_str());
   }

   return 0;
}
