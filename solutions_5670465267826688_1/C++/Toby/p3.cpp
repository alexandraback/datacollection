#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

long long L;
long long X;
string S;

// {1, i, j, k}
int MULT[4][4] = {
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0},
};
int SIGN[4][4] = {
    {1, 1, 1, 1},
    {1,-1, 1,-1},
    {1,-1,-1, 1},
    {1, 1,-1,-1},
};

void multiply(int *p, int *s, int p_other, int s_other) {
    int p_ans = MULT[*p][p_other];
    int s_ans = SIGN[*p][p_other];
    *p = p_ans;
    *s *= s_ans * s_other;
}

bool solve() {
    int p_s = 0;
    int s_s = 1;
    for (int i = 0; i < L; i++) {
        int v = S[i] - 'i' + 1;
        multiply(&p_s, &s_s, v, 1);
    }
//    cout << "p_s " << p_s << ", " << s_s << endl;

    int p_all = 0;
    int s_all = 1;
    for (int i = 0; i < X % 4; i++) {
        multiply(&p_all, &s_all, p_s, s_s);
    }

//    cout << "p_all " << p_all << ", " << s_all << endl;
    if (p_all != 0 || s_all != -1) { // ijk
        return false;
    }

    int find_i = -1;
    int p = 0;
    int s = 1;
    for (int i = 0; i < L * 4; i++) {
        int v = S[i % L] - 'i' + 1;
        multiply(&p, &s, v, 1);
        if (p == 1 && s == 1) { // i
            find_i = i + 1;
            break;
        }
    }
//    cout << "find_i " << find_i << endl;

    int find_k = -1;
    p = 0;
    s = 1;
    for (int i = 0; i < L * 4; i++) {
        int v = S[L - (i % L) - 1] - 'i' + 1;
        int p2 = v;
        int s2 = 1;
        multiply(&p2, &s2, p, s);
        p = p2;
        s = s2;
        if (p == 3 && s == 1) { // k
            find_k = i + 1;
            break;
        }
    }
//    cout << "find_k " << find_k << endl;

    if (find_i < 0 || find_k < 0 || find_i + find_k >= X * L) {
        return false;
    }

    return true;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> L >> X >> S;

        string ans = solve() ? "YES" : "NO";

        cout << "Case #" << testcase << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}
