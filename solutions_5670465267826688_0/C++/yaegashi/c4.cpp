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

bool check(const string &S, int L, int X)
{
    int now = 0, sig = 1, pos = 0, chr = 0;
    while (pos < L*X) {
        int t = to_sym(S[pos++%L]);
        sig *= sigtab[now][t];
        now = chrtab[now][t];
        if (sig < 0)
            continue;
        if ((chr == 0 && now == 1) || (chr == 1 && now == 3))
            chr++;
    }
    return chr == 2 && now == 0 && sig < 0;
}

int main()
{
    int T;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        int L, X;
        string S;
        cin >> L >> X >> S;
        cout << "Case #" << testcase+1 << ": ";
        cout << (check(S, L, X) ? "YES" : "NO");
        cout << endl;
    }
    return 0;
}

// vim: set sw=4:
