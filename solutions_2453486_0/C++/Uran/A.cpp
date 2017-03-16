#ifdef SHTRIX 
#include "/Users/roman/Dev/SharedCpp/DebugOutput.h"
#endif
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).end()-(s).begin())
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define C(a) memset((a),0,sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
//#define x first
//#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())

bool check(const string &s, char symb = 'X') {
    rept(i, L(s)) if (s[i] != symb && s[i] != 'T') return false;
    return true;
}

void solve(int case_id) {
    printf("Case #%d:", case_id);

    vector<string> vs(4);
    rept(i, 4) cin >> vs[i];
    vector<string> trs(4, string(4, 'a'));
    rept(i, 4)
        rept(j, 4)
            trs[i][j] = vs[j][i];

    string d1, d2;
    rept(i, 4) d1 += vs[i][i], d2 += vs[i][3 - i];
    vs.push_back(d1);
    vs.push_back(d2);
    rept(i, L(trs))
        vs.push_back(trs[i]);

    rept(i, L(vs)) 
        if (check(vs[i], 'O')) {
            printf(" O won\n");
            return;
        } else if (check(vs[i], 'X')) {
            printf(" X won\n");
            return;
        }
    rept(i, 4)
        rept(j, 4)
            if (vs[i][j] == '.') {
                printf(" Game has not completed\n");
                return;
            }
    printf(" Draw\n");
}

int main()
{
    #ifdef SHTRIX 
    //freopen("input.txt","rt",stdin); 
    //freopen("output.txt","wt",stdout); 
    #endif
	int TC;
    scanf("%d", &TC);
    rep(tc, TC) {
        solve(tc);
    }
    return 0;
}
