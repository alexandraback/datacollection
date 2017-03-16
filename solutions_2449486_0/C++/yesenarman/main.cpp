#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N,M;
int a[111][111];

bool row_ok(int r, int h) {
    for (int i=0; i<M; ++i)
        if (a[r][i]>h) return false;
    return true;
}

bool col_ok(int c, int h) {
    for (int i=0; i<N; ++i)
        if (a[i][c]>h) return false;
    return true;
}

void solve(int testcase) {
    printf("Case #%d: ", testcase);

    cin >> N >> M;
    for (int i=0; i<N; ++i)
        for (int j=0; j<M; ++j)
            cin >> a[i][j];

    for (int i=0; i<N; ++i)
        for (int j=0; j<M; ++j) 
            if (!row_ok(i, a[i][j]) && !col_ok(j, a[i][j])) {
                puts("NO");
                return;
            }
    puts("YES");
}

int main() {
    int T;
    cin >> T;
    for (int i=1; i<=T; ++i)
        solve(i);
    return 0;
}
