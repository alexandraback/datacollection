#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test_amo; cin >> test_amo;
    for (int test_num = 1; test_num <= test_amo; test_num++) {
        int n; cin >> n; vector<double> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        deque<double> A, B;
        for (int i = 0; i < n; i++) A.push_back(a[i]), B.push_back(b[i]);
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (A.front() < B.front()) {
                A.pop_front();
                B.pop_back();
            } else if (A.back() > B.back()) {
                A.pop_back();
                B.pop_back();
                ++x;
            } else {
                A.pop_front();
                B.pop_front();
                ++x;
            }
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && b[j] < a[i]) j++;
            if (j < n) {
                j++;
            } else {
                y++;
            }
        }
        printf("Case #%d: ", test_num);
        printf("%d %d\n", x, y);
    }
    return 0;
}
