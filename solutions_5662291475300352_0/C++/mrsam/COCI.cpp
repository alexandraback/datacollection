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

ifstream fin ("C-small-1-attempt3.in");
ofstream fout ("out.out");

typedef long long ll;
int n, t;
double d[3], h[3], m[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    fin >> t;

    for(int i = 1 ; i <= t ; i++)
    {
        fin >> n;
        
        for(int j = 0 ; j < n ; j++)
            fin >> d[j] >> h[j] >> m[j];    
       
        if(n == 1)
        {
            fout << "Case #" << i << ": " << 0 << endl; 
            continue;  
        }  
        
        if(d[1] < d[0])
        {
            swap(d[0], d[1]);
            swap(h[0], h[1]);
            swap(m[0], m[1]);    
        } 
        
        if(d[0] == d[1] && m[0] < m[1]) 
        {
            swap(d[0], d[1]);
            swap(h[0], h[1]);
            swap(m[0], m[1]);    
        } 
        
        double t0 = (360.0 - d[0]) / 360.0 * m[0];
        double t1 = m[1] * (720.0 - d[1]) / 360.0;
        
        fout << "Case #" << i << ": " << (t0 > t1) << endl; 
    }

    return 0;
}
