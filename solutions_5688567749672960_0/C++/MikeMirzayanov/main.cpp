#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 10000001;
int d[N];
queue<int> q;

int rev(int n)
{
        stringstream ss;
        ss << n;
        string t;
        ss >> t;
        reverse(t.begin(), t.end());
        stringstream ss2;
        ss2 << t;
        ss2 >> n;
        return n;
}

int main(int argc, char* argv[])
{
    d[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        {
            int v = u + 1;
            if (v < N && d[v] == 0)
            {
                d[v] = d[u]  +1;
                q.push(v);
            }
        }
        {
            int v = rev(u);
            if (v < N && d[v] == 0)
            {
                d[v] = d[u]  +1;
                q.push(v);
            }
        }
    }

    cerr << "ok" << endl;

    //freopen("input.txt", "rt", stdin);

    int tt;
    cin >> tt;

    forn(test, tt)
    {
        int x;
        cin >>x;
        cout << "Case #" << (test + 1) << ": " << d[x] << endl;
    }

    return 0;
}
