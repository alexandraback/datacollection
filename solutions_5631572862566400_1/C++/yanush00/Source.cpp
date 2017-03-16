#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:167777216")
#include <cmath>
#include <math.h>
#include <complex>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <ccomplex>

#include <unordered_map> 
#include <stack> 
#include <time.h> 
#include <fstream> 
#include <queue> 
using namespace std;

#define pb push_back  
#define mp(a,b) make_pair(a,b)   
#define F first  
#define S second  

#define all(x) x.begin(), x.end() 
#define sqr(x) ((x)*(x)) 
#define eps 1e-8 
#define inf (int)(1e9+7) 
#define infll (ll)(1e18+3) 
#define sz(x) ((int)x.size()) 
#define M_PI     3.14159265358979323846  
#define PI       3.14159265358979323846   
typedef long long ll;
typedef  unsigned long long ull;
typedef  long double ld;
typedef vector < ll > vll;
typedef vector < int > vi;
typedef pair < ll, ll > pll;
typedef pair < int, int > pii;
typedef int huint;
typedef complex<double> base;
using polynome = vector<complex<double>>;
 
int g[3000];
vector<vector<int>> p;

int n;
int ans;
int kl;
int f[2000];
int h[2000];
void dfs(int v,int l)
{
    h[v] = l;
    f[v] = kl;
    if (f[g[v]] == kl)
    {
        int s = l - h[g[v]] + 1;
        if (s > ans) ans = s;
        return;
    }
    if (f[g[v]] == 0)
    {
        dfs(g[v], l + 1);
    }

}
void find_cyclc()
{
    for (int i(0); i < n; i++)
        if (f[i] == 0) 
        {
            kl++;
            dfs(i, 1);
        }
}
int sum;
int mh;
int mv;
void find(int v, int h)
{
    if (h > mh)
    {
        mh = h;
        mv = v;
    }
    for (int i(0); i < p[v].size(); i++)
    {
        int to = p[v][i];
        if (f[to] != 0) continue;
        find(to, h + 1);
    }
}

void draw(int v)
{
    if (f[v] != 0) return;
    sum += 1;
    f[v] = 1;
    draw(g[v]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout); 

    int test;
    cin >> test; 
    for (int tt(1); tt <= test; tt++)
    {  
        cin >> n;
        p.clear();
        p.resize(n);
        for (int i(0); i < n; i++)
            f[i] = 0;
        ans = 1;
        kl = 1;
        for (int i(0); i < n; i++)
        {
            int x;
            cin >> x;
            x--;
            g[i] = x;
            p[x].pb(i);
        }
        find_cyclc();
        for (int i(0); i < n; i++)
            f[i] = 0;
        for (int i(0); i < n; i++)
        {
            int v = g[i];
            if (i == g[v])
            {
                f[i] = f[v] = 2;
            }
        }
        sum = 0;
        for (int i(0); i < n; i++)
        {
            if (f[i] != 2) continue;
            sum += 1;
            f[i] = 3; 
            mh = -1; mv = -1;
            find(i, 0);
            draw(mv);
        }
        if (sum > ans) ans = sum;

        cout << "Case #" << tt << ": " << ans; 
        cout << "\n"; 

    }

}