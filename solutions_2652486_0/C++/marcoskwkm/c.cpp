#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define foreach(_it,_v) for(typeof(_v.begin()) _it = _v.begin(); _it != _v.end(); ++_it)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXK = 10, MAXN = 10;

int r,n,m,k;
int v[MAXK];
int d[MAXN];

set<string> ans[1000];


int main() {
    for(int a=2;a<=5;++a) {
        for(int b=2;b<=5;++b) {
            for(int c=2;c<=5;++c) {
                string s = "";
                s += '0'+a;
                s += '0'+b;
                s += '0'+c;
                ans[1].insert(s);
                ans[a].insert(s);
                ans[b].insert(s);
                ans[c].insert(s);
                ans[a*b].insert(s);
                ans[a*c].insert(s);
                ans[b*c].insert(s);
                ans[a*b*c].insert(s);
            }
        }
    }    
    scanf("%*d");
    printf("Case #1:\n");
    scanf("%d%d%d%d",&r,&n,&m,&k);
    for(int a=0;a<r;++a) {
        for(int b=0;b<k;++b) scanf("%d",&v[b]);        
        for(string s: ans[v[0]]) {
            bool ok = 1;
            for(int b=1;b<k;++b) {
                if(ans[v[b]].find(s) == ans[v[b]].end()) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                printf("%s\n",s.c_str());
                break;
            }
        }
    }    
    return 0;
}
