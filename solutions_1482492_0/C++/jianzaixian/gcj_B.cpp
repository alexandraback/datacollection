#include <iostream>
#include <cstdio>
#include <cstring>

#include <map>
#include"cmath"
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <functional>
#include <set>
/**以上常用头文件**/
int N = 100010;
 int M = 55;
 int K = 200010;
 int LIT = 2500;
 int INF = 1 << 30;
 int ABS(int x) {while(x < 0) x = -x; return x;}

using namespace std;
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
/**常用typedef**/
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef vector<pdd> vp;
typedef vector<vi> vvi;
typedef priority_queue<pii, vp, greater<pii> > pq;

double d;
int n, a;

vp v;

void init()
{
    v = vp(n);
    for(int i = 0; i < n; i++)
    {
        cin>>v[i].fst>>v[i].snd;
    }
}

void solve(int tcase)
{
    printf("Case #%d:\n", tcase);

    for(int i = 0; i < a; i++)
    {
        double s;
        cin>>s;

        double res = 2 * d / s;
        res = sqrt(res);

        if(n == 1)
        {
             printf("%.10lf\n", res);
             continue;
        }
        else if(n == 2)
        {
            double ds = v[1].snd - v[0].snd;
            double dt = v[1].fst - v[0].fst;
            double dv = ds / dt;

            double tmp = 2 * dv + sqrt(4 * dv * dv + 8 * s * v[0].snd);
            tmp /= (2 * s);

            if(tmp > res)
            {
                printf("%.10lf\n", res);
                continue;
            }

            double ss = v[0].snd + dv * tmp;
            double tt = (d - ss) / dv;
            res = tmp + tt;
            printf("%.10lf\n", res);
        }
    }
}

int main()
{
    freopen("a.txt", "w", stdout);

    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
    	scanf("%lf%d%d",&d,&n,&a);
    	init();
    	solve(i+1);
    }

}
