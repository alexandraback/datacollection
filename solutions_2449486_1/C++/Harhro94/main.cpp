/*
 * File:     main.cpp
 * Author:   Hrayr [HarHro94]
 * Problem:  
 * IDE:      Visual C++ 2008
 */
//#pragma comment(linker, "/STACK:66777216")
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <Vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define LL long long
#define LD long double

const int N = 107;
int n, m, a[N][N];

bool can()
{
    int rowMax[N], colMax[N];
    int i, j;
    memset(rowMax, -1, sizeof rowMax);
    memset(colMax, -1, sizeof colMax);
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            rowMax[i]=max(rowMax[i], a[i][j]);
            colMax[j]=max(colMax[j], a[i][j]);
        }
    }
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            if (rowMax[i]!=a[i][j] && colMax[j]!=a[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
#ifdef harhro94
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, test, testCnt;
    scanf("%d", &testCnt);
    for(test=1;test<=testCnt;++test)
    {
        scanf("%d%d", &n, &m);
        for(i=0;i<n;++i)
        {
            for(j=0;j<m;++j)
            {
                scanf("%d", &a[i][j]);
            }
        }
        printf("Case #%d: ", test);
        puts(can()? "YES":"NO");
    }

#ifdef harhro94
	cerr << fixed << setprecision(3) << "\nExecution time = " << clock()/1000.0 << "s\n";
#endif
	return 0;
}
