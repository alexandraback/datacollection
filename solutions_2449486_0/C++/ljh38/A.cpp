#include <iostream>
#include <fstream>

using namespace std;

int height[100][100];
int row[100];
int col[100];

bool lowEnough(int N, int M)
{
    for (int n = 0; n != N; ++n) {
        for (int m = 0; m != M; ++m) {
            if (row[n] > height[n][m] &&
                col[m] > height[n][m]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::istream& input = cin;
    // std::ifstream input("sample");

    int T = 0;
    input >> T;
    
    for (int t = 0; t != T; ++t) {

        for (int r = 0; r != 100; ++r) { row[r] = -1; }
        for (int c = 0; c != 100; ++c) { col[c] = -1; }

        int N, M = 0;
        input >> N >> M;
        for (int n = 0; n != N; ++n) {
            for (int m = 0; m != M; ++m) {
                input >> height[n][m];

                // update row, col heights.  we cannot
                // mow any lower than this.
                row[n] = max(row[n], height[n][m]);
                col[m] = max(col[m], height[n][m]);
            }
        }

        // now check if we mowed low enough
        if (lowEnough(N, M)) {
            cout << "Case #" << t + 1 << ": YES\n";
        } else {
            cout << "Case #" << t + 1 << ": NO\n";
        }
    }

    return 0;
}
