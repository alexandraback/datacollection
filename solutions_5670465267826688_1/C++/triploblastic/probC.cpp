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

#define MAX 10005
// 'i' = 2, 'j' = 3, 'k' = 4
int chart[5][5] = { 0, 0, 0, 0, 0,
                    0, 1, 2, 3, 4,
                    0, 2, -1, 4, -3,
                    0, 3, -4, -1, 2,
                    0, 4, 3, -2, -1 };
// single represents the value of a single string after multiplication
// one represents the length of the cycle
int cycle, single, suffix[MAX];
Long X, L;
char S[MAX];
int mult(int x, int y)
{
   int ret = 1;
   if(x < 0) x = abs(x), ret *= -1;
   if(y < 0) y = abs(y), ret *= -1;
   return chart[x][y] * ret;
}
int tot(Long cnt)
{
   if(!cnt) return 1;
   if(cnt >= cycle) return tot(cnt % cycle);
   return mult(single, tot(cnt-1));
}
int value(int st, int en)
{
   if(en == L-1) return suffix[st];
   return mult( mult(suffix[st], suffix[en+1]), mult(suffix[en+1], suffix[en+1]) );
}

bool check(int posi, int mni, int posk, int mnk)
{
   posi = (posi+1) % L;
   posk = (posk > 0) ? posk-1 : L-1;
   int mntot, tmp;
   if(posi <= posk && value(posi, posk) == 3) {
      mntot = mni + mnk + 1;
      if(posi == 0 || posk == L-1) mntot++;
      if(mntot <= X && tot(X-mntot) == 1) return true;
   }
   REP(i, 4) {
      tmp = mult(value(posi, L-1), tot(i));
      tmp = mult(tmp, value(0, posk));
      if(tmp == 3) {
         mntot = mni+mnk+2+i;
         if(posi == 0) mntot++;
         if(posk == L-1) mntot++;
         if(mntot <= X && tot(X-mntot) == 1) return true;
      }
   }
   return false;
}

void main_(int caseno)
{
   bool ret = false;
   sll(L, X);
   scanf("%s", S);
   single = 1;
   for(int i = L-1; i >= 0; i--) {
      single = mult(S[i]-'i'+2, single);
      suffix[i] = single;
   }
   if(single == 1) cycle = 1;
   else if(single == -1) cycle = 2;
   else cycle = 4;

   int val1;
   REP(i, L) {
      int mni = -1;
      val1 = value(0, i);
      REP(j, 4) if(mult(tot(j), val1) == 2) {
         mni = j;
         break;
      }
      if(mni == -1) continue;
      REP(j, L) {
         int mnk = -1;
         val1 = value(j, L-1);
         REP(k, 4) if(mult(val1, tot(k)) == 4) {
            mnk = k;
            break;
         }
         if(mnk == -1) continue;
         ret |= check(i, mni, j, mnk);
         //cout << i << ' ' << j << endl;
      }
   }
   printf("Case #%d: ", caseno);
   if(ret) puts("YES");
   else puts("NO");

   return;
}

int main()
{
   READ("C-large.in");
   WRITE("soln.out");
   int t = 1, caseno = 1;
   si(t);
   while(caseno <= t) main_(caseno++);
   return 0;
}
