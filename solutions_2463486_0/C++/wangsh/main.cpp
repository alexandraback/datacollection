#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define FORALL(a,b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)
#define FOR(i,a,b) for(int i = a; i < (int)(b); ++i)

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

typedef long long LL;

const double EPS = 1e-6;
const int INF = 1<<29;

const int MAX = 10000000;

vector<LL> ret;

bool isPalindrome(char *s){
    int len = strlen(s);
//    printf("s = %s\n", s);
    for (int i = 0, j = len-1; i < j; ++i, --j)
        if (s[i] != s[j])
            return 0;
    return 1;
}

void Dfs(int length, LL v, bool leadz){
    if (length > 7) return;
    if (v > MAX) return;
    if (length && !leadz){
        LL v2 = v*v;
        char s[20]={};
//        printf("v = %I64d\n", v);
        sprintf(s,"%I64d",v2);
        if (isPalindrome(s)) ret.push_back(v);
    }

    for (int i = 0; i < 10; ++i){
        LL base = 1;
        for (int j = 0; j < length; ++j) base *= 10;
        LL tmp = base*i+v;
        tmp = tmp*10 + i;
        Dfs(length+2, tmp, i == 0 ? true : false);
    }
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t, cas = 0;
    LL a, b;

    Dfs(0,0,true);
    for (int i = 0; i < 10; ++i) Dfs(1,i,i == 0 ? true : false);

    scanf("%d", &t);

    while (t--){

        scanf("%I64d %I64d", &a, &b);
        int cnt = 0;
        for (int i = 0; i < (int)ret.size(); ++i){
            LL v = ret[i]*ret[i];
            if (a <= v && v <= b) ++cnt;
        }

        printf("Case #%d: %d\n", ++cas, cnt);
    }

    return 0;
}
