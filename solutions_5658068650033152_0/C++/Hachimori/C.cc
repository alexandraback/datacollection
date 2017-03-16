#include<iostream>
using namespace std;
const int BUF = 25;

int row, col, K;

void read() {
    cin >> row >> col >> K;
}


void dfs(int r, int c, bool visited[BUF][BUF], bool toPut[BUF][BUF]) {
    static int dr[] = {-1, 0, 1,  0};
    static int dc[] = { 0, 1, 0, -1};

    visited[r][c] = true;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i], nc = c + dc[i];
        if (!(0 <= nr && nr < row && 0 <= nc && nc < col)) continue;
        if (toPut[nr][nc] || visited[nr][nc]) continue;
        dfs(nr, nc, visited, toPut);
    }
}


void work(int cases) {
    int ans = 1<<20;

    for (int mask = 0; mask < (1 << (row * col)); ++mask) {
        bool toPut[BUF][BUF];
        for (int r = 0; r < row; ++r)
            for (int c = 0; c < col; ++c)
                toPut[r][c] = mask & (1 << (r * col + c));
        
        bool visited[BUF][BUF] = {};
        for (int r = 0; r < row; ++r)
            for (int c = 0; c < col; ++c) {
                if (!(r == 0 || r == row - 1 || c == 0 || c == col - 1))
                    continue;
                if (visited[r][c] || toPut[r][c])
                    continue;
                
                dfs(r, c, visited, toPut);
            }
        
        int cnt = 0;
        for (int r = 0; r < row; ++r)
            for (int c = 0; c < col; ++c)
                cnt += !visited[r][c];
        
        if (cnt >= K)
            ans = min(ans, __builtin_popcount(mask));
    }

    cout << "Case #" << cases << ": " << ans << endl;
}


int main() {
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; ++i) {
        read();
        work(i + 1);
    }
    return 0;
}
