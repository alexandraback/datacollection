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
#define mod 1010101
#define Pi acos(-1.0)
#define link fjksldfjaslkdfjas
#define y1 fksjdlf
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int iCase;
LL gcd(LL a,LL b){
    LL temp;
    while(b){
        temp = a % b;
        a = b;
        b = temp;
    }return a;
}
void solve(void){
    LL p , q;
    char op;
    scanf("%I64d%c%I64d",&p,&op,&q);
    printf("Case #%d: ",++iCase);
    if(p > q){
        printf("impossible\n");
        return;
    }
    LL gggcd = gcd(p,q);
    p /= gggcd , q /= gggcd;
    int ans = 0;
    int rem = 40;
    while(p < q && rem > 0){
        p *= 2LL;
        ans++;
        rem--;
    }
    if(p < q){
        printf("impossible\n");
        return;
    }
    gggcd = gcd(p,q);
    p /= gggcd , q /= gggcd;
    bool ok = false;
    while(rem > 0){
        if(q == 1){
            ok = true;
            break;
        }
        if(q % 2){
            ok = false;
            break;
        }
        q /= 2;
        rem--;
    }
    if(ok){
        printf("%d\n",ans);
    }else{
        printf("impossible\n");
    }
}
int main(void){
    //freopen("A-large.in","r",stdin);
    //freopen("out.out","w",stdout);
    iCase = 0;
    int casenum; scanf("%d",&casenum);
    while(casenum--) solve();
    return 0;
}
