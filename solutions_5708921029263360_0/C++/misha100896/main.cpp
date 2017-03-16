#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int m[3][100000], m1[3][100050];
int A[20][20];
int B[20][20];
int C[20][20];
bool used[10][10][10];
int kol, kol1;
int a, b, c, k;
mt19937 mt_rand(time(NULL));

void MYRANDOM() {
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            for (int k = 0; k < c; ++k)
                used[i][j][k] = false;
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            A[i][j] = 0;
    for (int i = 0; i < b; ++i)
        for (int j = 0; j < c; ++j)
            B[i][j] = 0;
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < c; ++j)
            C[i][j] = 0;
    kol1 = 1;
    m1[0][0] = mt_rand() % a;
    m1[1][0] = mt_rand() % b;
    m1[2][0] = mt_rand() % c;
    A[m1[0][0]][m1[1][0]]++;
    B[m1[1][0]][m1[2][0]]++;
    C[m1[0][0]][m1[2][0]]++;
    used[m1[0][0]][m1[1][0]][m1[2][0]] = true;
    int xx = 0;

    while (A[m1[0][kol1 - 1]][m1[1][kol1 - 1]] <= k && B[m1[1][kol1 - 1]][m1[2][kol1 - 1]] <= k && C[m1[0][kol1 - 1]][m1[2][kol1 - 1]] <= k) {
        m1[0][kol1] = mt_rand() % a;
        m1[1][kol1] = mt_rand() % b;
        m1[2][kol1] = mt_rand() % c;
        if (used[m1[0][kol1]][m1[1][kol1]][m1[2][kol1]]) {
            ++xx;
            if (xx > 10)
                break;
            continue;
        }
        xx = 0;
        used[m1[0][kol1]][m1[1][kol1]][m1[2][kol1]] = true;
        A[m1[0][kol1]][m1[1][kol1]]++;
        B[m1[1][kol1]][m1[2][kol1]]++;
        C[m1[0][kol1]][m1[2][kol1]]++;
        ++kol1;
    }
    if (xx <= 10)
        --kol1;
    if (kol1 > kol) {
        kol = kol1;
        for (int i = 0; i < kol1; ++i) {
            for (int j = 0; j < 3; ++j)
                m[j][i] = m1[j][i] + 1;
        }
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int t;
    cin >> t;
    for (int x = 0;  x < t; ++x) {
        cout << "Case #" << x + 1 << ": ";
        cin >> a >> b >> c >> k;
        if (a * b * c == 1) {
            cout << 1 << '\n';
            cout << 1 << ' ' << 1 << ' ' << 1 << '\n';
            continue;
        }
        kol = 0;
        for (int i = 0; i < 300000; ++i) {
            MYRANDOM();
        }
        cerr << x << '\n';
        cout << kol << '\n';
        for (int i = 0; i < kol; ++i)
            cout << m[0][i] << ' ' << m[1][i] << ' ' << m[2][i] << '\n';
    }
    return 0;
}
