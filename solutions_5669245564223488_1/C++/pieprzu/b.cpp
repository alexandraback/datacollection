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

const int MAXN = 1000;
const int SIZE = 1000;
const int LETTERS = 30;
const ll MOD = 1000000007;

char s[MAXN][SIZE];
int nn [MAXN];

int in[LETTERS];
int pref[LETTERS];
int suf[LETTERS];
int full[LETTERS];

bool isLetter[LETTERS];

vi t[LETTERS];
int vis[LETTERS];

ll fact(int x)
{
    ll res = 1;
    FORE (i, 1, x) res = (res*i)%MOD;

    return res;
}

bool isCycle(int v, int tm)
{
    //printf("isCycle(%d)\n", v);
    vis[v] = tm;
    FOREACH (w, t[v])
    {
        if (vis[*w] == tm) return true;
        if (vis[*w]) return false;
        if (isCycle(*w, tm)) return true;
    }

    return false;
}

void rob(int cs)
{
    int n;
    scanf("%d", &n);

    FOR (i, 0, n)
    {
        scanf("%s", s[i]);
        nn[i] = strlen(s[i]);
    }

    FORE (letter, 'a', 'z')
    {
        in[letter-'a'] = pref[letter-'a'] = suf[letter-'a'] = full[letter-'a'] = 0;
        isLetter[letter-'a'] = 0;
        vis[letter-'a'] = 0;
        t[letter-'a'].clear();
        FOR (i, 0, n)
        {
            int j = 0;
            for (j = 0; j < nn[i] && s[i][j] == letter; ++j);

            if (j && j < nn[i])
            {
                for (; j < nn[i]; ++j)
                    if (s[i][j] == letter)
                    {
                        printf("Case #%d: 0\n", cs);
                        return;
                    }
                ++pref[letter-'a'];
                t[letter-'a'].PUB(s[i][nn[i]-1]-'a');
            }
            else if (j && j == nn[i])
            {
                ++full[letter-'a'];
            }
            else
            {
                for (; j < nn[i] && s[i][j] != letter; ++j);
                if (j != nn[i])
                {
                    for (; j < nn[i] && s[i][j] == letter; ++j);
                    if (j == nn[i])
                    {
                        ++suf[letter-'a'];
                    }
                    else
                    {
                        for (; j < nn[i]; ++j)
                            if (s[i][j] == letter)
                            {
                                printf("Case #%d: 0\n", cs);
                                return;
                            }
                        ++in[letter-'a'];
                    }
                }
            }

            if (in[letter-'a']+pref[letter-'a']+suf[letter-'a']+full[letter-'a']) isLetter[letter-'a'] = 1;
        }
    }

    ll res = 1;

    /*FOR (i, 0, 26)
    {
        if (isLetter[i])
        {
            printf("%c: ", i+'a');
            FOREACH (w, t[i]) printf("%d ", *w);
            printf("\n");
        }
    }*/

    int movable = 0;
    int tm = 0;
    FORE (letter, 'a', 'z')
    {
        //printf("%c: (%d,%d,%d,%d)\n", letter, in[letter-'a'], pref[letter-'a'], suf[letter-'a'], full[letter-'a']);
        if (in[letter-'a'])
        {
            if (pref[letter-'a']+suf[letter-'a']+full[letter-'a'])
            {
                printf("Case #%d: 0\n", cs);
                return;
            }
        }
        else if (pref[letter-'a'] > 1 || suf[letter-'a'] > 1)
        {
            printf("Case #%d: 0\n", cs);
            return;
        }
        else if (pref[letter-'a'] == 0 && isLetter[letter-'a'])
        {
            ++movable;
        }

        if (isLetter[letter-'a'] && !vis[letter-'a'] && isCycle(letter-'a', ++tm))
        {
            printf("Case #%d: 0\n", cs);
            return;
        }

        res = (res * fact(full[letter-'a']))%MOD;
        //printf("\n");
    }

    res = (res*fact(movable))%MOD;

    printf("Case #%d: %I64d\n", cs, res);
}

int main()
{
    int test = 1;
    scanf("%d", &test);

    FORE (i, 1, test) rob(i);

    return 0;
}
