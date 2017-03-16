//
//  pancakes.cpp
//  
//
//  Created by John Nevard on 4/11/15.
//
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

const int N = 1000;

vector<VI> table;

void make_table(vector<VI>& table) {
    table.resize(N + 1);
    for (int n = 1; n <= N; ++n)
        table[n].resize(N + 1);
    for (int n = 1; n <= N; ++n) {
        for (int k = n; k <= N; ++k)
            table[n][k] = 0;
        int lo = (n + 1) / 2;
        for (int k = lo; k < n; ++k)
            table[n][k] = 1;
        for (int k = 1; k < lo; ++k) {
            int best = n;
            for (int j = 1; j <= n - j; ++j) {
                int t = table[j][k] + table[n - j][k];
                if (t < best)
                    best = t;
            }
            table[n][k] = 1 + best;
        }
    }
}

int breakfast(VI& p) {
    int np = p.size();
    int big = 0;
    for (int i = 0; i < np; ++i)
        if (p[i] > big)
            big = p[i];
    int answer = big;
    for (int plate = 1; plate < big; ++plate) {
        int n_special = 0;
        for (int i = 0; i < np; ++i) {
            n_special += table[p[i]][plate];
            if (n_special + plate >= answer)
                break;
        }
        if (n_special + plate < answer)
            answer = n_special + plate;
    }
    return answer;
}

int main() {
    make_table(table);
    int n_cases;
    cin >> n_cases;
    for (int c = 1; c <= n_cases; ++c) {
        int d;
        cin >> d;
        VI p(d);
        for (int i = 0; i < d; ++i)
            cin >> p[i];
        VI q = p;
        int answer = breakfast(p);
        cout << "Case #" << c << ": " << answer << '\n';
    }
    return 0;
}