#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

bool vis[1007];
VI e[1007];

bool go(int x)
{
    vis[x] = true;
    TR(it, e[x])
        if (!vis[*it])
        {
            if (go(*it)) return true;
        } else return true;
    return false;
}

int main()
{
    int T, nowCase = 0;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        REP(i, n) e[i].clear();
        bool ok = true;
        REP(i, n)
        {
            int m;
            scanf("%d", &m);
            REP(j, m)
            {
                int v;
                scanf("%d", &v);
                --v;
                e[i].PB(v);
            }
        }
        REP(i, n)
        {
            CLEAR(vis);
            if (go(i))
            {
                ok = false;
                break;
            }
        }
        printf("Case #%d: ", ++nowCase);
        if (!ok)
            printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}
