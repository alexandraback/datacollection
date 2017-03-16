#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

pair<int, int> v[1 << 15];

int a[1 << 7][1 << 7];
int col[1 << 7];
int row[1 << 7];

string solve(){
    int n , m;
    cin >> n >> m;
    memset(col, 0, sizeof(col));
    memset(row, 0, sizeof(row));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            cin >> a[i][j];
            if (a[i][j] > row[i])
                row[i] = a[i][j];
            if (a[i][j] > col[j])
                col[j] = a[i][j];
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] < row[i] && a[i][j] < col[j])
                return "NO";
    return "YES";
}


int main(){
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        cout << "Case #" << i << ": " << solve() << endl;
    return 0;
}
