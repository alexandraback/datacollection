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

void main_(int caseno)
{
   int x, r, c;
   bool ret;
   si(x); sii(r, c);
   if(r > c) swap(r, c);
   switch(x) {
      case 1:
         ret = true;
         break;
      case 2:
         if((r*c) % 2 > 0) ret = false;
         else ret = true;
         break;
      case 3:
         if(r == 2 && c == 3) ret = true;
         else if(r == 3 && c >= 3) ret = true;
         else ret = false;
         break;
      case 4:
         if(r == 3 && c == 4) ret = true;
         else if(r == 4 && c == 4) ret = true;
         else ret = false;
         break;
   }
   printf("Case #%d: ", caseno);
   if(ret) puts("GABRIEL");
   else puts("RICHARD");

   return;
}

int main()
{
   READ("D-small-attempt1.in");
   WRITE("soln.out");
   int t = 1, caseno = 1;
   si(t);
   while(caseno <= t) main_(caseno++);
   return 0;
}
