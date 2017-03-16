#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()

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
int L, X, n;
int mul1[10005], mul2[10005];
vector <int> a, b;

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

string solve() {
   a.clear();
   b.clear();
   mul1[0] = 1;
   for (int i = 1; i <= n; i++) {
      mul1[i] = mult(mul1[i-1], s[i] - 'g');
      if (mul1[i] == 2) a.pb(i);
   }
   mul2[n+1] = 1;
   for (int i = n; i >= 1; i--) {
      mul2[i] = mult(s[i] - 'g', mul2[i+1]);
      if (mul2[i] == 4) b.pb(i);
   }
   for (int i = 0; i < sz(a); i++)
   for (int j = 0; j < sz(b); j++) {
      int x = a[i], y = b[j];
      if (x > y) break;
      if (divv(mul1[y-1], mul1[x]) == -3) return "YES";
   }
   return "NO";
}

int main() {
   freopen("C-small-attempt1.in", "r", stdin);
   freopen("output.txt", "w", stdout);

   ios::sync_with_stdio(false);
   int nTest; cin >> nTest;
   for (int t = 1; t <= nTest; t++) {
      cin >> L >> X >> ss;
      n = L * X;
      for (int i = 1; i <= n; i++)
         s[i] = ss[(i-1)%L];
      cout << "Case #" << t << ": " << solve() << endl;
   }

   return 0;
}
