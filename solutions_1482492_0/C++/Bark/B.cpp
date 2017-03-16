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
typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef vector<pdd> vp;
typedef vector<vi> vvi;
typedef priority_queue<pii, vp, greater<pii> > pq;

const int N = 100010;
const int M = 55;
const int K = 200010;
const int LIT = 2500;
const int INF = 1 << 30;
const int ABS(int x) {while(x < 0) x = -x; return x;}

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

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
            
            //cout<<tmp<<endl;
            if(tmp > res)
            {
                printf("%.10lf\n", res);   
                continue;
            }
            
            double ss = v[0].snd + dv * tmp;
            double tt = (d - ss) / dv;
            
            //cout<<tt<<endl;
            
            res = tmp + tt;
            printf("%.10lf\n", res);  
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int T, tcase = 1;
    cin>>T;
    
    while(T-- && cin>>d>>n>>a)
    {
        init();
        solve(tcase++);
    }
    
    //while(1);
}
