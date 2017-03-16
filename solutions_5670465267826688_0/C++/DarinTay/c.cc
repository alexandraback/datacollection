
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int mem[10001][3];

const int vm[4][4] = {
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
    };

const int sm[4][4] = {
    {1, 1, 1, 1},
    {1, -1, 1, -1},
    {1, -1, -1, 1},
    {1, 1, -1, -1}
    };

bool solve(int p, int v, string& s) {
    if (v == 3) {
        return p == s.size();
    }
    int& ans = mem[p][v];
    if (ans != -1) return ans;

    int sign = 1;
    int val = 0;
    while (p < s.size()) {
        int c;
        if (s[p] == '1') c = 0;
        else c = s[p]-'i' + 1;

        sign *= sm[val][c];
        val = vm[val][c];

        if (sign == 1 && val == v + 1) {
            if (solve(p + 1, v+1, s)) {
                return ans = true;
            }
        }
        
        ++p;
    }

    return ans = false;
}

int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        int L,X;
        cin>>L>>X;
        string s;
        cin>>s;
        string S;
        for (int i=0;i<X;++i) S += s;

        memset(mem,-1,sizeof(mem));
        bool good = solve(0, 0, S);
        printf("Case #%d: %s\n", t, good ? "YES" : "NO");
    }
}
