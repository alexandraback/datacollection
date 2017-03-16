#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool vis[1000008];
int n;

int reverseDigit(int x)
{
    char ch[100] = {0};
    int pos = 0;
    while (x) {
        ch[pos++] = x % 10;
        x /= 10;
    }
    int y = 0;
    for (int i = 0; i < pos; i++) {
        y = y * 10;
        y += ch[i];
    }
    return y;
}
int bfs()
{
    queue<pair<int, int> > q;
    pair<int, int> x;
    int y;
    memset(vis, false, sizeof vis);
    vis[1] = true;
    q.push(make_pair(1, 1));
    while (!q.empty()) {
        x = q.front();
        q.pop();
        if (x.first == n) {
            return x.second;
        }
        if (vis[x.first + 1] == false) {
            vis[x.first + 1] = true;
            q.push(make_pair(x.first + 1, x.second + 1));
        }
        y = reverseDigit(x.first);
        if (y > n * 10) {
            puts("error");
            continue;
        }
        if (vis[y] == false) {
            vis[y] = true;
            q.push(make_pair(y, x.second + 1));
        }
    }
    return -1;
}
void work()
{
    scanf("%d", &n);
    cout << bfs() << endl;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        work();
    }
    return 0;
}