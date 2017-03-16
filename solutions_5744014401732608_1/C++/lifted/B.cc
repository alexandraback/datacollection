#include <iostream>
#include <vector>

using namespace std;

unsigned long long typedef u64;
vector<vector<int> > typedef Matrix;

bool Feasible(int b, u64 m) {
    return m <= (1u << (b - 2));
}

Matrix MakeMatrix(int b, u64 m) {
    Matrix G(b, vector<int>(b));

    G[0][b - 1] = 1;
    m--;

    for (int v = b - 2; v > 0; v--) {
        for (int w = v + 1; w < b; w++) {
            G[v][w] = 1;
        }
    }

    for (int v = b - 2, s = 0; v > 0; v--, s++) {
        if (m & (1 << s)) {
            G[0][v] = 1;
        }
    }

    return G;
}

void DisplayMatrix(const Matrix& m) {
    for (auto& row : m) {
        for (auto c : row) {
            cout << c;
        }
        cout << "\n";
    }
}

int main() {
    int num_tests;
    cin >> num_tests;
    for (int test = 1; test <= num_tests; test++) {
        int b;
        u64 m;
        cin >> b >> m;
        cout << "Case #" << test << ": ";
        if (Feasible(b, m)) {
            cout << "POSSIBLE\n";
            DisplayMatrix(MakeMatrix(b, m));
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
