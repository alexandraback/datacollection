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

const int SIZE = 100;
const int MAXN = 1005;

char s[SIZE];

int t1[MAXN];
int t2[MAXN];

inline int readInt()
{
    scanf("%s", s);
    int n = strlen(s);

    int res = 0;
    FOR (i, 2, n) res = res*10 + (s[i]-'0');

    return res;
}

int secondGame(int n)
{
    int j = 0;
    FOR (i, 0, n) if (t1[i] > t2[j]) ++j;

    return j;
}

int firstGame(int n)
{
    int j = 0;
    FOR (i, 0, n)
    {
        for (; j < n; ++j)
        {
            if (t1[i] < t2[j])
            {
                ++j;
                break;
            }
        }
        if (j == n) return n-i - (t1[i] < t2[n-1] ? 1 : 0);
    }

    return 0;
}

void rob(int cs)
{
    int n;
    scanf("%d", &n);

    FOR (i, 0, n) t1[i] = readInt();
    FOR (i, 0, n) t2[i] = readInt();

    sort(t1, t1+n);
    sort(t2, t2+n);

    int res1 = secondGame(n);
    int res2 = firstGame(n);

    printf("Case #%d: %d %d\n", cs, res1, res2);
}

int main()
{
    int test = 1;
    scanf("%d", &test);

    FORE (i, 1, test) rob(i);

    return 0;
}
