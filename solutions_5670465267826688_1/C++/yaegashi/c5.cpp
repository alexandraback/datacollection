#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

const int chrtab[][4] = {
    { 0, 1, 2, 3 },
    { 1, 0, 3, 2 },
    { 2, 3, 0, 1 },
    { 3, 2, 1, 0 },
};

const int sigtab[][4] = {
    {  1,  1,  1,  1 },
    {  1, -1,  1, -1 },
    {  1, -1, -1,  1 },
    {  1,  1, -1, -1 },
};

inline int to_sym(int c)
{
    switch (c) {
    case 'i': return 1;
    case 'j': return 2;
    case 'k': return 3;
    default: return 0;
    }
}

bool check(const string &S, int L, int64_t X)
{
    int final_chr[4], final_sig[4];
    int chr = 0, sig = 1, next = 0, max = X < 8 ? X : 8;
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < L; j++) {
            int t = to_sym(S[j]);
            sig *= sigtab[chr][t];
            chr = chrtab[chr][t];
            if (sig < 0)
                continue;
            if ((next == 0 && chr == 1) || (next == 1 && chr == 3))
                next++;
        }
        if (i < 4) {
            final_chr[i] = chr;
            final_sig[i] = sig;
        }
    }
    int i = (X - 1) % 4;
    return next == 2 && final_chr[i] == 0 && final_sig[i] < 0;
}

int main()
{
    int T;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        int L;
        int64_t X;
        string S;
        cin >> L >> X >> S;
        cout << "Case #" << testcase+1 << ": ";
        cout << (check(S, L, X) ? "YES" : "NO");
        cout << endl;
    }
    return 0;
}

// vim: set sw=4:
