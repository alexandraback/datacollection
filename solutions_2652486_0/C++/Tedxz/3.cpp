#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <map>
#include <ctime>

using namespace std;

int T, p[15];
map <int, int> mp3, mp2, mp1;
int r, n, m, k, flag;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("c.out", "w", stdout);
    srand(time(NULL));
    mp3[18] = 233; mp3[24] = 234; mp3[27] = 333; mp3[30] = 235; mp3[32] = 244;
    mp3[36] = 344; mp3[40] = 245; mp3[45] = 533; mp3[48] = 443; mp3[50] = 255;
    mp3[60] = 345; mp3[64] = 444; mp3[75] = 355; mp3[80] = 445; mp3[100] = 455;
    mp3[125] = 555;
    
    mp2[6] = 23; mp2[9] = 33; mp2[10] = 25; mp2[15] = 35; mp2[25] = 55;
    
    mp1[2] = 2; mp1[3] = 2; mp1[5] = 2;
    
    cin >> T;
    cout << "Case #1: " << endl;
    cin >> r >> n >> m >> k;
    for (int i = 1; i <= r; ++i) {
        flag = 0;
        for (int j = 0; j < k; ++j)
            cin >> p[j];
        for (int j = 0; j < k && flag < n; ++j) {
            if (mp3.count(p[j])) {
                cout << mp3[p[j]];
                flag = 3;
                break;
            }
        }
        for (int j = 0; j < k && flag < n; ++j) {
            if (mp2.count(p[j])) {
                cout << mp2[p[j]];
                for (int q = 0; q < k; ++q)
                    if (j != q) p[q] /= gcd(p[j], p[q]);
                p[j] = 1;
                flag = 2;
                break;
            }
        }
        for (int j = 0; j < k && flag < n; ++j) {
            if (mp1.count(p[j])) {
                cout << mp1[p[j]];
                for (int q = 0; q < k; ++q)
                    if (j != q) p[q] /= gcd(p[j], p[q]);
                p[j] = 1;
                flag++;
                break;
            }
        }
        for (int j = 0; j < k && flag < n; ++j) {
            if (mp1.count(p[j])) {
                cout << mp1[p[j]];
                for (int q = 0; q < k; ++q)
                    if (j != q) p[q] /= gcd(p[j], p[q]);
                p[j] = 1;
                flag++;
                break;
            }
        }
        for (int j = 0; j < k && flag < n; ++j) {
            if (mp1.count(p[j])) {
                cout << mp1[p[j]];
                for (int q = 0; q < k; ++q)
                    if (j != q) p[q] /= gcd(p[j], p[q]);
                p[j] = 1;
                flag++;
                break;
            }
        }
        while (flag++<n) {
            cout << rand() % (m - 1) + 2;
        } 
        cout << endl;
        
    }    
    return 0;
}

