#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool check(int idx[], int n, vector<string> &vec)
{
    bool used[26] = {false};
    int pre = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < vec[idx[i]].size(); ++j)
        {
            int id = vec[idx[i]][j] - 'a';
            if (used[id] && pre != id)
                return false;
            pre = id;
            used[id] = true;
        }
    }
    return true;
}

void Solved(int nT)
{
    int idx[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<string> vec;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s; cin >> s;
        vec.push_back(s);
    }
    int result = 0;
    do 
    {
        if (check(idx, n, vec))
            ++result;
    } while (next_permutation(idx, idx + n));
    printf("Case #%d: %d\n", nT, result);
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    int T = 1;
    cin >> T;
    for (int nT = 1; nT <= T; ++nT)
    {
        Solved(nT);
    }

    return 0;
}