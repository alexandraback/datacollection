#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <list>
#include <cstring>
#include <map>
#include <cmath>

#define FOREACH(a,c) for(__typeof((c).begin()) a = (c).begin(); a != (c).end(); a++)
#define MP(i,j) make_pair(i,j)

using namespace std;

typedef pair<double, double> PDD;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<PDD> VDD;

VDD P;

int main(){
    int T; scanf ("%d", &T);
    for (int w = 0; w < T; w++){
        double D; int N, A;  scanf ("%lf %d %d", &D, &N, &A);
        P.clear();
        for (int i = 0; i < N; i++){
            double a,b;
            scanf ("%lf %lf", &a,&b);
            P.push_back(MP(a,b));
        }
        printf ("Case #%d: \n", w+1);
        for (int i = 0; i < A; i++){
            double a; scanf ("%lf", &a);
            double delay = 0;
            for (int i = 0; i < N; i++){
                double t = P[i].first, x = P[i].second;
                if (P[i].second > D){
                    if (i == 0) break;
                    x = D;
                    t = P[i-1].first + (P[i].first - P[i-1].first)*((D-P[i-1].second)/(P[i].second-P[i-1].second));
        //            printf ("MOD : %lf %lf", x, t);
                }
                if (a*(t-delay)*(t-delay)/2 > x){
        //            printf ("del %lf t %lf x %lf a %lf iloraz %lf\n", delay, t, x, a, 2*x/a);
                    delay = t - sqrt(2*x/a);
                }
        //        printf ("delay : %d : %lf\n", i, delay);
            }
            printf ("%.9lf\n", delay+sqrt(2*D/a));
        }
    }
    return 0;
}
