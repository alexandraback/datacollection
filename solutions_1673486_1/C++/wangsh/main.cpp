#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define FORALL(a,b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)
#define FOR(i,a,b) for(int i = a; i < (int)(b); ++i)

typedef long long LL;

const double EPS = 1e-6;
const int INF = 1<<29;
const int MAX = 100010;

int A, B;
double p[MAX];
double s[MAX];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t, cas = 0;
    scanf("%d", &t);
    s[0] = 0.0;
    while (t--){
        double ans = 1e99;
        scanf("%d %d", &A, &B);
        for (int i = 1; i <= A; ++i) scanf("%lf", &p[i]);
        double remain = 1.0;
        for (int i = 1; i <= A; ++i){
            remain*=p[i];
            s[i] = remain;
        }

        int rest = B-A;
        for (int i = 0; i <= A; ++i){
            double tmp = (1-s[A-i])*(i*2+rest+1+B+1)+s[A-i]*(i*2+rest+1);
            if (ans > tmp) ans = tmp;
        }
        if (ans > B+2.0) ans = B+2.0;
        printf("Case #%d: %.6lf\n", ++cas, ans);
    }

    return 0;
}

