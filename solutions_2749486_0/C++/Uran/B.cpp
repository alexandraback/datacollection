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
#include <cassert>
char res[555];
int cres;

int dx[] = {0, 1, 0, -1},
    dy[] = {1, 0, -1, 0};
char D[] = {'N', 'E', 'S', 'W'};

inline int sgn(int x) {
    if (x < 0) return -1;
    if (x > 0) return +1;
    return 0;
}

inline bool EXECUTE(int x, int y) {
    int curx = 0, cury = 0;
    rept(i, cres) {
        rept(k, 4)
            if (D[k] == res[i]) {
                curx += (i + 1) * dx[k];
                cury += (i + 1) * dy[k];
                break;
            }
    }
    //cerr << curx << " " << cury << endl;
    return curx == x && cury == y;
}

void solve(int case_id) {
    int x, y;
    scanf("%d%d", &x, &y);
    int curx = 0, cury = 0;
    cres = 0;
    while (curx != x || cury != y) {
        int dcx = x - curx, dcy = y - cury;
        if (dcx) {
            if (sgn(dcx) == dx[1]) {
                res[cres++] = D[3];
                res[cres++] = D[1];
                curx += dx[1];
            } else {
                res[cres++] = D[1];
                res[cres++] = D[3];                
                curx += dx[3];
            }
            continue;
        }
        if (dcy) {
            if (sgn(dcy) == dy[0]) {
                res[cres++] = D[2];
                res[cres++] = D[0]; 
                cury += dy[0];
            } else {
                res[cres++] = D[0];
                res[cres++] = D[2];                
                cury += dy[2];
            }
            continue;
        }
    } 
    res[cres] = 0;
    //cerr << "CHECKING: " << EXECUTE(x, y) << endl;
    assert(EXECUTE(x, y));
    printf("Case #%d: %s\n", case_id, res);
}

int main()
{
    #ifdef SHTRIX 
    freopen("input.txt","rt",stdin); 
    //freopen("output.txt","wt",stdout); 
    #endif
	int TC;
    scanf("%d", &TC);
    rep(tc, TC) {
        solve(tc);
    }
    return 0;
}
