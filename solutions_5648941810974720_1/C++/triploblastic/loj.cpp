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

#define MAX 2005
int N, cnt[26], dig[10];
int go[] = {0, 6, 2, 4, 8, 3, 7, 5, 1, 9};
char s[MAX], key[] = {'Z', 'X', 'W', 'U', 'G', 'H', 'S', 'V', 'O', 'I'};
string val[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

int main() {
   READ("A-large.in");
   WRITE("answer.out");
   int t, ca = 1;
   si(t);

   while(t--) {
      ss(s);
      N = strlen(s);
      mem(cnt, 0);
      mem(dig, 0);
      REP(i, N) cnt[ s[i] - 'A' ]++;
      REP(i, 10) {
         dig[ go[i] ] += cnt[ key[i] - 'A' ];
         REP(j, val[ go[i] ].SZ) cnt[ val[ go[i] ][j] - 'A' ] -= dig[ go[i] ];
      }
      printf("Case #%d: ", ca++);
      REP(i, 10) {
         while(dig[i] > 0) {
            putchar('0' + i);
            dig[i]--;
         }
      }
      puts("");
   }

   return 0;
}
