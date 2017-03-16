#include <iostream>
#include <vector>
using namespace std;

unsigned long long toNum(vector<int>& n, unsigned long long b)
{
    unsigned long long res = n[0];
    for (int i = 1; i < n.size(); i++)
        res = res * b + (unsigned long long)(n[i]);
    return res;
}

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int K, C, S;
        cin >> K >> C >> S;
        vector<vector<int> > ns;
        vector<int> n;
        for (int i = 0; i < K; i++) {
            n.push_back(i);
            if (n.size() == C) {
                ns.push_back(n);
                n.clear();
            }
        }
        if (!n.empty()) {
            while (n.size() < C)
                n.push_back(0);
            ns.push_back(n);
        }
        cout << "Case #" << c << ": ";
        if (ns.size() > S)
            cout << "IMPOSSIBLE" << endl;
        else {
            for (int i = 0; i < ns.size(); i++)
                cout << (i == 0 ? "" : " ") << toNum(ns[i], K) + 1;
            cout << endl;
        }
    }
    return 0;
}
