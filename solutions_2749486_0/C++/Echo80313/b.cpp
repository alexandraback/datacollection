#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <climits>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#define REP(i,n) for( int (i)=0;(i)<(int)(n); ++(i))
#define REPR(i,n) for( int (i) = n; (i)>=0; --(i))
#define REPN(i,x,y) for( int i = x; (i) < (int)(y); (i)++ )
#define REPIT(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define ZERO(x) memset(x,0,sizeof(x))
#define RI(n) scanf("%d",&(n))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define OI(x) printf("%d\n",(x))
#define OII(x,y) printf("%d %d\n",(x),(y))
#define FT first
#define SD second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
LL LLMAX = 9223372036854775807LL;
const int MOD = 1000000007;
const int maxn = 100000+10;
int T;
int x,y;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt1 (2).in","r",stdin);
	freopen("out.txt","w",stdout);
#endif
    RI(T);
    REP(kase,T){
        RII(x,y);
        printf("Case #%d: ",kase+1);
        REP(i,abs(x)-1)printf("EW");
        if(x>0)printf("E");
        else if(x<0) printf("EW");
        if(y>0)REP(i,abs(y))printf("SN");
        else REP(i,abs(y))printf("NS");
        printf("\n");
    }
}
