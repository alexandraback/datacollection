#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define I 2
#define J 3
#define K 4

const int table[5][5] =
{
    {0, 0, 0, 0, 0},
    {0, 1, I, J, K},
    {0, I, -1, K, -J},
    {0, J, -K, -1, I},
    {0, K, J, -I, -1}
};
char st[10001];

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

int main()
{
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cerr << i << endl;
        vector<int> v_i, v_k;
        int L, X, ri, rk;
        bool found = false;
        cin >> L >> X;
        cin >> st;
        ri = 1; rk = 1;
        for(int s = 0; s < X; s++) {
            for(int t = 0; t < L; t++) {
                ri = sgn(ri) * table[(int)abs(ri)][st[t] - 'i' + I];
                if(ri == I) {
                    v_i.push_back(s * L + t + 1);
                }
            }
            for(int t = L - 1; t >= 0; t--) {
                rk = sgn(rk) * table[st[t] - 'i' + I][(int)abs(rk)];
                if(rk == K) {
                    v_k.push_back((X - s - 1) * L + t);
                }
            }
        }
        int count = 0;
        for(vector<int>::reverse_iterator it = v_i.rbegin(); !found && it != v_i.rend(); ++it) {
            for(vector<int>::reverse_iterator kt = v_k.rbegin(); !found && kt != v_k.rend(); ++kt) {
                int rj = 1;
                for(int s = *it; s < *kt; s++) {
                    rj = sgn(rj) * table[(int)abs(rj)][st[s % L] - 'i' + I];
                }
                if(rj == J) {
                    found = true;
                }
                count ++;
                if(count > 500000) {
                    cerr << "count hit" << endl;
                    found = true;
                }
            }
        }
        cout << "Case #" << i << ":";
        if(count <= 500000 && found) {
            cout << " YES" << endl;
        } else{
            cout << " NO" << endl;
        }
    }
    return 0;
}
