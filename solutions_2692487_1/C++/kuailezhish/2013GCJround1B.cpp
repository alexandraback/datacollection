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
#include <bitset>
#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>
#include <cstring>
#include <ctime>
#define mem(a,b) memset(a,b,sizeof(a));
#define INF 0x3f3f3f3f
#define lldINF 0x3f3f3f3f3f3f3f3fll
#define eps 1e-8
#define lld long long
#define sqr(x) ((x)*(x))
#define ab(x) (((x)>0) ? (x) : -(x))
#define PI 3.14159265358979323846
#define psl pair<sting,lld>
#define pll pair<lld,lld>
#define pii pair<int,int>
#define MP make_pair
#define er(i) (1ll<<(i))
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rin freopen("in.txt","r",stdin)
#define pout freopen("out.txt","w",stdout)
#pragma comment(linker, "/STACK:102400000,102400000")
using std::bitset;
using namespace std;

#define maxn 1000

int a[maxn];
int n,s;

int main(){

freopen("A-large.in","r",stdin);
pout;

    int i,j,tem,T,cas=0;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&s,&n);
        for (i=1; i<=n; i++) scanf("%d",&a[i]);
        if (s==1) {printf("Case #%d: %d\n",++cas,n); continue;}
        sort(a+1,a+1+n);
        int ans=INF;
        for (j=0; j<=n; j++){
            int ma=j,ss=s;
            for (i=1; i<=n-j; i++){
                if (ss>a[i]){ss+=a[i]; continue;}
                while (ss<=a[i]){ss=2*ss-1; ma++;}
                ss+=a[i];
            }
            ans=min(ans,ma);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}






















