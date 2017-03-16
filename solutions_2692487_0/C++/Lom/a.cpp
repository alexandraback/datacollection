#include <algorithm>

#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include <iostream>

using namespace std;

int readInt() {
    string str;
    getline(cin, str);
    int i = stoi(str);
    return i;
}

typedef vector<vector<signed char>> TV;
typedef uint64_t ui64;

vector<int> v;

void f(ui64 curA, int curN, int curAns, int& best, TV& s) {
    // cout << curA << " " << curN << " " << curAns << " " << best << endl;

    if (curAns > best)
        return;

    if (curA > v.back()) {
        if (curAns < best)
            best = curAns;
        return;
    }

    if (curN >= s.size()) {
        if (curAns < best)
            best = curAns;
        return;
    }

    if (curA > v[curN]) {
        f(curA + v[curN], curN + 1, curAns, best, s);
        s[curN][curA] = best;
        return;
    }

    if (curA > 1)
        f(curA + curA - 1, curN, curAns + 1, best, s);
    f(curA, curN + 1, curAns + 1, best, s);
    s[curN][curA] = best;
}

int main(int argc, char* argv[]) {
    int numTests = readInt();
    for (int test = 1; test <= numTests; ++test) {
        uint64_t A, N;
        cin >> A >> N;
        v.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> v[i];
        sort(v.begin(), v.end());

        TV s(N, TV::value_type(v.back(), -1));
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < s[i].size(); ++j) {
                if (j > v[i]) {
                    s[i][j] = 0;
                }
            }
        }

        int best = 1000000000;
        f(A, 0, 0, best, s);

        cout << "Case #" << test << ": " << best << endl;
    }

    return 0;
}
