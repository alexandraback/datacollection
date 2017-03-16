#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int T, n, lit[10][30], nr[30];
string s, litera[10], sol;
queue <string> Q;

inline void Solve()
{
    int i, j, last, cif, nownr[30], ns;
    bool ok;
    string now;
    now.clear();
    Q.push(now);
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        memset(nownr, 0, sizeof(nownr));
        ns = now.size();
        for(i = 0; i < ns; ++i)
        {
            cif = now[i] - '0';
            for(j = 0; j < litera[cif].size(); ++j)
                nownr[litera[cif][j] - 'A']++;
        }
        ok = true;
        for(i = 0; i < 30; ++i)
            if(nownr[i] != nr[i])
                ok = false;
        if(ok)
        {
            sol = now;
            return;
        }
        if(ns == 0)
            last = 0;
        else
            last = now[ns - 1] - '0';
        for(cif = last; cif < 10; ++cif)
        {
            ok = true;
            for(j = 0; j < litera[cif].size(); ++j)
            {
                nownr[litera[cif][j] - 'A']++;
                if(nownr[litera[cif][j] - 'A'] > nr[litera[cif][j] - 'A'])
                    ok = false;
            }
            if(ok)
                Q.push(now + (char)(cif + '0'));
            for(j = 0; j < litera[cif].size(); ++j)
                nownr[litera[cif][j] - 'A']--;
        }
    }
}

int main()
{
    int i, j;
    litera[0] = "ZERO";
    litera[1] = "ONE";
    litera[2] = "TWO";
    litera[3] = "THREE";
    litera[4] = "FOUR";
    litera[5] = "FIVE";
    litera[6] = "SIX";
    litera[7] = "SEVEN";
    litera[8] = "EIGHT";
    litera[9] = "NINE";
    for(i = 0; i < 10; ++i)
    {
        for(j = 0; j < litera[i].size(); ++i)
            lit[i][litera[i][j] - 'A']++;
    }
    ifstream fin("A.in");
    ofstream fout("A.out");
    fin >> T;
    for(int t = 1; t <= T; ++t)
    {
        fin >> s;
        n = s.size();
        memset(nr, 0, sizeof(nr));
        for(i = 0; i < n; ++i)
            nr[s[i] - 'A']++;
        Solve();
        fout << "Case #" << t << ": " << sol << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

