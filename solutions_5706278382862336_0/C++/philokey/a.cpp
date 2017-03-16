#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
const int MAXN = 30005;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
long long pow2[42];
bool judge(long long q) {
    while (q) {
        if (q%2) {
            q>>=1;
        } else {
            return 0;
        }
    }
    return 1;
}
int main() {
    freopen("/home/philokey/code/codejam/in.txt","r",stdin);
    int cas;
    long long p,q;
    long long g;
    scanf("%d",&cas);
    for (int ca = 1; ca<=cas; ++ca) {
        scanf("%lld/%lld",&p,&q);
        g = __gcd(p,q);
        p /= g;
        q /= g;
        bool flag = 0;
        long long pow2 = 1;
        int gen = 1;
        //cout<<p<<" "<<q<<endl;
        while (pow2 <= p) {
            if (pow2 == p) {
                flag = 1;
                break;
            } else {
                pow2*=2;
                ++gen;
            }
        }
        if (flag) {
            flag = judge(p);
        }
        printf("Case #%d: ",ca);
        if (!flag) {
            printf("impossible\n");
        } else {
            printf("%d\n",gen);
        }
    }
    return 0;
}
