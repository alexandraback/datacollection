#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void readTest(deque<double>& a, deque<double>& b) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double x; cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        double x; cin >> x;
        b.push_back(x);
    }
}

template <class T>
int simpleWar(const T& a, const T& b) {
    int wins = 0;

    int bstart = 0, bend = a.size() - 1;
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] > b[bend]) {
            ++wins;
            ++bstart;
        }
        else {
            --bend;
        }
    }

    return wins;
}

template <class T>
int deceitfulWar(T a, T b) {
    //int sol1 = simpleWar(a, b); // just in case

    int wins = 0;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] > b.front())
            b.pop_front(),
            ++wins;

    return wins;
}

template <class T>
void print(const T& a) {
    for (auto x: a)
        cout << x << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        deque<double> a, b;
        readTest(a, b);
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        //cout << "a = "; print(a);
        //cout << "b = "; print(b);
        cout << "Case #" << t << ": " << deceitfulWar(a, b) << " " << simpleWar(a, b) << endl;
    }

    return 0;
}
