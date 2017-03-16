#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iterator>
#include <ctime>
#include <iomanip>

typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

using namespace std;

#define ALL(a) a.begin(), a.end()
#define FOR(a) for (int i = 0; i < a; ++i)
#define mp(a, b) make_pair(a, b)
#define D(a) #a << ": " << a << "\n"

vector<vector<char> > arr;
int cache[51][51][51*51];

bool search(int empty, int c, int r, int rStart, int offset = 0)
{
    if (cache[c][r][empty])
        return false;

    for (int stlpce = 2; stlpce <= c; ++stlpce)
    {
        for (int riadky = rStart; riadky <= r; ++riadky)
        {
            int ostava = empty - riadky * stlpce;

            if (!ostava)
            {
                for (int i = 0; i < stlpce; ++i)
                    for (int j = offset; j < offset + riadky; ++j)
                        arr[j][i] = '.';

                return true;
            }

            if (search(ostava, stlpce, r - riadky, 1, offset + riadky))
            {
                for (int i = 0; i < stlpce; ++i)
                    for (int j = offset; j < offset + riadky; ++j)
                        arr[j][i] = '.';

                return true;
            }
        }
    }

    cache[c][r][empty] = 1;
    return false;
}

int main()
{
    srand(time(NULL));
    cout << setprecision(15);
    int CASES;
    cin >> CASES;
    for (int CASE = 1; CASE <= CASES; ++CASE)
    {
        int r, c, m;
        cin >> r >> c >> m;
        //r = rand() % 50 + 1; c = rand() % 50 + 1; m = rand() % (r * c);

        memset(cache, 0, sizeof cache);

        printf("Case #%d:\n", CASE);
        int empty = r * c - m;

        if (r == 1 || c == 1 || empty == 1)
        {
            for (int rr = 0; rr < r; ++rr)
            {
                for (int cc = 0; cc < c; ++cc)
                {
                    if (m)
                        printf("*"), --m;
                    else if (rr == r-1 && cc == c-1)
                        printf("c");
                    else
                        printf(".");
                }

                printf("\n");
            }
        }
        else
        {
            arr.clear();
            arr.resize(r, vector<char>(c, '*'));

            if (empty < 4)
            {
                printf("Impossible\n");
                //printf("Impossible %d %d %d\n", r, c, m);
                continue;
            }

            if (!search(empty, c, r, 2))
            {
                printf("Impossible\n");
                //printf("Impossible %d %d %d\n", r, c, m);
                continue;
            }

            arr[0][0] = 'c';

            for (int rr = 0; rr < r; ++rr)
            {
                for (int cc = 0; cc < c; ++cc)
                    printf("%c", arr[rr][cc]);
                printf("\n");
            }
        }
    }

    return 0;
}