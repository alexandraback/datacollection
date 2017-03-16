#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


char keys[100];
char target[100];
int K, L, S;

int mi;
int ti;

int calInstance(char* cur)
{
    int ci = 0;
    for (int i = 0; i < S - L + 1; i++)
    {
        bool can = true;
        for (int j = i; j < i + L; j++)
        {
            if (cur[j] != target[j - i])
            {
                can = false;
                break;
            }
        }
        if (can) ci++;
    }
    return ci;
}

void doit(int pos, char* cur)
{
    if (pos == S)
    {
        cur[S] = '\0';
        //printf("%s", cur);
        int ci = calInstance(cur);
        mi = max(ci, mi);
        ti = ti + ci;
        return;
    }

    for (int i = 0; i < K; i++)
    {
        cur[pos] = keys[i];
        doit(pos + 1, cur);
    }
}

void _main(int cases)
{
    scanf("%d%d%d", &K, &L, &S);
    scanf("%s%s", keys, target);

    mi = 0;
    ti = 0;

    char cur[10];
    doit(0, cur);

    int tc = 1;
    for (int i = 0; i < S; i++) tc *= K;
    double res = mi * 1.0 - ti * 1.0 / tc;
    printf("%.6lf\n", res);
}


int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++)
    {
        printf("Case #%d: ", cases);
        _main(cases);
    }
}