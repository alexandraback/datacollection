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
using namespace std;

#define debug(args...) fprintf(stderr,args);

typedef long long lint;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 220;
const int LIM = 2000;

int s[MAXN];
int T,n,sum;

bool ok(int i,double p) {
    double score = s[i] + p*sum;
    double cont=0;
    for(int a=0;a<n;++a) {
        if(a==i) continue;
        cont += max((score - s[a])/double(sum), 0.0);
    }
    return cont <= 1-p;
}    

double binsrch(int i) {
    double l=0,r=100;
    for(int a=0;a<LIM;++a) {
        double m = (l+r)/2;
        if(ok(i,m/100)) l = m;
        else r = m;
    }
    return l;
}

int main() {
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d: ",t);
        sum = 0;
        scanf("%d",&n);
        for(int a=0;a<n;++a) {
            scanf("%d",&s[a]);
            sum += s[a];
        }
        double target = double(2*sum)/n;
        //for(int a=0;a<n;++a) printf("%.6lf ",max(0.0,100*(target-s[a])/sum));
        for(int a=0;a<n;++a) printf("%.6lf ",binsrch(a));
        printf("\n");
    }        
    return 0;
}
