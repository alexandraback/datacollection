#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <cassert>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T x) { return x.size(); }

// assert or gtfo
int E, R, N, *v;
map<ii, int> mem;

int mx(int r, int i)
{
    if (i == N)
    {
        return 0;
    }
    else if (mem.find(ii(r, i)) != mem.end())
    {
        return mem[ii(r, i)];
    }
    else
    {
        int res = 0;
        for (int j = 0; j <= r; j++)
        {
            res = max(res, v[i]*j + mx(min(r - j + R, E), i+1));
        }

        return mem[ii(r, i)] = res;
    }
}

int main()
{
    int ts;
    scanf("%d\n", &ts);
    for (int t = 0; t < ts; t++)
    {
        mem.clear();
        scanf("%d %d %d\n", &E, &R, &N);
        v = new int[N];

        for (int i = 0; i < N; i++)
        {
            scanf("%d", v + i);
        }

        printf("Case #%d: %d\n", t+1, mx(E, 0));
        delete[] v;
    }

    return 0;
}
