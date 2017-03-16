#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

vector<pair<int, int> > PM[3]; // JP, PS, JS
vector<tuple<int, int, int> > ANS;
int CNT[3][105]; // JP, PS, JS

int T, J, P, S, K;

bool can(pair<int, int> JP, pair<int, int> PS, pair<int, int> JS) {
    return JP.first == JS.first && JP.second == PS.first && PS.second == JS.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int ways = 0;
        ANS.clear();
        cin >> J >> P >> S >> K;
        for (int a = 0; a < 3; ++a) {
            PM[a].clear();
            for (int b = 0; b < 105; ++b)
                CNT[a][b] = 0;
        }
        for (int a = 1; a <= J; ++a)
            for (int b = 1; b <= P; ++b)
                PM[0].emplace_back(a, b);
        for (int a = 1; a <= P; ++a)
            for (int b = 1; b <= S; ++b)
                PM[1].emplace_back(a, b);
        for (int a = 1; a <= J; ++a)
            for (int b = 1; b <= S; ++b)
                PM[2].emplace_back(a, b);
        for (int a = 0; a < (int)PM[0].size(); ++a) {
            //cerr << "A: " << a << "\n";
            for (int b = 0; b < (int)PM[1].size(); ++b) {
                //cerr << " B: " << b << "\n";
                if (CNT[0][a] == K) continue;
                if (CNT[1][b] == K) continue;
                for (int c = 0; c < (int)PM[2].size(); ++c) {
                    //cerr << "  C: " << c << "\n";
                    if (CNT[0][a] == K) continue;
                    if (CNT[1][b] == K) continue;
                    if (CNT[2][c] == K) continue;
                    if (can(PM[0][a], PM[1][b], PM[2][c])) {
                        ++CNT[0][a];
                        ++CNT[1][b];
                        ++CNT[2][c];
                        ++ways;
                        ANS.emplace_back(PM[0][a].first, PM[0][a].second, PM[1][b].second);
                    }
                }
            }
        }
        cout << "Case #" << tc << ": " << ways << "\n";
        for (int a = 0; a < (int)ANS.size(); ++a)
            cout << get<0>(ANS[a]) << " " << get<1>(ANS[a]) << " " << get<2>(ANS[a]) << "\n";
    }
    return 0;
}
