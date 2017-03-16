#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

#include <cmath>

using namespace std;

bool f(vector<bool>& mark, const vector< vector<int> >& e, int cur) {
    mark[cur] = true;

    for (int i = 0; i < e[cur].size(); ++i) {
        if (mark[e[cur][i]])
            return true;

        if (f(mark, e, e[cur][i]))
            return true;
    }

    return false;
}

int main(int argc, char* argv[]) {
    int T = 0;
    cin >> T;

    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector< vector<int> > e(N);
        for (int i = 0; i < N; ++i) {
            int M;
            cin >> M;
            for (int j = 0; j < M; ++j) {
                int base;
                cin >> base;
                e[i].push_back(base - 1);
            }
        }

        bool answer = false;
        for (int i = 0; i < N; ++i) {
            vector<bool> mark(N, false);
            if (f(mark, e, i)) {
                answer = true;
                break;
            }
        }

        cout << "Case #" << test << ": " << (answer ? "Yes" : "No") << endl;
    }

    return 0;
}
