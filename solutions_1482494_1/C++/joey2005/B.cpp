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
bool used[maxn];

void main2() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
    }
    vector<pair<int, int> > A, B;
    for (int i = 0; i < n; ++i) {
        A.push_back(make_pair(a[i], i));
        B.push_back(make_pair(b[i], i));
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    set<pair<int, int> > sa;
    set<pair<int, int> > sb;
    for (int i = 0; i < n; ++i) score[i] = 2;
    int now = 0;
    int ans = 0;
    memset(used, false, sizeof used);
    for (int step = 0, i = 0, j = 0; step < n; ) {
        while (i < B.size() && B[i].first <= now) {
            sb.insert(B[i]);
            i++;
        }
        while (!sb.empty()) {
            now += score[sb.begin()->second];
            used[sb.begin()->second] = true;
            step++;
            sb.erase(sb.begin());
            while (i < B.size() && B[i].first <= now) {
                sb.insert(B[i]);
                i++;
            }
        }
        if (step == n) break;
        while (j < A.size() && A[j].first <= now) {
            if (!used[A[j].second]) {
                sa.insert(make_pair(-b[A[j].second], A[j].second));
            }
            j++;
        }
        if (!sa.empty()) {
            do {
                if (!used[sa.begin()->second]) {
                    break;
                }
                sa.erase(sa.begin());
            } while (!sa.empty());
            if (!sa.empty()) {
                now += 1;
                score[sa.begin()->second] = 1;
                sa.erase(sa.begin());
                ans++;
                while (j < A.size() && A[j].first <= now) {
                    if (!used[A[j].second]) {
                        sa.insert(make_pair(-b[A[j].second], A[j].second));
                    }
                    j++;
                }
            }
        }
        if (i < n && B[i].first > now && sa.empty()) {
            printf("Too Bad\n");
            return;
        }
    }

    printf("%d\n", ans + n);
}

int main() {
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B2.out", "w", stdout);
    //freopen("B-small-attempt2.in", "r", stdin);
    //freopen("B-small-attempt2.out", "w", stdout);
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int testCnt;
    scanf("%d", &testCnt);
    for (int caseId = 1; caseId <= testCnt; ++caseId) {
        printf("Case #%d: ", caseId);
        main2();
    }
}

