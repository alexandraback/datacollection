//Krzysztof Pieprzak
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define Size(x) (int)x.size()
#define VAR(v,n) typeof(n)v = (n)
#define FOR(i,a,b) for(VAR(i,a); i < (b); ++i)
#define FORE(i,a,b) for(VAR(i,a); i <= (b); ++i)
#define FORREV(i,a,b) for(VAR(i,b); i >= (a); --i)
#define FORSTEP(i,a,b,step) for(VAR(i,a); i < (b); i += (step))
#define FOREACH(i,c) for(VAR(i,(c).begin()); i != (c).end(); ++i)
#define ALL(x) x.begin(),x.end()
#define CLEAR(t) memset(t, 0, sizeof(t))
#define F first
#define S second
#define MP make_pair
#define PUB push_back
#define POB pop_back
#define pieprzu ios_base::sync_with_stdio(0);

const int    INF = 1000000001;
const double EPS = 10e-9;

void rob(int cs)
{
    int r, c, m;
    scanf("%d %d %d", &r, &c, &m);

    printf("Case #%d:\n", cs);

    int n = r*c;
    int e = n-m;

    if (r == 1)
    {
        printf("c");
        FOR (i, 0, c-m-1) printf(".");
        FOR (i, 0, m) printf("*");
        printf("\n");
    }
    else if (c == 1)
    {
        printf("c\n");
        FOR (i, 0, r-m-1) printf(".\n");
        FOR (i, 0, m) printf("*\n");
    }
    else if (r == 2)
    {
        if (e == 1)
        {
            printf("c");
            FOR (i, 1, c) printf("*");
            printf("\n");
            FOR (i, 0, c) printf("*");
            printf("\n");
        }
        else if ((m&1) || e == 2) printf("Impossible\n");
        else
        {
            printf("c");
            FOR (i, 0, c-m/2-1) printf(".");
            FOR (i, 0, m/2) printf("*");
            printf("\n");
            FOR (i, 0, c-m/2) printf(".");
            FOR (i, 0, m/2) printf("*");
            printf("\n");
        }
    }
    else if (c == 2)
    {
        if (e == 1)
        {
            printf("c*\n");
            FOR (i, 1, r) printf("**\n");
        }
        else if ((m&1) || e == 2) printf("Impossible\n");
        else
        {
            printf("c.\n");
            FOR (i, 1, r-m/2) printf("..\n");
            FOR (i, 0, m/2) printf("**\n");
        }
    }
    else
    {
        if (e == 2 || e == 3 || e == 5 || e == 7) printf("Impossible\n");
        else
        {
            printf("c");
            if (e == 1)
            {
                int beg = 1;
                FOR (i, 0, r)
                {
                    FOR (j, beg, c) printf("*");
                    beg = 0;
                    printf("\n");
                }
            }
            else if (e <= c*2+1)
            {
                int base, rest;
                if (e&1)
                {
                    base = (e-3)/2;
                    rest = 3;
                }
                else
                {
                    base = e/2;
                    rest = 0;
                }
                FOR (i, 0, base-1) printf(".");
                FOR (i, base, c) printf("*");
                printf("\n");
                FOR (i, 0, base) printf(".");
                FOR (i, base, c) printf("*");
                printf("\n");
                FOR (i, 0, rest) printf(".");
                FOR (i, rest, c) printf("*");
                printf("\n");
                FOR (i, 3, r)
                {
                    FOR (j, 0, c) printf("*");
                    printf("\n");
                }
            }
            else //e > c*2+1
            {
                int last,rest;
                if (e%c == 1)
                {
                    last = c-1;
                    rest = 2;
                }
                else
                {
                    last = c;
                    rest = e%c;
                }
                int beg = 1;
                FOR (i, 0, e/c-1)
                {
                    FOR (j, beg, c) printf(".");
                    beg = 0;
                    printf("\n");
                }
                FOR (i, 0, last) printf(".");
                FOR (i, last, c) printf("*");
                printf("\n");
                if (rest)
                {
                    FOR (i, 0, rest) printf(".");
                    FOR (i, rest, c) printf("*");
                    printf("\n");
                }
                FOR (i, e/c + ((e%c) ? 1 : 0), r)
                {
                    FOR (j, 0, c) printf("*");
                    printf("\n");
                }
            }
        }
    }
}

int main()
{
    int test = 1;
    scanf("%d", &test);

    FORE (i, 1, test) rob(i);

    return 0;
}
