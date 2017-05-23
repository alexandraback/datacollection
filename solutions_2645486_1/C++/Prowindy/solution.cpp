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

typedef long long LLD;

int val[10100],next[10100];
int main(){
    int E,R,N,i,e,cost,tcas=1,j;
    int tt;
    freopen("B-large.in","r",stdin);    freopen("B-large.out","w",stdout);

    scanf("%d",&tt);
    while(tt--){
        scanf("%d%d%d",&E,&R,&N);
        LLD ans = 0;
        for (i=0;i<N;i++)
            scanf("%d",&val[i]);
        next[N] = N;
        for (i=N-1;i>=0;i--){
            for (j=i+1;j<N&&val[j]<val[i];j=next[j]);
            next[i] = j;
        }
        LLD now = E;
        for (i=0;i<N;i++){
            LLD should = 0;
            if (next[i]==N){
                should = now;
            }else {
                should = 1LL*(next[i]-i)*R;
            }
            should = min(now,should);
            now-=should;
            ans+=should*val[i];
            now+=R;
        }
        printf("Case #%d: ",tcas++);
        cout<<ans<<endl;
    }
}
        
