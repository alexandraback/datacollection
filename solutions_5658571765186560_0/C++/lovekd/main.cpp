//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>   //我是沙茶....今天又写搓了。。
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <utility>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):(-(x)))
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define FORD(i,a,b) for(int i = (a);i>=(b);i--)
#define REP(i,n) for(int i = 0;i<(n);i++)
#define rst(x,k) memset(x,k,sizeof(x))
#define lowbit(x) ((x)&(-(x)))
#define h(x) (1<<(x))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define eps 1e-9
#define INF 1500000000
#define maxn 110000
#define mod  1000000007LL
#define HASHMOD 3894229
#define Pi acos(-1.0)
#define link fjksldfjaslkdfjas
#define y1 fksjdlf
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int iCase;

int x, row, col;

void solve(void) {
    scanf("%d%d%d",&x,&row,&col);
    if(row > col) swap(row, col);
    int flag = -1;
    if(x == 1) {
        flag = 1;
    }else if(x == 2) {
        if(row * col % 2 == 0) {
            flag = 1;
        }else {
            flag = 0;
        }
    }else if(x == 3) {
        if(row == 1 || col == 1) {
            flag = 0;
        }else if(row == 2) {
            if(col % 3 == 0) {
                flag = 1;
            }else {
                flag = 0;
            }
        }else if(row == 3) {
            if(col % 2 == 0) {
                flag = 1;
            }else {
                flag = 0;
            }
        }else if(row == 4) {
            if(col % 3 == 0) {
                flag = 1;
            }else {
                flag = 0;
            }
        }
    }else if(x == 4) {
        flag = 0;
    }
    if(row * col < x || row * col % x != 0) {
        flag = 0;
    }
    printf("Case #%d: ",++iCase);
    if(flag == -1) {
        printf("fuck!!\n");
    }else if(flag == 0) {
        printf("RICHARD\n");
    }else if(flag == 1) {
        printf("GABRIEL\n");
    }
}

int main(void) {
    iCase = 0;
    //freopen("D-small-attempt1.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int casenum; scanf("%d",&casenum);
    while(casenum--) solve();
}
