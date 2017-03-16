#include <iostream>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <numeric>
#include <list>
#include <stack>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <functional>

#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef  long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VII;
typedef priority_queue<int> PQI;
const int Mod = 1e9 + 7;
inline LL FIX(LL a) {return (a % Mod + Mod) % Mod;}
#define MP(x,y) make_pair(x,y)
#define LEN(x) ((int)x.length())
#define SZ(x) ((int)x.size())
#define take(x,y) (((x)>>(y)) & 1ll)
#define mv(n) (1<<(n))
#define what_is(x) cerr << #x << " is " << x << endl;
#define eb emplace_back
#define pb push_back
#define UNQ(x) (sort(begin(x),end(x)),x.erase(unique(begin(x),end(x)),end(x)))






int a[1024];
int n;

int gao(int Max) {
    int ret = 0;
    for(int i = 0;i < n;i++) {
        if(a[i] <= Max) continue;
        if(a[i] % Max == 0) ret += a[i] / Max - 1;
        else ret += a[i]/Max;
    }
    return ret;
}
int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T,cas = 0;
    cin>>T;
    while(T--) {
        scanf("%d",&n);
        for(int i = 0;i < n;i++) scanf("%d",&a[i]);
        int Max = *max_element(a,a + n);
        int ret = Max;
        for(int i = 1;i <= Max;i++) {
            ret = min(ret,i + gao(i));
        }
        printf("Case #%d: %d\n",++cas,ret);
    }
    return 0;
}

















