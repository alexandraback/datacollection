#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif

#define FNAME "1"

const int MAXN = 1e6;
const char *alphabet = "1ijk";
const pair <int, int> go[4][4] = {{mp(0, 0), mp(1, 0), mp(2, 0), mp(3, 0)}, 
                                  {mp(1, 0), mp(0, 1), mp(3, 0), mp(2, 1)}, 
                                  {mp(2, 0), mp(3, 1), mp(0, 1), mp(1, 0)}, 
                                  {mp(3, 0), mp(2, 0), mp(1, 1), mp(0, 1)}};


int T, L, X;
char s[MAXN], r[MAXN];

int next (int a, int b, int &sign)
{
    sign ^= go[a][b].second;
    return go[a][b].first;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        scanf("%d%d\n", &L, &X);
        gets(s);
        int good = 1;
        int curAll = 0, signAll = 0;
        for (int i = 0; i < L; i++)
            curAll = next(curAll, strchr(alphabet, s[i]) - alphabet, signAll);
        if (curAll != 0 && X % 4 != 2)
            good = 0;
        if (curAll == 0 && (signAll == 0 || X % 2 == 0))
            good = 0;
        X = min(X, 10);
        int sz = 0;
        for (int j = 0; j < X; j++)
            for (int i = 0; i < L; i++)
                r[sz++] = s[i];
        int curPref = 0, signPref = 0, indPref = -1;
        for (int i = 0; i < sz; i++)
        {
            curPref = next(curPref, strchr(alphabet, r[i]) - alphabet, signPref);
            if (curPref == 1 && signPref == 0)
            {
                indPref = i;
                break;
            }
        }
        int curSuff = 0, signSuff = 0, indSuff = -1;
        for (int i = sz - 1; i >= 0; i--)
        {
            curSuff = next(strchr(alphabet, r[i]) - alphabet, curSuff, signSuff);
            if (curSuff == 3 && signSuff == 0)
            {
                indSuff = i;
                break;
            }
        }
        printf("Case #%d: ", t + 1);
        if (good && indPref != -1 && indSuff != -1 && indSuff > indPref)
            puts("YES");
        else
            puts("NO");            
    }    
    return 0;
}