#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <tr1/unordered_map>
using namespace std;
using namespace tr1;

#define debug(args...) fprintf(stderr,args);

typedef long long lint;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 550, LIM = 22;

lint v[MAXN];
map<lint,int> mp;

int main() {
    int T;
    scanf("%d",&T);    
    for(int t=1;t<=T;++t) {
        printf("Case #%d:\n",t);
        int n;
        scanf("%d",&n);
        for(int a=0;a<n;++a) scanf("%lld",&v[a]);
        bool found = 0;
        while(!found) {
            mp.clear();
            random_shuffle(v,v+n);
            for(int a=1;a<(1<<LIM);++a) {
                lint sum = 0;
                for(int b=0;b<LIM;++b) {
                    if(a&(1<<b)) sum += v[b];
                }
                mp[sum] = a;
            }
            for(int a=1;a<(1<<LIM) && !found;++a) {
                lint sum = 0;
                for(int b=0;b<LIM;++b) {
                    if(a&(1<<b)) sum += v[b+LIM];
                }
                if(mp.find(sum) != mp.end()) {
                    found = 1;
                    int mask = mp[sum];
                    for(int b=0;b<LIM;++b) {
                        if(mask&(1<<b)) printf("%lld ",v[b]);
                    }
                    printf("\n");
                    for(int b=0;b<LIM;++b) {
                        if(a&(1<<b)) printf("%lld ",v[b+LIM]);
                    }
                    printf("\n");
                    debug("Done case %d\n",t);
                }
            }
        }
    }       
    return 0;
}
