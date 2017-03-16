#include <cstdlib>
#include <climits>
#include <sstream>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>

// STL
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <list>
#include <stack>


using namespace std;

int yard[100][100];
int max_row[100];
int max_col[100];

bool solve(int N, int M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (yard[i][j] != max_row[i] && yard[i][j] != max_col[j])
                return false;
        }
    }
    return true;
}


int main() {
    int numcase, N, M;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> N >> M;
        memset(max_row, 0, sizeof(int)*N);
        memset(max_col, 0, sizeof(int)*M);
        for  (int j = 0; j < N; ++j) {
            for  (int k = 0; k < M; ++k) {
                int tmp;
                cin >> tmp;
                yard[j][k] = tmp;
                if (tmp > max_row[j]) max_row[j] = tmp;
                if (tmp > max_col[k]) max_col[k] = tmp;
            }
        }
        cout << "Case #" << i + 1 << ": ";
        if (solve(N, M))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
