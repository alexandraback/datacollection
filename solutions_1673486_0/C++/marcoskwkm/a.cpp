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
#include <set>
#include <map>
using namespace std;

#define debug(args...) fprintf(stderr,args);

typedef long long lint;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;

double ch[10];
double ex[10];

int main() {
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        memset(ch,0,sizeof(ch));
        memset(ex,0,sizeof(ex));
        int A,B;
        scanf("%d%d",&A,&B);
        for(int a=0;a<A;++a) scanf("%lf",&ch[a]);
        for(int a=0;a<(1<<A);++a) {
            //printf("a = %d...",a);
            double prob = 1;
            for(int b=0;b<A;++b) {
                if(a&(1<<b)) prob *= ch[b];
                else prob *= 1-ch[b];
            }
            //printf("prob = %lf\n",prob);
            bool ok = 1;
            for(int b=1;b<=A;++b) {
                //printf("b=%d...",b);
                if(a&(1<<(b-1)) && ok) {
                    //printf("OK!\n");
                    ex[b] += ( A-b + B-b + 1)*prob;
                }
                else {
                    ok = 0;
                    //printf("NO!\n");
                    ex[b] += ( A-b + B-b + 1 + B + 1)*prob;
                }
            }
        }
        //for(int a=1;a<=A;++a) printf("%d: %lf\n",a,ex[a]);
        double best = INF;
        for(int a=1;a<=A;++a) best = min(best, ex[a]);
        printf("Case #%d: %.6lf\n",t,min(best,double(2+B)));
    }
    return 0;
}
