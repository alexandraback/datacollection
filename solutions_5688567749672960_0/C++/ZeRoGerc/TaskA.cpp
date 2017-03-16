#include <iostream>
#include <memory.h>
#include <deque>

using namespace std;

const int L = 10000111;
const int INF = 1000111222;

int n, T, it = 1;
deque<int> cur;
int used[L];
int ans[L];

int reverse(int x) {
    int y = 0;
    while (x != 0) {
        y = y * 10 + (x % 10);
        x /= 10;
    }
    return y;
}

void bfs() {
    cur.clear();
    cur.push_back(1);
    used[1] = true;
    
    while (!cur.empty()) {
        int v = cur.front();
        cur.pop_front();
        
        if (v + 1 < L && !used[v + 1]) {
            ans[v + 1] = ans[v] + 1;
            cur.push_back(v + 1);
            used[v + 1] = true;
        }
        int temp = reverse(v);
        if (temp < L && !used[temp]) {
            ans[temp] = ans[v] + 1;
            cur.push_back(temp);
            used[temp] = true;
        }
    }
}

int main() {
    freopen("A-small-attempt2.in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    
    it++;
    for (int i = 0; i < n; i++) {
        ans[i] = INF;
        used[i] = false;
    }
    ans[1] = 1;
    bfs();
    
    for (int I = 0; I < T; I++) {
        cin >> n;
        printf("Case #%d: %d\n", I + 1, ans[n]);
    }
}