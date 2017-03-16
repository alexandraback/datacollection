#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int pop(int x) {
  int n = 0;
  while(x != 0) {
    n++;
    x &= (x-1);
  }
  return n;
}

bool stone[21][21];
bool out[21][21];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int paint(int h, int w) {
    memset(out, false, sizeof(out));
    queue<int> qx, qy;
    for (int x = 0; x < w; ++x) {
        if (!stone[0][x]) {
            out[0][x] = true;
            qx.push(x); qy.push(0);
        }
        if (!stone[h-1][x]) {
            out[h-1][x] = true;
            qx.push(x); qy.push(h-1);
        }
    }
    for (int y = 0; y < h; ++y) {
        if (!stone[y][0]) {
            out[y][0] = true;
            qx.push(0); qy.push(y);
        }
        if (!stone[y][w-1]) {
            out[y][w-1] = true;
            qx.push(w-1); qy.push(y);
        }
    }

    while(!qx.empty()) {
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (stone[ny][nx] || out[ny][nx]) continue;
            out[ny][nx] = true;
            qx.push(nx); qy.push(ny);
        }
    }

    int ans = 0;
    for (int y=0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            if (!out[y][x]) ans++;
    //cout<<"return "<<ans<<endl;
    return ans;
}

int solve() {
    int n, m, k;
    cin>>n>>m>>k;
    int t = n*m;

    int ans = 100;
    for (int c = 0; c < (1<<t); ++c) {
        for (int y = 0; y < n; ++y)
            for (int x = 0; x < m; ++x)
                if ((c >> (y*m + x)) & 1) stone[y][x] = true;
                else stone[y][x] = false;

        int p = paint(n, m);
        if (p == k) ans = min(ans, pop(c));
    }
    return ans;
}

int main() {
    int T, tc;
    cin>>T;
    for (tc = 1; tc <= T; ++tc) {
        cout<<"Case #"<<tc<<": ";
        cout<<solve()<<endl;
    }
}
