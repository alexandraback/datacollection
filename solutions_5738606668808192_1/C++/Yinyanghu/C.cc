#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxN = 32 + 1;
const int P = 15;
const int maxB = 10 - 1;

int N, J;

int f[maxN][maxB][P];

int bits[maxN];

const int Prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int found;

void search(int k) {
    if (k > N) {
        vector<int> divisors;
        for (int b = 2; b <= 10; ++ b) {
            bool flag = false;
            for (int p = 0; p < P; ++ p)
                if (f[N][b - 2][p] == 0) {
                    divisors.push_back(Prime[p]);
                    flag = true;
                    break;
                }
            if (!flag) return;
        }

        for (int i = 1; i <= N; ++ i)
            printf("%d", bits[i]);
        for (int i = 0; i < divisors.size(); ++ i)
            printf(" %d", divisors[i]);
        printf("\n");
        ++ found;
        return;
    }
    if (k != 1 && k != N) {
        bits[k] = 0;
        for (int b = 2; b <= 10; ++ b)
            for (int p = 0; p < P; ++ p)
                f[k][b - 2][p] = (f[k - 1][b - 2][p] * b) % Prime[p];
        search(k + 1);
    }
    if (found >= J) return;
    bits[k] = 1;
    for (int b = 2; b <= 10; ++ b)
        for (int p = 0; p < P; ++ p)
            f[k][b - 2][p] = (f[k - 1][b - 2][p] * b + 1) % Prime[p];
    search(k + 1);
}

int main() {
    int T = 1;
    //scanf("%d", &T);
    for (int test = 1; test <= T; ++ test) {
        N = 32;
        J = 500;
        /*
        N = 16;
        J = 50;
        */
        memset(f, 0, sizeof(f));
        printf("Case #%d:", test);
        printf("\n");
        found = 0;
        search(1);
    }
    return 0;
}
