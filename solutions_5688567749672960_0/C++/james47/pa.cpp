#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1000000;
int T, n, cas;
int q[maxn + 100], d[maxn+100], s[1000];

int re(int x){
    int cnt = 0, ret = 0;
    while(x){
            s[cnt++] = x % 10;
            x /= 10;
    }
    for (int i = cnt-1, f = 1; i >= 0; i--, f *= 10){
            ret += s[i] * f;
    }
    return ret;
}
void init(){
    int h = 0, t = 0;
    memset(d, 127, sizeof(d));
    int inf = d[0];
    d[1] = 1; q[t++] = 1;
    while(h < t){
            int v = q[h++], u;
            u = v + 1;
            if (d[u] > d[v] + 1){
                d[u] = d[v] + 1;
                if (u <= maxn) q[t++] = u;
            }
            u = re(v);
            if (d[u] > d[v] + 1){
                d[u] = d[v] + 1;
                if (u <= maxn) q[t++] = u;
            }
    }
}
int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    init();
    scanf("%d", &T);
    while(T--){
            scanf("%d", &n);
            printf("Case #%d: %d\n", ++cas, d[n]);
    }
    return 0;
}
