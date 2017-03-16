//Krzysztof Pieprzak
#include <bits/stdc++.h>

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
#define FOREACHS(i,c,n) for(VAR(i,&(c)[0]); i-(c)<(n); ++i)
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

const int MAX_V = 1000;

bool t[MAX_V+5];
bool t2[MAX_V+5];

int c,d,v;

void add(int a)
{
    FORE (j, 0, v-a)
        if (t[j])
            t2[j+a] = 1;

    FORE (j, 0, v)
        if (t2[j])
        {
            t[j] = 1;
            t2[j] = 0;
        }
}

void rob(int test)
{
    scanf("%d %d %d", &c, &d, &v);

    t[0] = 1;
    FORE (i, 1, v) t[i] = 0;

    int a;
    FOR (i, 0, d)
    {
        scanf("%d", &a);
        add(a);
    }

    int cnt = 0;
    FORE (i, 0, v)
        if (!t[i])
        {
            add(i);
            ++cnt;
        }

    printf("Case #%d: %d\n", test, cnt);
}

int main()
{
    int test = 1;
    scanf("%d", &test);

    FORE (i, 1, test) rob(i);

    return 0;
}
