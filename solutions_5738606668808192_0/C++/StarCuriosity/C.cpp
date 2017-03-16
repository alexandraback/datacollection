#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wmissing-declarations"

#define FINAL_OUT(x) {cout << x << '\n'; exit(0);}

int const n = 16;
vector<string> ans;


inline long long test(const string& s, int base)
{
    long long curVal = 0;
    for(char c : s)
        curVal *= base, curVal += c - '0';
    for(int i = 2; i < min(curVal, 10000LL); ++i)
        if (curVal % i == 0)
            return i;
    return -1;
}

void precalc()
{
    for(int i = 0; ans.size() < 50; ++i)
    {
        string s = "1";
        int mask = i;
        for(int j = 1; j + 1 < n; ++j)
            s.push_back('0' + (mask % 2)), mask /= 2;
        s.push_back('1');

        vector<long long> tmp;
        for(int j = 2; j <= 10; ++j)
        {
            long long cur = test(s, j);
            if (cur > 0)
                tmp.push_back(cur);
        }
        if (tmp.size() == 9)
        {
            for(int x : tmp)
                s.push_back(' '), s = s + to_string(x);
            ans.push_back(s);
        }
    }
    cout << "Case #1:" << endl;
    for(auto y : ans)
        cout << y << endl;
}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("C-small.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    precalc();

}

