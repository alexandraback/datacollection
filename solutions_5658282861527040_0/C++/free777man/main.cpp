#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <cstring>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define FOR(i,s,n) for(int i=(s);i<(n);++i)
#define REP(i,n) FOR(i,0,(n))
#define PB(x) push_back((x))
#define CLR(a,v) memset((a),(v),sizeof((a)))
typedef long long ll;

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w+", stdout);
    
    int TTT;
    scanf("%d", &TTT);
    FOR(ttt,1,TTT+1)
    {
        int a,b,k;
        cin>>a>>b>>k;

        int res = 0;
        REP(i,a)REP(j,b)
        {
            int r = i&j;
            if(r<k)++res;
        }

        printf("Case #%d: %d\n", ttt, res);
    }

    return 0;
}


