#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

typedef long long LL;

LL f[100][100];
int val[100];
int main(){
    int E,R,N,i,e,cost,tcas=1;
    int tt;
    freopen("B-small-attempt0.in","r",stdin);    freopen("B-small-attempt0.out","w",stdout);

    scanf("%d",&tt);
    while(tt--){
        scanf("%d%d%d",&E,&R,&N);
        LL ans = 0;
        for (i=0;i<N;i++)
            scanf("%d",&val[i]);
        memset(f,-1,sizeof(f));
        f[0][E] = 0;
        for(i=0;i<=N;i++)
            for (e = 0;e<=E;e++)
            if (f[i][e]>-1){
                if (i==N){
                    ans = max(ans,f[i][e]);
                    continue;
                }
                for (LL cost = 0;cost<=e;cost++){
                    int tmp = min(e-cost+R,1LL*E);
                    f[i+1][tmp] = max(f[i+1][tmp],f[i][e]+cost*val[i]);
                }
            }
        printf("Case #%d: ",tcas++);
        cout<<ans<<endl;
    }
}
        
