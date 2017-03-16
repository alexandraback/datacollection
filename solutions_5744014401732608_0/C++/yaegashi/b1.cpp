#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

int main(int argc, char **argv)
{
        int T;
        cin >> T;
        for (int testcase = 0; testcase < T; testcase++) {
                int B, M;
                cin >> B >> M;
                vector<vector<int>> mat(B, vector<int>(B));
                for (int i = 0; i < B - 1 && M > 0; i++) {
                        mat[i][B-1] = 1;
                        mat[i][i+1] = 1;
                        M--;
                }
                for (int i = 0; i < B - 3; i++) {
                        for (int j = i + 2; j < B - 1; j++) {
                                if (M >= B - 1 - j) {
                                        M -= B - 1 - j;
                                        mat[i][j] = 1;
                                }
                        }
                }
                cout << "Case #" << testcase+1 << ": ";
                if (M > 0) {
                        cout << "IMPOSSIBLE" << endl;
                }
                else {
                        cout << "POSSIBLE" << endl;
                        for (int i = 0; i < B; i++) {
                                for (int j = 0; j < B; j++)
                                        cout << mat[i][j];
                                cout << endl;
                        }
                }
        }
        return 0;
        }
