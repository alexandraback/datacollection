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
int val[MAX], D;
bool check(int x)
{
   REP(t, x) {
      int sum = 0, rem = x-t, tmp = t;
      for(int i = D-1; i >= 0; i--) {
         if(val[i] <= rem) break;
         if(val[i]-rem > rem) sum += (val[i]-rem);
         tmp--;
      }
      if(tmp < 0) continue;
      while(tmp--) sum -= rem;
      if(sum <= rem) return true;
   }
   return false;
}

void main_(int caseno)
{
   int mx = 0, ret, tm = 0;
   mem(val, 0);
   si(D);
   REP(i, D) si(val[i]);
   sort(val, val+D);
   ret = val[D-1];
   int lo = 1, hi = val[D-1];
   while(lo < hi) {
      if(lo+1 == hi) {
         if(!check(lo)) lo = hi;
         break;
      }
      int mid = (lo+hi) >> 1;
      if(check(mid)) hi = mid;
      else lo = mid;
      //cout << lo << endl;
   }
   ret = min(ret, lo);
   printf("Case #%d: %d\n", caseno, ret);

   return;
}

int main()
{
   READ("B-small-attempt1.in");
   WRITE("soln.out");
   int t = 1, caseno = 1;
   si(t);
   while(caseno <= t) main_(caseno++);
   return 0;
}
