/**
 * @author neko01
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define clr(a) memset(a,0,sizeof a)
#define clr1(a) memset(a,-1,sizeof a)
#define dbg(a) printf("%d\n",a)
typedef pair<int,int> pp;
const double eps=1e-9;
const double pi=acos(-1.0);
const int INF=0x3f3f3f3f;
const LL inf=(((LL)1)<<61)+5;
LL n;
LL aNum;
LL a[100];
LL gao()
{
    LL nn=n;
    if(n<=10) return n;
    LL tmp=n;
    aNum=0;
    while(tmp) a[++aNum]=tmp%10,tmp/=10;
    LL ans=10;
    int B=2;
    LL cur=10;
    while(B<aNum){
        ans+=cal(cur,cur*10-1,B);
        ans++;
        cur*=10;
        B++;
    }
    if(n==cur) return ans;
    int allZero=1;
    if(a[1]==0){
        a[1]=9,a[2]--;
        for(int i=2;i<=aNum;i++)
        {
            if(a[i]>=0) break;
            a[i]+=10;
            a[i+1]--;
        }
        ans++;
        n--;
    }
    LL A=n-cur;
    for(int i=aNum;i>=1;i--){
        LL tmp=0;
        for(int j=i;j<=aNum;j++) tmp=tmp*10+a[j];
        tmp++;
        LL P=0;
        for(int j=i-1;j>=1;j--) P=P*10+a[j];
        if(P==0) continue;
        P--;
        tmp+=P;
        if(tmp<A) A=tmp;
    }
    return ans+A;
}

int main()
{
    int t,cnt=0;
        freopen("A-large (1).in" , "r" , stdin);
        freopen("A-large (1).out" , "w" , stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        LL nn=n;
        LL ans=gao();
        printf("Case #%d: %lld\n",++cnt,ans);
    }
    return 0;
}
