#include <bits/stdc++.h>

using namespace std;

int K;
vector<tuple<int, int, int>> comb;
map<pair<int, int>, int> seen[3];
vector<int> take, best_take;

void rec(int i)
{
    if (i == comb.size()) {
        if (take.size() > best_take.size()) {
            best_take = take;
        }
        return;
    }

    // don't take i
    rec(i + 1);

    // take i
    int j, p, s;
    tie(j, p, s) = comb[i];
    int v1 = ++seen[0][make_pair(j, p)];
    int v2 = ++seen[1][make_pair(j, s)];
    int v3 = ++seen[2][make_pair(p, s)];
    take.push_back(i);
    if (v1 <= K  and v2 <= K and v3 <= K) {
        rec(i + 1);
    }
    take.pop_back();
    seen[0][make_pair(j, p)]--;
    seen[1][make_pair(j, s)]--;
    seen[2][make_pair(p, s)]--;
}

void solve(int testnum)
{
    cout << "Case #" << testnum + 1 << ": ";
    int J, P, S;
    cin >> J >> P >> S >> K;
    comb.clear();
    for (int j = 0; j < J; j++) {
        for (int p = 0; p < P; p++) {
            for (int s = 0; s < S; s++) {
                comb.push_back(make_tuple(j, p, s));
            }
        }
    }

    seen[0].clear();
    seen[1].clear();
    seen[2].clear();
    take.clear();
    best_take.clear();
    rec(0);


    cout << best_take.size() << '\n';
    for (int i = 0; i < best_take.size(); i++) {
        int j, s, p;
        tie(j, s, p) = comb[best_take[i]];
        cout << j + 1 << ' ' << s + 1<< ' ' << p + 1<< '\n';
    }
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve(i);
    }
}
