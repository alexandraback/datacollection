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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("A-large (1).in","r",stdin);
	freopen("out.txt","w",stdout);
#endif
    int T;
    long double r,t;
    RI(T);
    for(int kase=1;kase<=T;++kase){
        cin>>r>>t;
        //r = (long double)1.0-(long double)2.0*r;
        long double L,R,M;
        long double l2 = 2.0,l1=1.0;
        L=0;R = t;
        while(R-L > 1e-8){
            M = (R-L)/2.0 + L;
            //cout<<M<<endl;
            long double k = t/M,m = l2*M-l1+l2*r;
            if(m-k>1e-18)R = M;
            else L=M;
        }
        //LL ans = floor(R);
        cout<<"Case #"<<kase<<": "<<R<<endl;
    }
}
