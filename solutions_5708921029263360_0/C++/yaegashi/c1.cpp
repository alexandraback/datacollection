#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

struct outfit { int j, p, s; };

int main(int argc, char **argv)
{
        int T;
        cin >> T;
        for (int testcase = 0; testcase < T; testcase++) {
                int J, P, S, K;
                cin >> J >> P >> S >> K;
                vector<vector<int>> JP(S, vector<int>(S));
                vector<vector<int>> PS(S, vector<int>(S));
                vector<vector<int>> SJ(S, vector<int>(S));
                vector<outfit> R;
                int count = 0;
                for (int j = 0; j < J; j++) {
                        for (int p = 0; p < P; p++) {
                                for (int s = 0; s < S; s++) {
                                        if (JP[j][p] < K && PS[p][s] < K && SJ[s][j] < K) {
                                                JP[j][p]++;
                                                PS[p][s]++;
                                                SJ[s][j]++;
                                                R.push_back({j, p, s});
                                                count++;
                                        }
                                }
                        }
                }
                cout << "Case #" << testcase+1 << ": ";
                cout << count << endl;
                for (auto r: R)
                        cout << r.j+1 << " " << r.p+1 << " " << r.s+1 << endl;
        }
        return 0;
}
