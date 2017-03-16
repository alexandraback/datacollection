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
const int MAXN = 30, MAXS = 1e6;

lint v[MAXN];
vector<int> bucket[MAXS];

int main() {
    int T;
    scanf("%d",&T);    
    for(int t=1;t<=T;++t) {
        for(int a=0;a<MAXS;++a) bucket[a].clear();
        printf("Case #%d:\n",t);
        int n,r1,r2;
        bool found = 0;
        scanf("%d",&n);
        for(int a=0;a<n;++a) scanf("%lld",&v[a]);
        for(int a=1;a<(1<<n) && !found;++a) {
            lint sum=0;
            for(int b=0;b<n;++b) {
                if(a&(1<<b)) sum += v[b];
            }
            for(int b=0;b<bucket[sum].size();++b) {
                if((bucket[sum][b]&a)==0) {
                    found = 1;
                    r1 = bucket[sum][b];
                    r2 = a;
                }
            }
            if(!found) bucket[sum].push_back(a);
        }
        if(found) {
            for(int a=0;a<n;++a) {
                if(r1&(1<<a)) printf("%lld ",v[a]);
            }
            printf("\n");
            for(int a=0;a<n;++a) {
                if(r2&(1<<a)) printf("%lld ",v[a]);
            }
            printf("\n");
        }
        else printf("Impossible\n");     
    }       
    return 0;
}
