#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
typedef vector<long> vl;
typedef vl::const_iterator vlci;

struct ans {
    vl p;
    vl n;
};

bool findit(long long total, vlci begin, vlci end, ans& a) {
    if (begin == end) {
        return false;
    } else if (*begin == total) {
        a.n.push_back(*begin);
        return true;
    } else {
        // pos
        if (findit(total + *begin, begin+1, end, a)) {
            a.p.push_back(*begin);
            return true;
        } else if (findit(total - *begin, begin+1, end, a)) {
            a.n.push_back(*begin);
            return true;
        } else {
            return findit(total, begin+1, end, a);
        }
    }
}

void doCase(int caseNum) {
    int N;
    cin >> N;

    vector<long> s;
    for (int i = 0; i < N; i++) {
        long si;
        cin >> si;
        s.push_back(si);
    }
    sort(s.begin(), s.end());

    ans a;
    if (findit(0LL, s.begin(), s.end(), a)) {
        cout << "Case #" << caseNum << ":" << endl;
        for (vlci it = a.p.begin(); it != a.p.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
        for (vlci it = a.n.begin(); it != a.n.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    } else {
        cout << "Case #" << caseNum << ": Impossible" << endl;
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        doCase(i+1);
    }
}
