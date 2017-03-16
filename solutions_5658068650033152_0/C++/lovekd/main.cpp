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
//#define abs(x) ((x)>0?(x):(-(x)))
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define FORD(i,a,b) for(int i = (a);i>=(b);i--)
#define REP(i,n) for(int i = 0;i<(n);i++)
#define rst(x,k) memset(x,k,sizeof(x))
#define lowbit(x) ((x)&(-(x)))
#define h(x) (1<<(x))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define eps 1e-7
#define INF 100000000
#define maxn 1100
#define mod 1000000007LL
#define Pi acos(-1.0)
#define link fjksldfjaslkdfjas
#define y1 fksjdlf
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int iCase ;
int row , col , k;
struct aa{
    int ind;
    int s;
    bool operator < (const aa & t)const{
        return s < t.s;
    }
}a[2011];
void solve(void){
    scanf("%d%d%d",&row,&col,&k);
    printf("Case #%d: ",++iCase);
    if(row <= 2 || col <= 2){
        printf("%d\n",k);
        return;
    }
    FOR(i,0,2010){
        a[i].ind = i;
        a[i].s = 0;
    }
    FOR(i,1,row-2){
        FOR(j,1,col-2){
            int tt = 2 * i + 2 * j;
            int ss = 2 * i + 2 * j + i * j;
            if(a[tt].s < ss){
                a[tt].s = ss;
            }
        }
    }
    sort(a,a+2011);
    int ans = k;
    FOR(i,0,2010){
        int tt = a[i].ind;
        if(a[i].s < k){
            tt += (k - a[i].s);
        }
        if(tt < ans) ans = tt;
    }
    printf("%d\n",ans);
}
int main(void){
    //freopen("C-small-attempt2.in","r",stdin);
    //freopen("out.out","w",stdout);
    iCase = 0;
    int casenum; scanf("%d",&casenum);
    while(casenum--) solve();
    return 0;
}
