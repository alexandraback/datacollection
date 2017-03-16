#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

#define esp 1e-10

long long R,T;
long long ans;
long long a;
long long l, r, m;

bool check(long long m) {
    double w,tmp;
    long long c;
    
    c = a+m+m-2;
    w = log(c);
    w += log(m);
    tmp = log(T);
    if (w-esp > tmp) return false;
    c *= m;
    if (c > T) return false;
    return true;
}
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    
    int cases, k;
    
    scanf("%d",&cases);
    for (k = 1; k <= cases; ++k) {
        cin >> R >> T;
        ans = 0;
        a = R+R+1;
        
        l = 1; r = 1000000000;
        while (l+1 < r) {
            m = (l+r)/2;
            if (m == 50) {
                int nn;
                ++nn;
            }
            if (check(m)) l = m;
            else r = m;
        }
        if (check(r)) ans = r;
        else ans = l;
        
        printf("Case #%d: ",k);
        cout << ans << endl;
    }
    
    
    return 0;
}
