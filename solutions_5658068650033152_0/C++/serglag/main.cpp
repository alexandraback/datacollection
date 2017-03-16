#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;
const ll mod = 1000000007;

bool visited[20][20];
bool stone[20][20];

int n, m;

void dfs(int row, int col) {
    if(row < 0 || row >= n || col < 0 || col >= m)
        return;

    if(stone[row][col])
        return;

    if(!visited[row][col]) {
        visited[row][col] = true;

        dfs(row, col-1);
        dfs(row, col+1);
        dfs(row-1, col);
        dfs(row+1, col);
    }
}

void clear() {
    for(int i = 0; i < 20; ++i)
        for(int j = 0; j < 20; ++j) {
            visited[i][j] = false;
            stone[i][j] = false;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    
    fstream in("D:\\input.txt");
    fstream out("D:\\output.txt");

    int t;
    in >> t;

    for(int q = 1; q <= t; ++q) {
        int k; 
        in >> n >> m >> k;

        int ans = k;
        int A = (1 << (n*m));

        for(int i = 0; i < A; ++i) {
            clear();

            int mask = i;
            int num_stones = 0;
            for(int j = 0; j < n*m; ++j) {
                if(mask & (1 << j)) {
                    int r = j / m;
                    int c = j % m;

                    stone[r][c] = true;
                    ++num_stones;
                }
            }

            if(num_stones >= ans)
                continue;

            for(int y = 0; y < n; ++y) {
                dfs(y, 0);
                dfs(y, m-1);
            }

            for(int y = 0; y < m; ++y) {
                dfs(0, y);
                dfs(n-1, y);
            }

            int not_visited = 0;
            for(int r = 0; r < n; ++r) 
                for(int c = 0; c < m; ++c) {
                    if(!visited[r][c])
                        ++not_visited;
                }

            if(not_visited >= k) {
                if(ans > num_stones) {
                    ans = num_stones;
                }
            }
        }

        out << "Case #" << q << ": " << ans << endl;
    }

    return 0;
} 