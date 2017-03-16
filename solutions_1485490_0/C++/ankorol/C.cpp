#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstring>
#include <cstdio>

using namespace std;

struct line
{
    long long c;
    long long T;
};

line b[101];
int bkol = 0;
line t[101];
int tkol = 0;
int bcur;
int tcur;

long long solve(int curB, int curT)
{
    if ((curB == bkol) || (curT == tkol)) return 0;
    if (b[curB].T == t[curT].T)
    {
        if (b[curB].c == t[curT].c) return b[curB].c + solve(curB + 1, curT + 1);
        if (b[curB].c > t[curT].c)
        {
            b[curB].c -= t[curT].c;
            long long ans = t[curT].c + solve(curB, curT + 1);
            b[curB].c += t[curT].c;
            return ans;
        }
        else
        {
            t[curT].c -= b[curB].c;
            long long ans = b[curB].c + solve(curB + 1, curT);
            t[curT].c += b[curB].c;
            return ans;
        }
    }
    long long ans = 0;
    // save toy
    long long temp = solve(curB + 1, curT);
    if (temp > ans) ans = temp;
    temp = solve(curB, curT + 1);
    if (temp > ans) ans = temp;
    return ans;
}

int main()
{
    int T;
    cin >> T;
    for (int te = 1; te <= T; ++te)
    {
        int N, M;
        cin >> N >> M;
        bkol = N;
        tkol = M;
        for (int i = 0; i < N; ++i)
        {
            cin >> b[i].c >> b[i].T;
        }
        for (int i = 0; i < M; ++i)
        {
            cin >> t[i].c >> t[i].T;
        }
        cout << "Case #" << te << ": " << solve(0, 0) << endl;
    }
    return 0;
}