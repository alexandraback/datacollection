#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define INF (~0U>>2)
#define eps (1e-6)
#define SZ(x) (int)((x).size())
#define foreach(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)

typedef long long LL;

int n,m;
double p[1000],multi[1000];

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int test; scanf("%d", &test);
    for (int caseN=1;caseN<=test;caseN++){
        printf("Case #%d: ",caseN);
        scanf("%d %d",&m,&n);
        for (int i=0;i<m;i++)
            scanf("%lf",&p[i]);
        multi[0]=p[0];
        for (int i=1;i<m;i++)
            multi[i]=multi[i-1]*p[i];
        double res=1e15;
        for (int i=m-1;i>=0;i--){
            double tmp=(m-1-i)+(((n-1-i)+1)*multi[i]+((n-1-i)+1+n+1)*(1-multi[i]));
            if (tmp<res) res=tmp;
        }
        if (res>1+n+1) res=1+n+1;
        printf("%.6lf\n",res);
    }
    return 0;
}

