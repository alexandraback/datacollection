#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>

using namespace std;

struct Result
{
    string c, j;
    int diff;
};

void solve(string c, string j, Result &res)
{
    size_t cq = c.find('?'), jq = j.find('?');
    if (cq == c.npos && jq == j.npos)
    {
        int a = atoi(c.c_str()), b = atoi(j.c_str());
        int diff = abs(a - b);
        if (res.diff > diff)
            res = { c,j,diff };
        else if (res.diff == diff)
        {
            if (c < res.c || (c == res.c && j < res.j))
                res = { c,j,diff };
        }
        return;
    }
    if (cq != c.npos)
    {
        for (int i = 0; i <= 9; i++)
        {
            string ctmp = c;
            ctmp[cq] = i + '0';
            solve(ctmp, j, res);
        }
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            string jtmp = j;
            jtmp[jq] = i + '0';
            solve(c, jtmp, res);
        }
    }

}
int main()
{
    int t;
    cin >> t;
    getchar();

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: ", i + 1);
        string s;
        getline(cin, s);
        string c = s.substr(0, (s.size() - 1) / 2);
        string j = s.substr((s.size() - 1) / 2 + 1);

        int n = c.size();
        Result res = { "", "", 1000000000 };
        solve(c, j, res);

        cout << res.c << " " << res.j;


        cout << endl;
    }
    return 0;
}