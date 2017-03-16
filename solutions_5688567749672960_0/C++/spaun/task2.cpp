#pragma comment(linker, "/STACK:500000000")
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <set>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdint.h>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <queue>
#include <functional>

#pragma warning(disable : 4996)

using namespace std;
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007ull
#define INF 999999999
#define SPLIT 1000000000

int inverse(int t)
{
    int ans = 0;
    while (t)
    {
        ans *= 10;
        ans += t % 10;
        t /= 10;
    }
    return ans;
}

int main()
{
    int MAXN = 1000005;
    vector < vector < pair<int, int> > > a(MAXN);
    int s = 12;
    vector<int> d(MAXN, INF);
    for (int i = 1; i < 13; i++)
        d[i] = i;
    for (int i = 12; i < MAXN - 1; i++)
    {
        int t = inverse(i);
        if (t < MAXN)
            a[i].push_back(make_pair(inverse(i), 1));
        if (i + 1 < MAXN)
            a[i].push_back(make_pair(i + 1, 1));
    }
    set < pair<int, int> > q;
    q.insert(make_pair(d[s], s));
    while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (size_t j = 0; j < a[v].size(); ++j) {
                int to = a[v][j].first,
                    len = a[v][j].second;
                if (d[v] + len < d[to]) {
                    q.erase(make_pair(d[to], to));
                    d[to] = d[v] + len;
                    q.insert(make_pair(d[to], to));
                }
            }
        }
    int T;
    cin >> T;
    for (int k = 0; k < T; k++)
    {
        int n;
        cin >> n;
        cout << "Case #" << k + 1 << ": " << d[n] << endl;
    }
    //system("PAUSE");
    return 0;
}