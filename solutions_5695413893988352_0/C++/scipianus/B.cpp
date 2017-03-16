#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;
int T, n, sol[2];
string A, B, ssol[2];

inline void Back2(int pas, int currA, int now)
{
    if(pas == n)
    {
        if(sol[0] == -1)
        {
            sol[0] = currA;
            sol[1] = now;
            return;
        }
        if(abs(currA - now) < abs(sol[0] - sol[1]))
        {
            sol[0] = currA;
            sol[1] = now;
            return;
        }
        if(abs(currA - now) == abs(sol[0] - sol[1]))
        {
            if(currA < sol[0] || (currA == sol[0] && now < sol[1]))
            {
                sol[0] = currA;
                sol[1] = now;
                return;
            }
        }
    }
    else
    {
        if(B[pas] != '?')
            Back2(pas + 1, currA, now * 10 + B[pas] - '0');
        else
        {
            for(int i = 0; i < 10; ++i)
                Back2(pas + 1, currA, now * 10 + i);
        }
    }
}

inline void Back1(int pas, int now)
{
    if(pas == n)
        Back2(0, now, 0);
    else
    {
        if(A[pas] != '?')
            Back1(pas + 1, now * 10 + A[pas] - '0');
        else
        {
            for(int i = 0; i < 10; ++i)
                Back1(pas + 1, now * 10 + i);
        }
    }
}

int main()
{
    int i, j;
    ifstream fin("B.in");
    ofstream fout("B.out");
    freopen("B.out", "w", stdout);
    fin >> T;
    for(int t = 1; t <= T; ++t)
    {
        fin >> A >> B;
        n = A.size();
        sol[0] = sol[1] = -1;
        Back1(0, 0);
        ssol[0].clear();
        while(sol[0] > 0)
        {
            ssol[0] = (char)(sol[0] % 10 + '0') + ssol[0];
            sol[0] /= 10;
        }
        while(ssol[0].size() < n)
            ssol[0] = '0' + ssol[0];
        ssol[1].clear();
        while(sol[1] > 0)
        {
            ssol[1] = (char)(sol[1] % 10 + '0') + ssol[1];
            sol[1] /= 10;
        }
        while(ssol[1].size() < n)
            ssol[1] = '0' + ssol[1];
        fout << "Case #" << t << ": " << ssol[0] << " " << ssol[1] << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}


