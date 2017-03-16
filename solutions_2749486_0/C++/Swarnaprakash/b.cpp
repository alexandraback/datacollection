// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int INF = 0x3f3f3f3f;
const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

const int M = 500;
const int offset = 250;
int xprev[M][M];
int yprev[M][M];

char get_dir(int cx, int cy, int px, int py) {
    if(cx < px && cy == py) return 'W';
    if(cx > px && cy == py) return 'E';
    if(cy > py && cx == px) return 'N';
    if(cy < py && cx == px) return 'S';
    return 'Z';
}


void compute() {

    SET(xprev, 0x3f);


    queue<int> Q;
    Q.push(0);
    Q.push(0);
    Q.push(42000);
    Q.push(42000);
    Q.push(0);

    while(!Q.empty()) {
        int cx = Q.front();Q.pop();
        int cy = Q.front();Q.pop();
        int px = Q.front();Q.pop();
        int py = Q.front();Q.pop();
        int cn = Q.front();Q.pop();

        if(cx + offset >= M || cy + offset >= M || cx + offset < 0 || cy + offset < 0 || xprev[cx + offset][cy + offset] != INF) continue;

        xprev[cx + offset][cy + offset] = px;
        yprev[cx + offset][cy + offset] = py;

        ++cn;
        Q.push(cx + cn);Q.push(cy);Q.push(cx);Q.push(cy);Q.push(cn);
        Q.push(cx - cn);Q.push(cy);Q.push(cx);Q.push(cy);Q.push(cn);
        Q.push(cx);Q.push(cy + cn);Q.push(cx);Q.push(cy);Q.push(cn);
        Q.push(cx);Q.push(cy - cn);Q.push(cx);Q.push(cy);Q.push(cn);
    }

}

int main() {
    int tc;
    scanf("%d", &tc);
    compute();
    for(int t=1;t<=tc;++t) {
        int x,y;
        scanf("%d %d", &x, &y);
        string ans;
        int cx = x;
        int cy = y;
        while(cx !=42000) {
            char c =  get_dir(cx, cy, xprev[cx + offset][cy + offset], yprev[cx + offset][cy + offset]);
            if ( c != 'Z') ans += c;
            int ncx = xprev[cx + offset][cy + offset];
            int ncy = yprev[cx + offset][cy + offset];

            cx = ncx;
            cy = ncy;

        }
        reverse(ALL(ans));
        printf("Case #%d: %s\n",t, ans.c_str());
    }
    return 0;
}

