#include <bits/stdc++.h>

using namespace std;

void test() {
    int K, C, S;
    scanf("%d %d %d", &K, &C, &S);
    long long x = 0;
    int c = 0;
    int students = 0;
    vector<long long> ans;
    for (int i = 0; i < K; i++) {
        x += i;
        c++;
        if (c == C) {
            c = 0;
            ans.push_back(x);
            x = 0;
            students++;
            if (students == S && i < K - 1) {
                printf("IMPOSSIBLE\n");
                return;
            }
        } else {
            if (i == K - 1) {
                while (c < C) {
                    x *= K;
                    c++;
                }
                ans.push_back(x);
            }
            x *= K;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        printf("%lld ", ans[i] + 1);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tests = 1; tests <= t; tests++) {
        printf("Case #%d: ", tests);
        test();
    }
    return 0;
}