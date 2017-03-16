// David Wahler <dwahler@gmail.com>
// Google Code Jam submission: "Lawnmower"

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++) {
        int N, M;
        cin >> N >> M;

        vector<vector<int> > lawn(N, vector<int>(M));
        vector<int> row_max(N, 0), col_max(M, 0);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> lawn[i][j];
                row_max[i] = max(row_max[i], lawn[i][j]);
                col_max[j] = max(col_max[j], lawn[i][j]);
            }
        }

        bool feasible = true;
        for (int i = 0; i < N && feasible; i++) {
            for (int j = 0; j < M && feasible; j++) {
                if (lawn[i][j] != min(row_max[i], col_max[j])) {
                    feasible = false;
                }
            }
        }

        cout << "Case #" << testCase << ": ";
        cout << (feasible ? "YES" : "NO");
        cout << endl;
    }
}
