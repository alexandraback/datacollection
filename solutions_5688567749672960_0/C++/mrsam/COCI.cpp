#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <cctype>
#include <complex>
#include <numeric>

#define foreach(i, store) for(__typeof((store).begin()) i = (store).begin() ; i != (store).end() ; i++)
#define sqr(x) ((x)*(x))
#define comb2(x) ((x)*((x)-1)/2)
#define mod(x) ((x + MOD) % MOD)
#define All(store) store.begin(), store.end()
#define Unique(store) store.resize(unique(All(store)) - store.begin())
#define Assign(a, b, s, e) for(int i = s ; i <= e ; i++) b[i] = a[i];
#define IF(condition, x, y) ((condition) ? (x) : (y))
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define create make_pair
#define pii pair<int, int>
#define ppi pair< pii, int>
#define pic pair<int, char>
#define pll pair<ll, ll>
#define X first
#define Y second
#define Min(x, y) IF(x < y, x, y)
#define Max(x, y) IF(x > y, x, y)

using namespace std;

ifstream fin ("A-small-attempt0.in");
ofstream fout ("out.out");

typedef long long ll;
const int N = 1e6;
map<ll, int> dp;
int t;

inline ll rev(ll x)
{
    ll ret = 0;
    
    while(x)
    {
        ret = 10 * ret + (x % 10);
        x /= 10;    
    }   
    
    if(ret <= 1e10) return ret;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int cnt = 0;
    dp[1] = 1;
    queue<ll> q;
    q.push(1);
    
    while(cnt < N)
    {
        ll u = q.front();
        q.pop();
        
        if(u <= N) cnt++;
        
        if(u + 1 <= 1e10 && !dp[u+1])
        {
            dp[u+1] = dp[u]+1;
            q.push(u+1); 
        }      
        
        ll v = rev(u);
        
        if(v && !dp[v])
        {
            dp[v] = dp[u]+1;
            q.push(v); 
        }   
    }
    
    fin >> t;
    
    for(int i = 1 ; i <= t ; i++)
    {
        int n;
        fin >> n;
        fout << "Case #" << i << ": " << dp[n] << endl;      
    }

    return 0;
}
