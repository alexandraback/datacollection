// 
// 
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

int n;
int in[1000];
int best = 0;
bool check[1000];
int first;

void aaa(int left, int now, int len) {
    //cout << " --- " << now << "(" << len << ")\n";

    if (in[now] == left || in[now] == first) {
        best = max(best, len);
    }

    int next = in[now];
    if (check[next] == false) {
        check[next] = true;
        aaa(now, next, len+1);
        check[next] = false; // roll-back
    }

    if (in[now] != left) return;

    for (int i = 0; i < n; i++) {
        if (check[i] == false) {
            check[i] = true;
            aaa(now, i, len+1);
            check[i] = false; // roll-back
        }
    }
}

void solve() {
    best = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        in[i]--; // make it 0-based index
    }

    for (int i = 0; i < n; i++) {
        memset(check, 0, sizeof(check));
        first = i;

        check[i] = true;
        int next = in[i];
        check[next] = true;
        aaa(i, next, 2);
    }
    cout << best << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

