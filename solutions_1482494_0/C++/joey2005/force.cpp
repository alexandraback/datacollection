#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <complex>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;

const int maxn = 1024;

int a[maxn], b[maxn], n;
int score[maxn];

void main2() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
    }
    vector<pair<int, int> > data;
    for (int i = 0; i < n; ++i) {
        data.push_back(make_pair(a[i], -(i + 1)));
        data.push_back(make_pair(b[i], i + 1));
    }
    sort(data.begin(), data.end());
    int ans = 1<<30;
    for (int mask = 0; mask < 1 << n; ++mask) {
        int now = 0;
        int N = 0;
        int flag = 1;
        /*
        if (mask == (1<<7)+(1<<9)+(1<<8)+(1<<4)+(1<<5)+(1<<2)) {
            cout << "!!!" << endl;
        }
        */
        for (int i = 0; i < n; ++i) score[i] = 2;
        for (int i = 0; i < data.size(); ++i) {
            int id = abs(data[i].second) - 1;
            if (data[i].second > 0) {
                if (b[id] > now) {
                    flag = 0;
                    break;
                }
                /*
                if (mask == (1<<7)+(1<<9)+(1<<8)+(1<<4)+(1<<5)+(1<<2)) {
                    cout << id << " level2" << endl;
                }
                */
                N++;
                now += score[id];
            } else {
                if (now >= a[id] && (mask & 1 << id)) {
                    /*
                    if (mask == (1<<7)+(1<<9)+(1<<8)+(1<<4)+(1<<5)+(1<<2)) {
                        cout << id << " level1" << endl;
                    }
                    */
                    now += 1;
                    score[id] = 1;
                }
            }
        }
        if (flag && N == n) {
            ans = min(ans, __builtin_popcount(mask) + n);
        }
    }

    if (ans > 10000) {
        printf("Too Bad\n");
    } else {
        printf("%d\n", ans);
    }
}

int main() {
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B2.out", "w", stdout);
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    int testCnt;
    scanf("%d", &testCnt);
    for (int caseId = 1; caseId <= testCnt; ++caseId) {
        printf("Case #%d: ", caseId);
        main2();
    }
}

