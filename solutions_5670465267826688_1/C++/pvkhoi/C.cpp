#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()

typedef long long ll;

const int mulTable[4][4] =
{
{1, 2, 3, 4},
{2, -1, 4, -3},
{3, -4, -1, 2},
{4, 3, -2, -1}
};

const int divTable[4][4] =
{
{1, -2, -3, -4},
{2, 1, -4, 3},
{3, 4, 1, -2},
{4, -3, 2, 1}
};

char s[10005];
string ss;
int L, n;
ll X;
int mul1[10005], mul2[10005], mul3[10005];
vector <int> a, b, c, d;

int mult(int x, int y) {
   int sign1 = 1, sign2 = 1;
   if (x < 0) sign1 = -1, x = -x;
   if (y < 0) sign2 = -1, y = -y;
   return sign1 * sign2 * mulTable[x-1][y-1];
}

int divv(int x, int y) {
   int sign1 = 1, sign2 = 1;
   if (x < 0) sign1 = -1, x = -x;
   if (y < 0) sign2 = -1, y = -y;
   return sign1 * sign2 * divTable[x-1][y-1];
}

bool ok(int x, int y) {
   a.clear();
   b.clear();
   mul1[0] = c[x];
   if (x > 0 && mul1[0] == 2) a.pb(0);
   for (int i = 1; i <= L; i++) {
      mul1[i] = mult(mul1[i-1], s[i] - 'g');
      if (mul1[i] == 2) a.pb(i);
   }
   mul2[L+1] = c[(X-x-1)%sz(c)];
   for (int i = L; i >= 1; i--) {
      mul2[i] = mult(s[i] - 'g', mul2[i+1]);
      if (mul2[i] == 4) b.pb(i);
   }
   if (y == 0) {
      for (int i = 0; i < sz(a); i++)
      for (int j = 0; j < sz(b); j++) {
         int ii = a[i], jj = b[j];
         if (ii > jj) break;
         if (divv(mul1[jj-1], mul1[ii]) == -3) return true;
      }
   }
   else {
      b.clear();
      mul3[L+1] = c[(X-x-1-y)%sz(c)];
      if (X-x-1-y > 0 && mul3[L+1] == 4) b.pb(L+1);
      for (int i = L; i >= 1; i--) {
         mul3[i] = mult(s[i] - 'g', mul3[i+1]);
         if (mul3[i] == 4) b.pb(i);
      }
      mul2[L+1] = 1;
      for (int i = L; i >= 1; i--) {
         mul2[i] = mult(s[i] - 'g', mul2[i+1]);
      }
      for (int i = 0; i < sz(a); i++)
      for (int j = 0; j < sz(b); j++) {
         int ii = a[i], jj = b[j];
         int xx = mul2[ii+1];
         xx = mult(xx, c[y-1]);
         xx = mult(xx, mult(divv(mul3[1], mul3[jj]), 1));
         if (xx == 3) return true;
      }
   }
   return false;
}

string solve() {
   mul1[0] = 1;
   for (int i = 1; i <= L; i++) {
      mul1[i] = mult(mul1[i-1], s[i] - 'g');
   }
   int cycle = mul1[L];
   c.clear();
   c.pb(1);
   for (int i = 1; i < X && cycle != 1; cycle = mult(cycle, mul1[L]), i++)
      c.pb(cycle);
   for (int i = 0; i < sz(c); i++)
   for (int j = 0; j < sz(c); j++) {
      if (i+j+1 > X) break;
      if (ok(i, j))
         return "YES";
   }
   return "NO";
}

int main() {
   freopen("C-large.in", "r", stdin);
   freopen("output.txt", "w", stdout);

   ios::sync_with_stdio(false);
   int nTest; cin >> nTest;
   for (int t = 1; t <= nTest; t++) {
      cin >> L >> X >> ss;
      for (int i = 1; i <= L; i++)
         s[i] = ss[i-1];
      cout << "Case #" << t << ": " << solve() << endl;
   }

   return 0;
}
