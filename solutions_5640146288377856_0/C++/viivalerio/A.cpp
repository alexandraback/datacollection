#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<limits.h>
#include<iomanip>
#include<cmath>
#include<cassert>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<vector>
#include<sstream>
#include<bitset>

using namespace std;

#define INF 0x7fffffff

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef priority_queue<ii> pqii;
typedef priority_queue<iii> pqiii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef queue<ii> qii;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ull, ull> pull;
typedef pair<ll,ll> pll;


int main()
{
    int cases = 1;
    int T;
    int R, C , W;

    while(scanf("%d", &T)!= EOF)
    {
        while(T--)
        {

            scanf("%d %d %d", &R, &C, &W);

            printf("Case #%d: ", cases++);
            printf("%d\n", R*(C/W)+ (C%W == 0 ? W-1 : W));
        }

    }

    return 0;
}


