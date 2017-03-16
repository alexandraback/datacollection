#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <string.h>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define forn(i, n) for (int i=0; i<(n); ++i)

string s = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string t = "our language is impossible to understand there are twenty sixfactorial possibilities so it is okay if you want to just give up";

int m[32], b[32];
char a[256];
char u[256];

string func(string s)
{
    string t;
    forn (i, sz(s)) if (s[i]!= ' ') t+=s[i];
    return t;
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    s = func(s); t = func(t);

    forn (i, 32) m[i] = -1, b[i] = -1;

    for (int i=0; i<sz(s); ++i) if (s[i] != ' ') m[s[i]-'a'] = t[i]-'a';
//    forn (i, 26) printf("%d ", m[i]); puts("");

    set<int> h; forn (i, 26) if (m[i] != -1) h.insert(m[i]);
    forn (i, 26) if (m[i] == -1)
    {
        for (int j=25; j>=0; --j) if (h.count(j) == 0)
        {
            m[i] = j;
            h.insert(j);
            break;
        }
    }

//    forn (i, 26) printf("%d ",m[i]); puts("");
    int tc; scanf("%d", &tc);gets(a);
    for (int tt=1; tt<=tc; ++tt)
    {
        gets(a);
        int n = strlen(a);
        forn (i, n) if (a[i] != ' ') a[i] = 'a' + m[a[i]-'a'];
        printf("Case #%d: %s\n", tt, a);

    }

    return 0;
}
