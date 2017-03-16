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
int main()
{
    int t,cnt=0;
    freopen("D-small-attempt3.in" , "r" , stdin);
    freopen("D-small-attempt3.out" , "w" , stdout);
    scanf("%d",&t);
    while(t--){
        int x,r,c;
        scanf("%d%d%d",&x,&r,&c);
        int ans=0;
        if(x==1)
            ans=1;
        if(x==2){
            if(r%2==0||c%2==0)
                ans=1;
        }
        if(x==3){
            if((r>=2&&c%3==0)||(r%3==0&&c>=2))
                ans=1;
        }
        if(x==4)
        {
            if((r>=3&&c%4==0)||(r%4==0&&c>=3))
                ans=1;
        }
        if(ans)
            printf("Case #%d: GABRIEL\n",++cnt);
        else
            printf("Case #%d: RICHARD\n",++cnt);
    }
    return 0;
}
