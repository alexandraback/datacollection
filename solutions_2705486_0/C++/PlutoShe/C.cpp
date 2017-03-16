#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long LL;
long long f[200][8];
int a[200];
char s[530000][1000];
char ss[2000];

int max(int a, int b) {
    return (a > b ? a : b);
}


int main() {
    freopen("dictionary.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 1;
    while (gets(s[n])) {
        a[n] = strlen(s[n]);
        //cout << s[n] << endl;
        n++;
    }
    n--;
    while (a[n] == 0) n--;
    freopen("input.txt", "r", stdin);
    //cout << 1 << endl;
    int test;
    cin >> test; gets(ss);
    for (int tt = 1; tt <= test; tt++) {
        gets(ss);
        //cout << ss << endl;
        memset(f, 63, sizeof(f));
        f[0][5] = 0;
        f[0][1] = 0;
        f[0][2] = 0;
        f[0][3] = 0;
        f[0][4] = 0;
        int ans = 0;
        int len = strlen(ss);
        for (int i = 0; i < len; i++) {
            for (int k = 1; k <= 5; k++) {
              //  cout << i << ' ' << k <<  ' ' << f[i][k] << endl;
                  if (f[i][k] <= 1000000) {
                    for (int j = 1; j <= n; j++) {
                        if (a[j] + i <= len) {
                            int t = k, rt = 0;
                            bool u = true;
                            for (int l = 0; l < a[j]; l++) {
                                t++;
                                if (s[j][l] != ss[i + l]) {
                                    if (t > 5) {
                                        t = 1;
                                        rt++;
                                    } else { u = false; break;}
                                }
                            }
                            if (u) {
                                //cout << "!!!!!!!!!!!!!J" << j << endl;
                                if (t > 5) t = 5;
                                if (rt + f[i][k] < f[i + a[j]][t])
                                    f[i + a[j]][t] = rt + f[i][k];
                            }
                        }
                    }
                }
            }
        }
        ans = 1000000000;
        for (int i = 1; i <= 5; i++)
            if (f[len][i] < ans) ans = f[len][i];
        printf("Case #%d: %d\n", tt, ans);
    }
}
