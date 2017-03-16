#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ size()
#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define ITR(i, j, n) for(int i = j; i < (int)n; i++)
#define mem(array, val) memset(array, val, sizeof(array))
#define READ(filename) freopen(filename, "r", stdin)
#define WRITE(filename) freopen(filename, "w", stdout)
#define Pii pair <int, int>
#define Fr first
#define Sc second
#define Long long long
#define si(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define sd(a) scanf("%lf", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define sdd(a, b) scanf("%lf%lf", &a, &b)

#define MAX 1005
char s[MAX], len;

void main_(int caseno)
{
   scanf("%d %s", &len, s);
   int ret = 0, sum = 0;
   REP(i, len+1) {
      ret = max(ret, (sum < i) ? i-sum:0);
      sum += (s[i] - '0');
   }
   printf("Case #%d: %d\n", caseno, ret);

   return;
}

int main()
{
   READ("A-large.in");
   WRITE("soln.out");
   int t = 1, caseno = 1;
   si(t);
   while(caseno <= t) main_(caseno++);
   return 0;
}
