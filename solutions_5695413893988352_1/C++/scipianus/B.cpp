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
int T, n;
long long sol[2];
string A, B, ssol[2];

inline void Back(int pas, long long a, long long b, bool egal)
{
    if(pas == n)
    {
        if(sol[0] == -1LL)
        {
            sol[0] = a;
            sol[1] = b;
            return;
        }
        if(abs(a - b) < abs(sol[0] - sol[1]))
        {
            sol[0] = a;
            sol[1] = b;
            return;
        }
        if(abs(a - b) == abs(sol[0] - sol[1]))
        {
            if(a < sol[0] || (a == sol[0] && b < sol[1]))
            {
                sol[0] = a;
                sol[1] = b;
                return;
            }
        }
    }
    else
    {
        if(A[pas] == '?')
        {
            if(B[pas] == '?')
            {
                if(egal)
                    Back(pas + 1, a * 10LL, b * 10LL, true);
                else
                {
                    Back(pas + 1, a * 10LL, b * 10LL, false);
                    Back(pas + 1, a * 10LL, b * 10LL + 9LL, false);
                    Back(pas + 1, a * 10LL + 9LL, b * 10LL, false);
                }
            }
            else
            {
                if(egal)
                    Back(pas + 1, a * 10LL + B[pas] - '0', b * 10LL + B[pas] - '0', true);
                else
                {
                    Back(pas + 1, a * 10LL + B[pas] - '0', b * 10LL + B[pas] - '0', false);
                    Back(pas + 1, a * 10LL, b * 10LL + B[pas] - '0', false);
                    Back(pas + 1, a * 10LL + 9LL, b * 10LL + B[pas] - '0', false);
                }
            }
        }
        else
        {
            if(B[pas] == '?')
            {
                if(egal)
                    Back(pas + 1, a * 10LL + A[pas] - '0', b * 10LL + A[pas] - '0', true);
                else
                {
                    Back(pas + 1, a * 10LL + A[pas] - '0', b * 10LL + A[pas] - '0', true);
                    Back(pas + 1, a * 10LL + A[pas] - '0', b * 10LL, true);
                    Back(pas + 1, a * 10LL + A[pas] - '0', b * 10LL + 9LL, true);
                }
            }
            else
            {
                egal = (egal && (A[pas] == B[pas]));
                Back(pas + 1, a * 10LL + A[pas] - '0', b * 10LL + B[pas] - '0', egal);
            }
        }
    }
}

int main()
{
    int i, j;
    ifstream fin("B.in");
    ofstream fout("B.out");
    fin >> T;
    for(int t = 1; t <= T; ++t)
    {
        cout << t << "\n";
        fin >> A >> B;
        n = A.size();
        sol[0] = sol[1] = -1;
        Back(0, 0, 0, true);
        ssol[0].clear();
        while(sol[0] > 0)
        {
            ssol[0] = (char)(sol[0] % 10LL + '0') + ssol[0];
            sol[0] /= 10LL;
        }
        while(ssol[0].size() < n)
            ssol[0] = '0' + ssol[0];
        ssol[1].clear();
        while(sol[1] > 0)
        {
            ssol[1] = (char)(sol[1] % 10LL + '0') + ssol[1];
            sol[1] /= 10LL;
        }
        while(ssol[1].size() < n)
            ssol[1] = '0' + ssol[1];
        fout << "Case #" << t << ": " << ssol[0] << " " << ssol[1] << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}


