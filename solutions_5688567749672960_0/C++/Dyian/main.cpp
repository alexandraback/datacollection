
#include <string.h>

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int m[1000005];
struct node{
    int num, sec;
    node(int a, int b){num = a, sec = b;}
};
int Reverse(int x) {
    int y = 0, t;
    while (x) {
        t = x%10;
        y = y*10 +t;
        x/=10;
    }
    return y;
}
int main() {


    /*
    int R,C,N;
    int T,c = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &R,&C, &N);
        if (R > C) swap(R, C);
        printf("Case #%d: ", ++c);
        int a = (R*C + 1)>>1;
        if (N <= a) printf("0\n");
        else {
            if (R == 1) {
                if (C&1) printf("%d\n", (N - a) <<1);
                else  printf("%d\n", ((N - a) <<1) - 1);
            }
            else {
                int t = R*C;
                int m = (((R + C) << 1) - 4)>>1;
                if (t&1) {
                    N -= a;
                    int tmp1 = 0;
                    if (N <= m) tmp1 = 3*N;
                    else tmp1 = 3*m + (N - m)*4;
                    int tmp2 = 0;
                    ++N;
                    if (N <= 4) tmp2 = N*2;
                    else {
                        if (N <= m) tmp2 = (N - 4)*3 + 8;
                        else {
                            tmp2 = 8 + (m - 4)*3;
                            tmp2 += (N - m) * 4;
                        }
                    }
                    printf("%d\n", min(tmp1, tmp2));
                }
                else {
                    N -= a;
                    if (N <= 2) printf("%d\n", N << 1);
                    else {
                        if (N <= m) printf("%d\n", 4 + (N - 2)*3);
                        else {
                            printf("%d\n", 4 + (m - 2)*3 + (N - m)*4);
                        }
                    }
                }
            }
        }
    }
    return 0;
    */
    /*
    long long d = 26;
    long long e = 10;
    for (int i = 3; i <=14; ++i)
    {
        d = d + 26 + e*9;
        e=e*10;
        printf("%I64d\n", d);
    }
    return 0;
    */
    freopen("A-small-attempt0 (1).in", "r", stdin);
    freopen("A-small-attempt0 (1).out", "w", stdout);
memset(m, -1, sizeof(m));
    queue<node> q;
    for (int i = 1; i <= 20; ++i) {
        m[i] = i;
        q.push(node(i, i));
    }
    while (!q.empty()) {
        node t = q.front(); q.pop();
        int s = t.sec, n = t.num;
        int tmp = Reverse(n);
        if (tmp <= 1000000) {
            if (m[tmp] == -1 || s + 1 < m[tmp] ) {
                m[tmp] = s + 1;
                q.push(node(tmp, s + 1));
            }
        }
        ++n;
        if (n <= 1000000) {
            if (m[n] == -1 || s + 1 < m[n]) {
                m[n] = s + 1;
                q.push(node(n, s + 1));
            }
        }
    }
        int T, c = 0;
    scanf("%d", &T);
    while (T--) {
        int  N;
        scanf("%d", &N);
        printf("Case #%d: ", ++c);
        printf("%d\n", m[N]);
    /*
        if (n <= 11) {
            printf("%d\n", n - 1);
            continue;
        }
        int cnt = 0;
        long long t = n;
        while (t) {
            ++cnt;
            t >>= 1;
        }
        t = n >> (cnt - 1);
        int ans = 8 + (cnt - 2) * 26 + (t - 1) * 3 + 1;
        long long b = 1;
        while (b*10 < n) b = b * 10;
        if (t == 1) ans += n - b;
        else {
            b = b * t + 1;
            if (n < b) {
                //ans +=
            }
        }
*/
        //if
    }
    return 0;

    //freopen("B-small-attempt1.in", "r", stdin);
    //freopen("B-small-attempt1.out", "w", stdout);
    /*
    int T, B, N, c = 0, ma;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &B, &N);
        ma = 0;
        for (int i = 0; i < B; ++i) {
            scanf("%d", &m[i]);
            if (m[i] > ma) ma = m[i];
        }
        long long l = 0, r = N*(long long)ma;
        long long mid, sum;
        while (l <= r) {
            mid = (l + r) >> 1, sum = 0;
            for (int i = 0; i < B; ++i)
                sum += mid/m[i];
            if (sum > N - 1)r = mid - 1;
            else if (sum < N - 1) l = mid + 1;
            else {
                int j = 0, mi = 99999999, idx;
                while (j < B) {
                    if (mid % m[j] < mi) mi = mid % m[j], idx = j;
                    ++j;
                }
                printf("Case #%d: %d\n", ++c, idx + 1);
                break;
            }
        }
        if (sum < N - 1) {
            int tmp = N - sum, i = 0, idx,mi = 99999999;
            while (tmp) {
                while (mid % m[i] + 1 != m[i]) ++i;
                if (mid % m[i] <= mi) mi = mid % m[i], idx = i;
                --tmp, ++i;
            }
            printf("Case #%d: %d\n", ++c, idx+1);
        }
        else if (sum > N - 1){
            sum = 0;
            for (int i = 0; i < B; ++i)
            sum += r/m[i];
            int t = N - (int)sum, i = 0, idx;
            int mi = 99999999;
            for (int j = 0; j < t; ++j) {
                while (r % m[i] + 1 != m[i]) ++i;
                if (r % m[i] <= mi) mi = r % m[i], idx = i;
                ++i;
            }
            printf("Case #%d: %d\n", ++c, idx+1);
        }
    }
    return 0;
    */
}
/*
int a[1005];
int main() {

    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, N,c = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%d", &a[i]);
        --N;
        int sum1 = 0, i = 0;
        do {
            ++i;
            if (a[i] < a[i - 1]) sum1 += a[i - 1] - a[i];
        } while(i < N);
        int sum2 = 0; i = 0;
        int Max = 0;
        do {
            ++i;
            if (a[i] < a[i - 1])
                if(a[i-1]- a[i]>Max)
                    Max = a[i-1]- a[i];
        } while(i < N);
        i= 0;
        do {
            sum2 += min(a[i], Max);
        } while(++i < N);
        printf("Case #%d: %d %d\n", ++c,sum1, sum2);
    }
    return 0;
}
*/
/*
int main() {
    freopen("D-small-attempt2.in", "r", stdin);
    freopen("D-small-attempt2.out", "w", stdout);
    int T, X, R, C, c = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &X, &R, &C);
        if (X == 1) {
            printf("Case #%d: GABRIEL\n", ++c);
            continue;
        }
        if (X == 2) {
            if ((R*C)&1) {
                printf("Case #%d: RICHARD\n", ++c);
            }
            else printf("Case #%d: GABRIEL\n", ++c);
            continue;
        }
        if (X == 3) {
            if (R > C) swap(R, C);
            if ((R == 2 && C == 3) || (R == 3 && C == 4) || ( R == 3 && C == 3))
                printf("Case #%d: GABRIEL\n", ++c);
            else printf("Case #%d: RICHARD\n", ++c);
            continue;
        }
        if (R > C) swap(R, C);
        if ((R == 3 || R == 4) && C == 4)
            printf("Case #%d: GABRIEL\n", ++c);
        else
            printf("Case #%d: RICHARD\n", ++c);
    }
    return 0;
}
*/
/*
int cnt[1005];
int T, c = 0, w, m, n;
int piece[1005];
int main(){
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.out", "w", stdout);
    scanf("%d", &T);
    int a, b;
    while (T--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        m = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &w);
            ++cnt[w];
            if (w > m) m = w;
        }
        memset(piece, 0, sizeof(int) * (m + 1));
        for (int i = m; i > 1; --i) {
            if (cnt[i] == 0) continue;
            double i_d = i * 1.0;
            for (int j = i - 1; j > 1; --j) {
                piece[j] += cnt[i] * (ceil(i_d/j) - 1);
            }
        }
        for (int i = 2; i < m; ++i)
            if (piece[i] + i < m) m = piece[i] + i;
            printf("Case #%d: %d\n", ++c, m);
    }
    return 0;
}
*/
/*#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int MaxN = 5010;
const double EInf = 1e50;

struct tNode {
    double x, y;
    tNode(){}
};

bool Use[MaxN];
int N, W, R, Vs, Vt;
double F[MaxN];
tNode A[MaxN];

double sqr(double x) {return (x * x); }

double Dis_vs(int i) {return sqr(min(A[i].x - 1, W - A[i].y)); }

double Dis_vt(int i) {return sqr(min(A[i].y - 1, R - A[i].x)); }

double Dis(int u, int v) {return (sqr(A[u].x - A[v].x) + sqr(A[u].y - A[v].y)) / 4.0; }

int main() {
    freopen("a.txt", "r", stdin);
  //  freopen("dis.out", "w", stdout);
  while(~scanf("%d%d%d",&N,&R,&W)){
    Vs=N+1;Vt=N+2;
    for(int i=1;i<=N;i++)scanf("%lf%lf",&A[i].x,&A[i].y);
    for(int i=1;i<=Vt;i++){F[i]=EInf;Use[i]=false;}F[Vs]=0;

    for(int i=1;i<=Vt;i++){
        int u=0;
        double Min=EInf;
        for (int j=1;j<=Vt;j++){
            if ((!Use[j])&&(Min>F[j])){
                Min = F[j];
                u = j;
            }
        }
        if (u==0)break;
        Use[u]=true;
        if(u==Vt)break;
        if(u==Vs){
            for(int j=1;j<=N;j++)if(Dis_vs(j)<=F[j])F[j]=Dis_vs(j);
        }else{
            for(int j=1;j<=N;j++){
                F[j] = min(F[j], max(F[u], Dis(u, j)));
            }
            F[Vt] = min(F[Vt], max(F[u], Dis_vt(u)));
        }
    }
    printf("%.2f\n", sqrt(F[Vt]));}
    return 0;
}*/
/*double dp[5005][5005];
int main() {
    int n, k;
    dp[1][1] = 1;
    for (int i = 2; i <= 5000; ++i) {
        dp[i][1] = dp[i - 1][1] + 1.0/i;
    }
    for (int i = 2; i <= 4999; ++i) {
        dp[i][i] = dp[i - 1][i - 1] * 1.0/i;
        for (int j = i + 1; j <= 5000; ++j) {
            dp[j][i] = dp[j - 1][i - 1]/j + dp[j - 1][i];
        }
    }
    while (scanf("%d%d", &n, &k) != EOF) {
        if(k == 1) {
            printf("%.4f\n", 1.0/n);
        }
        else {
            double ans = 0;
            while (k) {
                ans += (dp[n][k] - dp[n - 1][k]);
                --k;
            }
            printf("%.4f\n", ans);
        }
    }
    return 0;
}*/
/*#include <stdio.h>
#include <string.h>
char mt[52][52];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int flag[52][52], cnt;
int dir[125];
void go(const int x, const int y) {
    flag[x][y] = 1, ++cnt;
    int xx, yy;
    for (int i = 0; i < 4; ++i) {
        if (dir[mt[x][y]] & (1 << i)) {
            xx = x + dx[i];
            yy = y + dy[i];
            if (mt[xx][yy] != '#' && flag[xx][yy] == -1) go(xx, yy);
        }
    }
}
void go2(const int x, const int y) {
    flag[x][y] = 2, --cnt;
    int xx, yy;
    for (int i = 0; i < 4; ++i) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (flag[xx][yy] == 1 && (dir[mt[xx][yy]] & (1 << (3 - i)))) go2(xx, yy);
    }
}
int main(){
    dir['.'] = 1, dir['+'] = 15, dir['-'] = 6, dir['|'] = 9;
    //freopen("a.txt", "r", stdin);
    int r, c, rr, cc;
    int sx, sy, tx, ty;
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; ++i) {
        scanf("%s", mt[i] + 1);
        for (int j = 1; j <= c; ++j)
            if (mt[i][j] == 'S') sx = i, sy = j;
            else if (mt[i][j] == 'T') tx = i, ty = j;
    }
    rr = r + 1, cc = c + 1;
    for (int i = 0; i <= cc; ++i)
        mt[0][i] = mt[rr][i] = '#';
    for (int i = 1; i <= r; ++i)
        mt[i][0] = mt[i][cc] = '#';
    memset(flag, -1, sizeof(flag));
    mt[sx][sy] = '+', mt[tx][ty] = '+';
    cnt = 0;
    go(sx, sy);
    if (flag[tx][ty] == -1) {
        puts("I'm stuck!");
    }
    else {
        go2(tx, ty);
        printf("%d\n", cnt);
    }
    return 0;
}*/
/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <list>
using namespace std;
long long f[2000][3][2];
/// f[seq_k to place][0: to place 0 , 1: ethier 0 or 1, 2 : must be 1][3 is placed ?1 : 0]
int dp(int n, int p1, int p3)
{
    long long &now = f[n][p1][p3];
    if (now != -1)
    return now;
    if (n == 0)
    {
        if (p1 == 2 && p3 == 1)
        {
            now = 1;
        }else
        {
            now = 0;
        }
            return now;
    }
    now = 0;
    if (p1 == 0)
    {
        now += dp(n-1, 1, p3); /// go 0
    }else if (p1 == 1)
    {
        now += dp(n-1, 1, p3); /// go 0now += dp(n-1, 2, p3); // go 1
    }else /// p1 == 2
    {
        now += dp(n-1, 2, p3); /// go 1
    }
    if (p3 == 0)
    {
        now += dp(n-1, p1, p3); /// go 2;
        now += dp(n-1, p1, 1); /// go 3;
    }else
    {
        now += dp(n-1, p1, 1); /// go 3;
    }
        now %= 1000000007;
    }
int main()
{
    int n;
    cin >> n;
    memset(f, -1, sizeof(f));
    int ans = dp(n - 1, 0, 0); /// seq[n] is 2
    cout << ans << endl;
    return 0;
}*/
