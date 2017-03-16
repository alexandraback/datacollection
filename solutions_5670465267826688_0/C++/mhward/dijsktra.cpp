#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum chars { one = 1, i, j, k };
const int num_chars = 4;

int multmap[][num_chars] = {
    { one, i, j, k },
    { i, -one, k, -j },
    { j, -k, -one, i },
    { k, j, -i, -one }
};

int to_q(char c) {
    if (c == 'i')
        return i;
    if (c == 'j')
        return j;
    if (c == 'k')
        return k;
    return num_chars;
}

int qmult(int l, int r) {
    bool neg = false;
    if (l < 0 && r < 0) {
        l *= -1;
        r *= -1;
    } else if (l < 0) {
        l *= -1;
        neg = true;
    } else if (r < 0) {
        r *= -1;
        neg = true;
    }
    return neg ? -(multmap[l-1][r-1]) : multmap[l-1][r-1];
}

int main() {
    /*for (int i = 0; i < num_chars; ++i) {
        for (int j = 0; j < num_chars; ++j) {
            cout << multmap[i][j] << " ";
        }
        cout << endl;
    }
    cout << qmult(2, 2) << endl;*/
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int l, x;
        string s;
        cin >> l >> x >> s;
        cout << "Case #" << tc << ": ";
        if (l*x < 3) {
            cout << "NO" << endl;
            continue;
        }
        vector<vector<int> > multr(l*x, vector<int>(l*x));
        for (int i = 0; i < l*x; ++i) {
            int prod = to_q(s[i%l]);
            multr[i][i] = prod;
            for (int j = i+1; j < l*x; ++j) {
                prod = qmult(prod, to_q(s[j%l]));
                multr[i][j] = prod;
            }
        }
        /*for (int i = 0; i < l*x; ++i)
            for (int j = i; j < l*x; ++j)
                cout << i << " " << j << " " << multr[i][j] << endl;*/
        bool done = false;
        for (int a = 1; a < l*x; ++a) {
            if (done)
                break;
            for (int b = a+1; b < l*x; ++b) {
                if (multr[0][a-1] == i && multr[a][b-1] == j && multr[b][l*x-1] == k) {
                    done = true;
                    break;
                }
            }
        }
        if (!done)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

    }
    return 0;
}
