#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

double p[100100];

int main() {
    int nt;

    scanf(" %d",&nt);
    for (int ct=1;ct<=nt;ct++) {
        int a,b;

        scanf("%d%d",&a,&b);

        REP(i,a) scanf(" %lf",&p[i]);

        double res=2+b, prd=1;

        REP(i,a+1) {
            double e=prd*(a-i+b-i+1)+(1-prd)*(a-i+b-i+b+2);

            res=min(res,e);
            prd*=p[i];
        }
        
        printf("Case #%d: %.8lf\n",ct,res);
    }
    return 0;
}
