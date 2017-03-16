#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 100000000;
int T, cas;
long long n;
int q[maxn + 100], d[maxn+100], s[10000], a[10000];

long long re(long long x){
    int cnt = 0; long long ret = 0;
    while(x){
            a[cnt++] = x % 10;
            x /= 10;
    }
    long long f = 1;
    for (int i = cnt-1; i >= 0; i--, f *= 10){
            ret += a[i] * f;
    }
    return ret;
}
long long cal(long long n){
    if (n <= 19) return n;
    long long tmp = n; int len = 0;
    while(tmp){
        s[len++] = tmp % 10;
        tmp /= 10;
    }
    long long f = 1, nx = 0, mo = 1;
    for (int i = 0; i < len; i++, f *= 10){
        tmp = s[i];
        if (i < (len+1)/2){
            tmp = 0; mo *= 10;
        }
        nx = nx + tmp * f;
    }
    nx ++;
    f /= 10; mo /= 10;
    if (nx - f == 1){
        nx = (nx / mo - 1) * mo + 1;
    }
    long long ret = n - nx;
    tmp = re(nx);
    if (tmp < nx) nx = tmp;
    return min(n, ret + cal(nx) + 1);
}
int main()
{
    //freopen("A-large (1).in", "r", stdin);
    //freopen("la.out", "w", stdout);
    //for (int i = 1; i <= 1000000; i++) printf("%lld\n", cal(i));
    cin >> T;
    while(T--){
            cin >> n;
            ++cas;
            cout << "Case #" << cas << ": " << cal(n) << endl;
    }
    return 0;
}
