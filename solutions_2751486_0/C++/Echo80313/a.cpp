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
const int maxn = 1000000+10;
int T,n;
char L[maxn];
bool vo(char c){
    return c == 'a' || c=='e' ||c=='i' ||c=='o' ||c=='u';
}
bool good(char* s,int len){
    int cnt=0;
    //REP(i,len)printf("%c",s[i]);
    //printf("\n");
    REP(i,len){
        if(!vo(s[i]))cnt++;
        else cnt=0;
        if(cnt==n)return true;
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt0 (2).in","r",stdin);
	freopen("out.txt","w",stdout);
#endif
    RI(T);scanf("%*c");
    REP(kase,T){
        LL ans=0;
        scanf("%s%d\n",L,&n);
        int len = strlen(L);
        for(int i=0;i<len;++i)
            for(int j=i;j<len;++j)
                if(good(L+i,j-i+1))ans++;

        printf("Case #%d: %lld\n",kase+1,ans);
    }
}
