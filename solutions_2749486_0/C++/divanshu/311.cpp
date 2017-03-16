/* Divanshu Garg */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
int ABS(int a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code bgins here */

void pre() {

}

inline void openfiles() {
    freopen("input.in","r",stdin);
    freopen ("output.txt", "w", stdout);
}

int remember[105][105][2][2][105];
string pp = "NSEW";
int f1,f2;
int isNegative (int x)
{
    return (x<0?1:0);
}
string ans;
int x,y;
int chk;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int f (int sx, int sy, int ff1, int ff2, int moves, string ss)
{
    if (chk == 1) {
        return 10000;
    }
    if (sx == x && sy == y && ff1 == f1 && ff2 == f2) {
        ans = ss;
        chk = 1;
        return 0;
    }
    int &ans = remember[sx][sy][ff1][ff2][moves];
    if (ans != -1) {
        return ans;
    }
    if (ff1 == 1) sx = sx * (-1);
    if (ff2 == 1) sy = sy * (-1);

    ans = 10000;
    int i,px,py;
    F (i, 0, 4) {
        px = sx + (moves+1)*dx[i];
        py = sy + (moves+1)*dy[i];
        if (abs(px) > 100 || abs(py) > 100) continue;
        if (chk == 1) return 10000;
        int temp = 1 + f (abs (px), abs (py), isNegative (px), isNegative (py), moves+1, ss + pp[i]);
        ans = min(ans,temp);
    }
    return ans;
}


int main()
{
    pre();
    int t,tests=1;
    openfiles();
    S (t);
    while (t--) {
        M(remember,-1);
        S (x);  S (y);
        f1 = isNegative(x);
        f2 = isNegative(y);
        chk = 0;
        x = abs (x);    y = abs (y);
        int k = 1 + f (0, 0, 0, 0, 0, "");
        cout << "Case #" << tests << ": " << ans << endl;
        tests++;
    }
    return 0;
}
