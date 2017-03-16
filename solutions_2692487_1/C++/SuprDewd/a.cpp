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

int* motes;
int N;
map<ii, int> mem;
int mn(int at, int a)
{
    if (at == N)
    {
        return 0;
    }
    else if (a > motes[N-1])
    {
        return 0;
    }
    else if (mem.find(ii(at, a)) != mem.end())
    {
        return mem[ii(at, a)];
    }
    else
    {
        int cur = motes[at];
        int res = INF;
        if (a > cur)
        {
            res = min(res, mn(at+1, a+cur)); // eat
            return mem[ii(at, a)] = res;
        }

        if (a > 1)
        {
            int meow = 0;
            int larger = a;
            while (larger <= cur)
                larger += larger + 1, meow++;
            res = min(res, meow+mn(at+1, larger + cur)); // enlarge
        }
        res = min(res, 1+mn(at+1, a)); // skip
        return mem[ii(at, a)] = res;
    }
}

int main()
{
    int ts;
    scanf("%d\n", &ts);
    for (int t = 0; t < ts; t++)
    {
        mem.clear();
        int res;

        int A;
        scanf("%d %d\n", &A, &N);

        motes = new int[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", motes + i);
        }

        sort(motes, motes + N);

        res = mn(0, A);
        printf("Case #%d: %d\n", t+1, res);
        delete[] motes;
    }

    return 0;
}
