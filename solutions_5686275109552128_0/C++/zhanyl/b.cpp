#include <vector>
#include <list>
#include <queue>
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
#include <cstring>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

const int maxn=1005;

int n;
int f[maxn];

int check(int x){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(f[i]<=x)continue;
        ans+=(f[i]-1)/x;
    }
    return ans;
}

int main(){
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int Cas=1;Cas<=T;Cas++){
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&f[i]);
            if(f[i]>ans)ans=f[i];
        }
        for(int i=1;i<=ans;i++)
            ans=min(ans,check(i)+i);
        printf("Case #%d: %d\n",Cas,ans);
    }
    return 0;
}
