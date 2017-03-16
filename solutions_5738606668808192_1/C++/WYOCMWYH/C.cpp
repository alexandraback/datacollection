#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> ans{3, 2, 3, 2, 5, 2, 3, 2, 3};
vector<int> sk(10);
vector<int> num(32);

void get_next() {
    for (int i = 9; i >= 0; --i) {
        if (sk[i] == 5 + i) continue;
        sk[i]++;
        for (int j = i + 1; j < 9; ++j) sk[j] = sk[j - 1] + 1;
        return;
    }
}

void p_ans() {
    num.assign(32, 1);
    for (int i = 0; i < 7; ++i) {
        num[1 + 2 * sk[i]] = num[2 + 2 * sk[i]] = 0;
    }
    for (int i = 7; i < 10; ++i) {
        num[1 + 2 * sk[i]] = 0;
    }
    for (int i = 0; i < 32; ++i) {
        printf("%d", num[i]);
    }
    for (int i = 0; i < 9; ++i) {
        printf(" %d", ans[i]);
    }
    printf("\n");
    num.assign(32, 1);
    for (int i = 0; i < 7; ++i) {
        num[1 + 2 * sk[i]] = num[2 + 2 * sk[i]] = 0;
    }
    for (int i = 7; i < 10; ++i) {
        num[2 + 2 * sk[i]] = 0;
    }
    for (int i = 0; i < 32; ++i) {
        printf("%d", num[i]);
    }
    for (int i = 0; i < 9; ++i) {
        printf(" %d", ans[i]);
    }
    printf("\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    printf("Case #1:\n");
    int j = 500;
    for (int i = 0; i < 10; ++i) sk[i] = i;
    for (int i = 0; i < 500; ++i) {
        p_ans();
        get_next();
        j -= 2;
        if (!j) break;
    }
}
