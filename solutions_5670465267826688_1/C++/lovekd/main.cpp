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

// 1 => 0, i => 1, j => 2, k => 3

int num[4][4] = {
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};
int op[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 1}
};

char s[601000], little[11000];
int L;
LL X;
void solve(void) {
    rst(little, 0);
    rst(s, 0);
    cin >> L >> X;
    cin >> little;
    if(X >= 16) {
        X %= 16;
        X += 16;
    }
    int len = strlen(little);
    int pt = 0;
    for(int st = 0; st < X; st ++ ) {
        for(int i = 0;i < len;i ++ ) {
            s[pt] = little[i];
            pt++;
        }
    }
    //printf("s is %s\n",s);
    int now = 0, o = 0, flag = 0;
    len = pt;
    pt = 0;
    for(int i = pt;i < len; i++) {
        int cc = s[i] - 'h';
        int to = num[now][cc];
        o = (o + op[now][cc]) % 2;
        now = to;
        if(now == 1 && o == 0) {
            flag++;
            pt = i + 1;
            break;
        }
    }
    now = 0, o = 0;
    for(int i = pt;i < len; i++) {
        int cc = s[i] - 'h';
        int to = num[now][cc];
        o = (o + op[now][cc]) % 2;
        now = to;
        if(now == 2 && o == 0) {
            flag++;
            pt = i + 1;
            break;
        }
    }
    now = 0, o = 0;
    for(int i = pt;i < len; i++) {
        int cc = s[i] - 'h';
        int to = num[now][cc];
        o = (o + op[now][cc]) % 2;
        now = to;
    }
    if(now == 3 && o == 0) flag ++;
    printf("Case #%d: ",++iCase);
    if(flag == 3) {
        printf("YES\n");
    }else {
        printf("NO\n");
    }
}

int main(void) {
    iCase = 0;
    //freopen("C-large.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int casenum; scanf("%d",&casenum);
    while(casenum--) solve();
}
