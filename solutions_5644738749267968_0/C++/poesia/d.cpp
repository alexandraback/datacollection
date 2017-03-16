#include <iostream>
#include <deque>
#include <algorithm>
#include <set>

using namespace std;


int play_ken(deque<double> n, deque<double> k) {
    set<double> sk(k.begin(), k.end());

    int score = 0;

    for (double w : n) {
        auto i = sk.upper_bound(w);

        if (i != sk.end()) {
            score++;
            sk.erase(i);
        }
    }

    return score;
}

int play_naomi(deque<double> n, deque<double> k) {

    int score = 0;

    while (n.size()) {
        if (n.back() > k.back()) {
            score++;
            n.pop_back();
            k.pop_back();
        } else {
            n.pop_front();
            k.pop_back();
        }
    }

    return score;
}

int main() {
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;

        deque<double> wn(n), wk(n);

        for (int i = 0; i < n; i++)
            cin >> wn[i];

        for (int i = 0; i < n; i++)
            cin >> wk[i];

        sort(wn.begin(), wn.end());
        sort(wk.begin(), wk.end());

        int nsW = n - play_ken(wn, wk);
        int nsDW = play_naomi(wn, wk);

        cout << "Case #" << tc << ": " << nsDW << " " << nsW << '\n';
    }

    return 0;
}
