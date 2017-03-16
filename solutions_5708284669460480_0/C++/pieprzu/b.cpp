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

const int SIZE = 100;

char K[SIZE+5];
char L[SIZE+5];
char S[SIZE+5];

int cnts[SIZE+5];

int k,l,s;

void dfs(int pos)
{
    if (pos == s)
    {
        bool ok = true;
        int cnt = 0;
        FORE (i, 0, s-l)
        {
            ok = true;
            FOR (j, 0, l)
                if (S[i+j] != L[j])
                {
                    ok = false;
                    break;
                }
            if (ok) ++cnt;
        }

        ++cnts[cnt];
        return;
    }

    FOR (i, 0, k)
    {
        S[pos] = K[i];
        dfs(pos+1);
    }
}

void rob(int test)
{
    scanf("%d %d %d", &k, &l, &s);
    scanf("%s %s", K, L);

    FORE (i, 0, s) cnts[i] = 0;
    dfs(0);

    int mxCnt = 0;
    int sumCnt = 0;
    FORE (i, 0, s)
    {
        mxCnt = cnts[i] > 0 ? i : mxCnt;
        sumCnt += cnts[i];
    }

    double res = 0;
    FORE (i, 0, s)
    {
        res += (double)cnts[i]/(double)sumCnt*(double)i;
    }

    printf("Case #%d: %.6lf\n", test, (double)mxCnt-res);
}

int main()
{
    int test = 1;
    scanf("%d", &test);

    FORE (i, 1, test) rob(i);

    return 0;
}
