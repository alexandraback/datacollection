#define FNAME ""

#include <bits/stdc++.h>

#define hash padjf9srpi
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (n); i++)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (a); i < (b); i++)
#define gcd __gcd
#define all(a) (a).begin(), (a).end()
 
#ifdef _WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;
typedef vector <int> vi;

template <class T> T sqr(const T &a) {return a * a;}

int T, cnt[300], ans[300];
char s[100000];

int main()
{
#ifdef LOCAL
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);
#endif
    scanf("%d ", &T);
    forn(qq, T) {
        gets(s);
        int n = strlen(s);
        forn(i,26)
            cnt[i + 'A'] = 0;
        forn(i, n)
            cnt[s[i]]++;
        forn(i, 10)
            ans[i] = 0;
        
        ans[8] = cnt['G'];
        for (char c : "EIHTG")
            cnt[c] -= cnt['G'];
        
        ans[0] = cnt['Z'];
        for (char c: "EROZ")
            cnt[c] -= cnt['Z'];
        
        ans[4] = cnt['U'];
        for (char c : "FORU")
            cnt[c] -= cnt['U'];
    
        ans[5] = cnt['F'];
        for (char c : "IVEF")
            cnt[c] -= cnt['F'];
        
        ans[7] = cnt['V'];
        for (char c : "SEENV")
            cnt[c] -= cnt['V'];
        
        ans[6] = cnt['S'];
        for (char c: "IXS")
            cnt[c] -= cnt['S'];
        
        ans[2] = cnt['W'];
        for (char c : "TOW")
            cnt[c] -= cnt['W'];

        ans[1] = cnt['O'];
        for (char c : "NEO")
            cnt[c] -= cnt['O'];
        
        ans[3] = cnt['T'];
        for (char c : "HREET")
            cnt[c] -= cnt['T'];
    
        ans[9] = cnt['E'];
        for (char c : "NINE")
            cnt[c] -= cnt['E'];

        forn(i, 26)
            assert(cnt[i + 'A'] == 0);            
        printf("Case #%d: ", qq + 1);
        forn(i, 10)
            forn(j, ans[i])
                printf("%d", i);
        puts("");
    }

}

