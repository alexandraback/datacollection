#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>
using namespace std;

const int MAXN = 1000;

typedef pair<int, int> pii;
pii vec[MAXN];
int used[MAXN];

const string Bad = "Too Bad";

int main() {
    int nTest;
    scanf("%d", &nTest);
    for (int test = 1; test <= nTest; ++test) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            vec[i] = pii(a, b);
        }
        int ret = 0;
        memset(used, 0, sizeof used);
        int done = 0;
        int curr = 0;
        while (done < n) {
            int best = -1;
            for (int i = 0; i < n; ++i) {
                if (used[i] >= 2) continue;
                if (curr >= vec[i].second) {
                    best = i;
                    break;
                }
                if (curr >= vec[i].first) {
                    bool todo = false;
                    if (best == -1) {
                        todo = true;
                    }
                    else {
                        if (vec[best].second < vec[i].second) {
                            todo = true;
                        }
                    }
                    if (used[i] >= 1) todo = false;
                    if (todo) {
                        best = i;
                    }
                }
            }
            if (best == -1) {
                ret = -1;
                break;
            }
            else {
                ++ret;
                if (curr >= vec[best].second) {
                    curr += (2 - used[best]);
                    used[best] = 2;
                    ++done;
                }
                else {
                    curr += 1;
                    used[best] = 1;
                }
            }
        }
        if (ret != -1)
            printf("Case #%d: %d\n", test, ret);
        else
            cout << "Case #" << test << ": " << Bad << endl;
    }
    return 0;
}
