#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdlib>
#include <unordered_map>
#define pss pair<string, string>
#define pii pair<int, int>
using namespace std;
int T, n, nr, sol;
pss vs[20];
pii v[20];
unordered_map <string, int> M;
bool fake[20], exista[2][50];

inline bool Verif()
{
    int i;
    pii now;
    for(i = 1; i <= nr; ++i)
        exista[0][i] = exista[1][i] = false;
    for(i = 1; i <= n; ++i)
    {
        if(fake[i] == false)
        {
            exista[0][v[i].first] = true;
            exista[1][v[i].second] = true;
        }
    }
    for(i = 1; i <= n; ++i)
    {
        if(fake[i] == true)
        {
            if(!exista[0][v[i].first] || !exista[1][v[i].second])
                return false;
        }
    }
    return true;
}

inline void Back(int pas, int now)
{
    if(now + n - pas + 1 <= sol)
        return;
    if(pas == n + 1)
    {
        if(Verif())
            sol = max(sol, now);
    }
    else
    {
        fake[pas] = true;
        Back(pas + 1, now + 1);
        fake[pas] = false;
        Back(pas + 1, now);
    }
}

int main()
{
    int i, j;
    ifstream fin("C.in");
    ofstream fout("C.out");
    fin >> T;
    for(int t = 1; t <= T; ++t)
    {
        fin >> n;
        nr = 0;
        for(i = 1; i <= n; ++i)
        {
            fin >> vs[i].first >> vs[i].second;
            if(!M.count(vs[i].first))
            {
                nr++;
                M[vs[i].first] = nr;
            }
            if(!M.count(vs[i].second))
            {
                nr++;
                M[vs[i].second] = nr;
            }
            v[i] = make_pair(M[vs[i].first], M[vs[i].second]);
        }
        sol = 0;
        Back(1, 0);
        M.clear();
        fout << "Case #" << t << ": " << sol << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}



