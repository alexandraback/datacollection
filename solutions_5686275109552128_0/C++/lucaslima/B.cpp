#include <bits/stdc++.h>
using namespace std;

const int oo = 1000000000;

int go(multiset<int>& ms, int step) {
    if (step == 0) {
        return *(ms.rbegin());
    }
    else {
        int max_element = *(ms.rbegin());
        int rsp = oo;
        if (max_element <= 3) return max_element;
        ms.erase(ms.find(max_element));
        for (int i = 1; i < max_element; ++i) {
            ms.insert(i);
            ms.insert(max_element - i);
            rsp = min(rsp, 1 + go(ms, step - 1));
            ms.erase(ms.find(i));
            ms.erase(ms.find(max_element - i));
        }
        ms.insert(max_element);
        return rsp;
    }
}

int main() {
    int T;
    cin >> T;
    for (int caso = 1; caso <= T; ++caso) {
        int d;
        cin >> d;
        vector<int> p(d);
        for (int& x : p) cin >> x;
        int sum = accumulate(p.begin(), p.end(), 0);
        int rsp = oo;
        for (int i = 0; i <= min(30,min(rsp,sum)); ++i) {
            multiset<int> ms(p.begin(), p.end());
            rsp = min(rsp, go(ms, i));
        }
        cout << "Case #" << caso << ": " << rsp << endl;
        cerr << "finished test case " << caso << endl;
    }
    return 0;
}
