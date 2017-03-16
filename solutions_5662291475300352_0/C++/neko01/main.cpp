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
    freopen("C-small-1-attempt0.in" , "r" , stdin);
    freopen("C-small-1-attempt0.out" , "w" , stdout);
    int t,cnt=0;
    scanf("%d",&t);
    while(t--){
        int d1,d2,d,t1,t2,n,h,m;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&d,&h,&m);
            if(h==2){
                d1=d,d2=d;
                t1=m,t2=m+1;
            }
            if(i==0&&h==1){
                d1=d;
                t1=m;
            }
            if(i==1&&h==1){
                d2=d;
                t2=m;
            }
        }
        if(t1<t2){
            swap(t1,t2);
            swap(d1,d2);
        }
        double tmp1=(360-d1)*1.0/360*t1;
        double tmp2=(360-d2)*1.0/360*t2;
        if(tmp1>tmp2){
            swap(t1,t2);
            swap(tmp1,tmp2);
        }
        if(tmp1+t1>tmp2)
            printf("Case #%d: 0\n",++cnt);
        else
            printf("Case #%d: 1\n",++cnt);
    }
    return 0;
}
