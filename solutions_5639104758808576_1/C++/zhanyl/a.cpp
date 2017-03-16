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

bool check(int now){
    for(int i=0;i<=n;i++){
        if(f[i]==0)continue;
        if(i>now)return false;
        now+=f[i];
    }
    return true;
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int Cas=1;Cas<=T;Cas++){
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
            scanf("%1d",&f[i]);
        int ans=0;
        while(!check(ans))ans++;
        printf("Case #%d: %d\n",Cas,ans);
    }
    return 0;
}
