#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <functional>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef vector<vi> vvi;
typedef priority_queue<pii, vp, greater<pii> > pq;

const int N = 55;
const int M = 10000;
const int K = 200010;
const int LIT = 2500;
const int INF = 1 << 30;
const int ABS(int x) {while(x < 0) x = -x; return x;}

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

const double cl = 5.0;
int n;
struct node
{
    double d, s, p;
    node() {d = s = p = 0;}
    node(double dd, double ss, double pp) {d = dd, s = ss, p = pp;}
}c[N];

void init()
{
    for(int i = 0; i < n; i++)
    {
        char ss[3];
        double s, p;
        scanf("%ss", &ss);
        scanf("%lf %lf", &s, &p);
        double d = ss[0] == 'L' ? 0.0 : 1.0;
        c[i] = node(d, s, p);
    }
}

double cal(int x, int y)
{
    double dist = c[y].p - c[x].p - cl;
    double dv = c[x].s - c[y].s;
    double t = dist / dv;
    return t;
}

void solve(int tcase)
{
    double res = 0.0;
    double inf = 1e100;
    int cnt = 0;
    
    while(1)
    {
        double Max = inf;
        int pi = -1, pj = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                if(c[i].d != c[j].d) continue;
                if(c[i].p > c[j].p) continue;
                if(c[i].s < c[j].s) continue;
                
                double t = cal(i, j);
                if(t < Max) Max = t, pi = i, pj = j;
            }
        }
        
        //cout<<Max<<" "<<pi<<" "<<pj<<endl;
        if(pi == -1 || cnt > M)
        {
            printf("Case #%d: Possible\n", tcase);
            return ;
        }
        
        double p[N] = {0}, t[N] = {0};
        for(int i = 0; i < n; i++)
        {
            p[i] = c[i].p + Max * c[i].s;    
        }
        
        bool fg = 1;
        for(int i = 0; i < n; i++)
        {
            if(i == pi) continue;
            if(c[i].d == c[pi].d) continue;
            if(p[i] + cl <= p[pi]) continue;
            if(p[pi] + cl <= p[i]) continue;
            fg = 0;
        }
        if(!fg) 
        {
            printf("Case #%d: %.6lf\n", tcase, res + Max);
            return ;
        }
        for(int i = 0; i < n; i++)
        {
            c[i].p = p[i];
        }
        c[pi].d = 1.0 - c[pi].d;
        res += Max;
        
        cnt++;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int T, tcase = 1;
    cin>>T;
    
    while(cin>>n)
    {
        init();
        solve(tcase++);
    }
    
    //while(1);
}
