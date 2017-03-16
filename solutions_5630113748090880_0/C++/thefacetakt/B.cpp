#include "bits/stdc++.h"

using namespace std;


struct Sol {
    vector <int> result;

    vector <vector <int> > a;
    int column;
    int dual;
    void solution(vector <int> &b) {
        int n = (b.size() + 1) / 2;
        int I = max_element(b.begin(), b.end(),
                            [this, &n] (int x, int y) {
                                return a[x][n - 1] < a[y][n - 1];
                            }
                        ) - b.begin();
        int maxCount = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            if (a[b[i]][n - 1] == a[b[I]][n - 1]) {
                ++maxCount;
            }
        }
        if (maxCount == 2) {
            int maxx = a[b[I]][n - 1];
            swap(b[I], b.back());
            b.pop_back();
            for (int i = 0; i < b.size(); ++i) {
                if (a[b[i]][n - 1] == maxx) {
                    swap(b[i], b.back());
                    b.pop_back();
                    break;
                }
            }
            solution(b);
            return;
        } else {
            column = n - 1;
            dual = b[I];
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        vector <int> b;
        a.assign(2 * n - 1, vector<int>(n));
        for (int i = 0; i < 2 * n - 1; ++i) {
            b.push_back(i);
            for (int j = 0; j < n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        solution(b);

        vector <int> tails;
        tails.push_back(a[dual][column]);
        for (int i = 0; i < 2 * n - 1; ++i) {
            tails.push_back(a[i][column]);
        }
        sort(tails.begin(), tails.end());
        int i1 = 0, i2 = 0;
        while (result.size() < n) {
            if (i2 < a[dual].size() && tails[i1] == a[dual][i2]) {
                ++i1;
                ++i2;
                continue;
            }
            result.push_back(tails[i1]);
            ++i1;
        }

        for (int i = 0; i < result.size(); ++i) {
            printf("%d ", result[i]);
        }
        printf("\n");
        return 0;
    }
};

int main() {
    int T;
    scanf("%d", &T);
    for (int z = 1; z <= T; ++z) {
        printf("Case #%d: ", z);
        Sol().main();
    }
    return 0;
}
