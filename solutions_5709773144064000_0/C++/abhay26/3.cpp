/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <bitset>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
//int dx[]= {-1,0,1,0};
//int dy[]= {0,1,0,-1};
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
   // cout << t << endl;
    double C,F,X;
    FOR(z,t)
    {

        scanf("%lf %lf %lf",&C,&F,&X);
        double ans = 1000000000;

        double cur = 2.0;
        double now = 0.0;
        int gg = 1000000;
        while(1)
        {
            double tmp = X/cur;
            ans = min(ans, now+tmp);
            now += C/cur;
            cur += F;
            if(now > ans)
                break;
        }
        printf("Case #%d: ",z+1);
        printf("%.7lf\n",ans);
    }
return 0;
}
