#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 100100
using namespace std;
double per[maxn];
double ps[maxn];
double pv[maxn];
int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-large.in", "r", stdin);
    freopen("A-ans.txt", "w", stdout);
    int t, n, m;
    double res;
    scanf("%d", &t);
    for(int _ca=1;_ca<=t;_ca++){
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;i++){
            scanf(" %lf", &per[i]);
        }
        res = 1e11;
        ps[0] = per[0];
        for(int i=1;i<n;i++){
            ps[i] = per[i] * ps[i - 1];
        }
        for(int i=0;i<n;i++){
            pv[i] = ps[n - i - 1];
        }
       // for(int i=0;i<n;i++) cout << pv[i] << endl;
        for(int i=1;i<n;i++){
            pv[i] *= 1.0 - per[n - i];
        }
       // for(int i=0;i<n;i++) cout << pv[i] << endl;
        double p = 0;
        double tmp;
        int k = n;
        for(int i=0;i<n;i++){
            p += pv[i];
            tmp = p * (m - k + 1) + (1 - p) * (m - k + 1 + m + 1);
            res = min(res, tmp);
           // cout << i << ":" << m - k + 1 << endl;
           // cout << i << ":" << res << endl;
            k-=2;
        }
        res = min(res, (double)(m + 2));
        printf("Case #%d: %.6lf\n", _ca, res);
    }
    return 0;
}
