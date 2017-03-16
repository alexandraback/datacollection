#include <cassert>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cstddef>
#include <cctype>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <list>
#include <string>
#include <functional>
#include <utility>
using namespace std;
typedef long long llint;
void readin(int &n, vector <string> &fw, vector <string> &sw)
{
    cin >> n;
    fw.resize(n);
    sw.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> fw[i];
        cin >> sw[i];
    }
}
bool check(int const &mask, int const &N, vector <string> const &F, vector <string> const &S)
{
    set <string> fa, sa;
    for (int i = 0; i < N; ++i)
    {
        if ((mask & (1 << i)) == 0)
        {
            fa.insert(F[i]);
            sa.insert(S[i]);
        }
    }
    for (int i = 0; i < N; ++i)
    {
        if ((mask & (1 << i)) != 0)
        {
            if (fa.find(F[i]) == fa.end())
            {
                return false;
            }
            if (sa.find(S[i]) == sa.end())
            {
                return false;
            }
        }
    }
    return true;
}
int solve(int const &N, vector <string> const &F, vector <string> const &S)
{
    int ret = -1;
    for (int mask = 0; mask < (1 << N); ++mask)
    {
        if (check(mask, N, F, S))
        {
            ret = max(ret, __builtin_popcount(mask));
        }
    }
    return ret;
}
int main()
{
    int tc;
    int n;
    vector <string> fw, sw;
    cin >> tc;
    for (int cc = 1; cc <= tc; ++cc)
    {
        readin(n, fw, sw);
        cout << "Case #" << cc << ": "
             << solve(n, fw, sw)
             << endl;
    }
}
