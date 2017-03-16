//made by kuailezhish
//gl && hf
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>
#include <complex>
#include <cstring>
#include <ctime>
#define mem(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define lINF 0x3f3f3f3f3f3f3f3fll
#define dINF 1e30
#define eps 1e-8
#define lld long long
#define sqr(x) ((x)*(x))
#define ab(x) (((x)>0) ? (x) : -(x))
#define PI 3.14159265358979323846
#define psl pair<sting,lld>
#define pll pair<lld,lld>
#define pii pair<int,int>
#define mp make_pair
#define er(i) (1ll<<(i))
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define cp complex<double>
#define here printf("!!!!!!!!\n");
#define foreach(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define upmin(a,b) {if ((a)>(b)) (a)=(b);}
#define upmax(a,b) {if ((a)<(b)) (a)=(b);}
#define upmod(a,b) (a)=((a)%(b)+(b))%(b)
#define equ(a,b) (fabs(a-b)<eps)
#define rin freopen("in.txt","r",stdin)
#define pout freopen("out.txt","w",stdout)
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

lld gcd(lld a,lld b){
    if (b==0) return a;
    return gcd(b,a%b);
}

lld p,q;
lld er[50];

int main(){
    lld  i,j,tem,T,cas=0;
    rin; pout;
    er[0]=1;
    for (i=1; i<=44; i++)
        er[i]=er[i-1]*2ll;
    scanf("%lld",&T);
    while (T--){
        scanf("%lld/%lld",&p,&q);
        lld g=gcd(p,q);
        p/=g; q/=g;
        for (i=1; i<=41; i++) if (er[i]==q) break;
        if (i>41){
            printf("Case #%lld: impossible\n",++cas);
        }else{
            for (i=1; i<=41; i++)
                if (p*er[i]>=q) break;
            printf("Case #%lld: %lld\n",++cas,i);
        }
    }
    
    return 0;
}















