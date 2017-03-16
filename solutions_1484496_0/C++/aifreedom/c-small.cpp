#include <iostream>
using namespace std;
const int maxn = 21;
int n;
int a[maxn];
int s[maxn];
void init()
{
     memset(s, 0, sizeof(s));
     cin >> n;
     for (int i=0; i<n; i++) {
          cin >> a[i];
     }
}

bool calc(int l)
{
     if (l == n) {
          // for (int i=0; i<n; i++) {
          //      cout << s[i] << ' ';
          // }
          // cout << endl;
          int s1 = 0, s2 = 0;
          for (int i=0; i<n; i++) {
               if (s[i] == 1) {
                    s1 += a[i];
               } else if (s[i] == 2) {
                    s2 += a[i];
               }
          }
          // cout << s1 << ' ' << s2 << endl;
          if (s1 == s2 && s1 != 0) {
               bool first = true;
               for (int j=0; j<n; j++) {
                    if (s[j] == 1) {
                         if (first) {
                              first = false;
                         } else {
                              cout << ' ';
                         }
                         cout << a[j];
                    }
               }
               cout << endl;
               first = true;
               for (int j=0; j<n; j++) {
                    if (s[j] == 2) {
                         if (first) {
                              first = false;
                         } else {
                              cout << ' ';
                         }
                         cout << a[j];
                    }
               }
               cout << endl;
               // cout << "hrer" << endl;
               return true;
          }
     } else {
          s[l] = 0;
          if (calc(l+1)) {
               return true;
          }
          s[l] = 1;
          if (calc(l+1)) {
               return true;
          }
          s[l] = 2;
          if (calc(l+1)) {
               return true;
          }
     }
     return false;
}

int main()
{
     int T;
     cin >> T;
     for (int t=1; t<=T; t++) {
          init();
          cout << "Case #" << t << ":" << endl;
          bool f = calc(0);
          if (!f) {
               cout << "Impossible" << endl;
          }
          // cout << f << endl;
     }
     return 0;
}
