#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> answer[4][4][4][4];
int countxy[4][4], countxz[4][4], countyz[4][4];

vector<tuple<int, int, int>> solve(int J, int P, int S, int K) {
    vector<tuple<int, int, int> > all, answer, aux;
    for (int j = 1; j <= J; ++j)
        for (int p = 1; p <= P; ++p)
            for (int s = 1; s <= S; ++s)
                all.emplace_back(j, p, s);

    int N = all.size();
    for (int i = 0; i < (1 << N); ++i) {
        aux.clear();
        memset(countxy, 0, sizeof(countxy));
        memset(countxz, 0, sizeof(countxz));
        memset(countyz, 0, sizeof(countyz));

        for (int j = 0; j < N; ++j)
            if ((1 << j) & i)
                aux.emplace_back(all[j]);
        bool bad = false;
        for (auto &t : aux) {
            int x, y, z; tie(x, y, z) = t;
            if (++countxy[x][y] > K)
                bad = true;
            if (++countxz[x][z] > K)
                bad = true;
            if (++countyz[y][z] > K)
                bad = true;
        }
        if (!bad && aux.size() > answer.size())
            answer = aux;
    }
    return answer;
}

int main() {
    for (int J = 1; J <= 3; ++J)
        for (int P = J; P <= 3; ++P)
            for (int S = P; S <= 3; ++S)
                for (int K = 1; K <= 3; ++K)
                    answer[J][P][S][K] = solve(J, P, S, K);

    cerr << "Done precalculating\n";
    int tests; cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int J, P, S, K; cin >> J >> P >> S >> K;
        cout << "Case #" << test << ": " << answer[J][P][S][min(K, 3)].size() << "\n";
        for (auto &t : answer[J][P][S][min(K, 3)]) {
            int x, y, z; tie(x, y, z) = t;
            cout << x << " " << y << " " << z << "\n";
        }
    }
}
