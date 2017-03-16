#include <bits/stdc++.h>
using namespace std;

int h(char c) {
    if (c == 'i') return 2;
    if (c == 'j') return 3;
    if (c == 'k') return 4;
    assert(0);
}

int mult(int x, int y) {
    if (x < 0) return -mult(-x,y);
    if (y < 0) return -mult(x,-y);
    if (x == 1) return y;
    if (y == 1) return x;
    if (x == y) return -1;
    if (x == 2 && y == 3) return 4;
    if (x == 2 && y == 4) return -3;
    if (x == 3 && y == 2) return -4;
    if (x == 3 && y == 4) return 2;
    if (x == 4 && y == 2) return 3;
    if (x == 4 && y == 3) return -2;
    assert(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int caso = 1; caso <= T; ++caso) {
        int L;
        int64_t X;
        cin >> L >> X;
        
        X = min(X, 8 + X % 4);
        
        cerr << X << endl;
        
        string s, line = "";
        cin >> s;
        while (X--) line += s;
        
        vector<int> v;
        for (char &c : line) v.push_back(h(c));
        
        vector<int> goodi;
        int value = 1;
        for (int i = 0; i < int(v.size()); ++i) {
            value = mult(value, v[i]);
            if (value == 2) goodi.push_back(i);
        }
        
        vector<int> goodk;
        value = 1;
        for (int i = int(v.size()) - 1; i >= 0; --i) {
            value = mult(v[i], value);
            if (value == 4) goodk.push_back(i);
        }
        reverse(goodk.begin(), goodk.end());
        
        bool good = false;
        for (int pi : goodi) {
            int posk = 0;
            int value = 1;
            for (int i = pi + 1; i < int(v.size()); ++i) {
                value = mult(value, v[i]);
                if (value == 3) {
                    while (posk < int(goodk.size()) && goodk[posk] < i + 1) ++posk;
                    if (goodk[posk] == i + 1) {
                        good = true;
                        break;
                    }
                }
            }
            if (good) break;
        }
        
        cout << "Case #" << caso << ": " << (good ? "YES" : "NO") << endl;
        cerr << "finished test case " << caso << endl;
    }
    return 0;
}
