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

int n, vis[N];
vp v;

void init()
{
    memset(vis, 0, sizeof(vis));
    v = vp(n);
    for(int i = 0;i < n; i++)
    {
        scanf("%d %d", &v[i].fst, &v[i].snd);
    }
}

void solve(int tcase)
{
    int res = 0, cnt = 0;
    
    while(cnt < 2 * n)
    {
        int p = -1, Min = INF;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 2) continue;   
            if(v[i].snd > cnt) continue;
            if(v[i].snd < Min) Min = v[i].snd, p = i;
        }
        if(p != -1)
        {
            cnt += 2 - vis[p];
            vis[p] = 2;
            res++;
            continue;    
        }
        int Max = -1;
        for(int i = 0; i < n; i++)
        {
            if(vis[i]) continue;
            if(v[i].fst > cnt) continue;
            if(v[i].snd > Max) Max = v[i].snd, p = i;    
        }
        if(p == -1)
        {
             printf("Case #%d: Too Bad\n", tcase);
             return ;    
        }
        res++;
        vis[p] = 1;
        cnt += 1;
    }
    printf("Case #%d: %d\n", tcase, res);
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
