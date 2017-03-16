#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int Q[5][5] = { 
{0, 0, 0, 0, 0},
{0, 1, 2, 3, 4},
{0, 2, -1, 4, -3},
{0, 3, -4, -1, 2},
{0, 4, 3, -2, -1}};
 
int test, L, f[10011], v[10011], c[10011][2], r[10011][2], w[10011][10011];
long long X;
char str[100001];
bool b[10001][5][2];

int calc(int i){
     if (i == '1') return 1;
     if (i == 'i') return 2;
     if (i == 'j') return 3;
     return 4;
}

int get(int i, int j){
     bool positive = true;
     if (i < 0) i = -i, positive ^= 1;
     if (j < 0) j = -j, positive ^= 1;
     if (positive) return Q[i][j];
     else return -Q[i][j];
}

int rp(int now, long long k){
     int will = 1;
     for (; k; k >>= 1, now = get(now, now))
          if (k & 1) will = get(will, now);
     return will;
}

int main(){
     freopen("c.in", "r", stdin);
     freopen("c.out", "w", stdout);
     scanf("%d", &test);
     for (int uu = 1; uu <= test; uu++)
     {
          printf("Case #%d: ", uu);
          scanf("%d%I64d%s", &L, &X, str);
          for (int i = 0; i <= L + 1; i++) 
               for (int j = 0; j <= L + 1; j++) w[i][j] = 1;
          for (int i = 1; i <= L; i++)
               for (int j = i; j <= L; j++) w[i][j] = get(w[i][j - 1], calc(str[j - 1]));
          cerr << L << " " << X << endl;
          f[0] = 1;
          for (int i = 1; i <= L; i++)
               f[i] = get(f[i - 1], calc(str[i - 1]));
          v[L + 1] = 1;
          for (int i = L; i; --i)
               v[i] = get(calc(str[i - 1]), v[i + 1]);
          memset(b, false, sizeof(b));
          int now = 1, cnt1 = 0;
          for (int i = 1, j = 1; i <= L * X; i++, j++) 
          {
               if (j > L) j = 1;
               now = get(now, calc(str[j - 1]));
               int status = 0;
               if (now < 0) status = 1;
               if (b[j][abs(now)][status]) break;
               if (now == 2) c[++cnt1][0] = i, c[cnt1][1] = j;
          }
          memset(b, false, sizeof(b));
          now = 1; int cnt2 = 0;
          for (int i = 1, j = L; i <= L * X; i++, --j)
          {
               if (j == 0) j = L;
               now = get(calc(str[j - 1]), now);
               int status = 0;
               if (now < 0) status = 1;
               if (b[j][abs(now)][status]) break;
               if (now == 4) r[++cnt2][0] = i, r[cnt2][1] = j;
          }
          bool ok = false;
          cerr << cnt1 << " " << cnt2 << endl;
          for (int i = 1; i <= cnt1 && !ok; i++)
               for (int j = 1; j <= cnt2 && !ok; j++)
                    if (c[i][0] + r[j][0] <= L * X)
                    {
                         if ((L * X - (L - c[i][1] + c[i][0] + r[j][1] - 1 + r[j][0])) >= 0)
                         {
                         int now = v[c[i][1] + 1],
                         Mid = rp(f[L], (L * X - (L - c[i][1] + c[i][0] + r[j][1] - 1 + r[j][0])) / L);
                         now = get(now, Mid);
                         now = get(now, f[r[j][1] - 1]);
                         if (now == 3) ok = true;
                         }
                         else
                         {
                              int now = w[c[i][1] + 1][r[j][1] - 1];
                              if (now == 3) ok = true;
                         }
                    }
          if (ok) printf("YES\n");
          else printf("NO\n");
     }
}

          
     
     
