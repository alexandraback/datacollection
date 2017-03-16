#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

typedef double real;
typedef long long int64;

#define Eo(x) { cerr << #x << " = " << x << endl; }

#define eps 1e-9
#define maxn (1 << 8)

int s[maxn];

real m[maxn];

int main() {
    int t = 1, tc;
    for(scanf("%d", &tc); t <= tc; ++t) {
        printf("Case #%d:", t);

        int n, sum = 0;;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", s+i);

        for(int i = 0; i < n; i++) sum += s[i];

        for(int i = 0; i < n; i++) {
            real l = 0, r = 1;
            while(r-l > eps) {
                real cur = (l+r) * 0.5;
                real score = s[i] + sum * cur;
                real rem = 1 - cur;

                int j;
                for(j = 0; j < n; j++) if(i != j && s[j] < score) {
                    real nx = (score - s[j] + eps) / sum;
                    if(nx <= rem)
                        rem -= nx;
                    else
                        break;
                }
                if(j < n) r = cur;
                else l = cur;
            }
            printf(" %.6lf", r*100);
        }
        printf("\n");
    }
    return 0;
}
