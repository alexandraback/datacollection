#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <utility>

#include "common.h"

using namespace std;

const string imp = " IMPOSSIBLE";

string solve(int K, int C, int S)
{
    if (C * S < K)
        return imp;

    vector<lint> X(S, 0);
    for (int k = 0;k < K; k++)
        X[k % S] = K * X[k % S] + k;

    set<lint> seen(X.begin(), X.end());
    ostringstream out;
    for (auto x: seen)
        out << " " << (1 + x);
    return out.str();
}

int main(int argc, char **argv)
{
    int T;
    cin >> T;
    for (int t = 1;t <= T; t++) {
        int K, C, S;
        cin >> K >> C >> S;
        cout << "Case #" << t << ":";
        cout << solve(K, C, S) << endl;
    }

    return 0;
}
