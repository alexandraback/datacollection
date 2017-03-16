#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ostream>
#include <queue>
#include <cmath>
#include <climits>
#include <utility>
#include <fstream>
#include <memory>
#include <sstream>
#include <set>
#include <iterator>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
#define FOR(a, b, n) for(int (a) = (b); (a) < (n); ++(a))
#define FORE(a, b, n) for(int (a) = (b); (a) <= (n); ++(a))
#define ITE(a, v) for(auto (a) = v.begin(); (a) != v.end(); ++(a))
#define LL long long
#define ALL(v) v.begin(),v.end()
#define ZERO(v) memset(v, 0, sizeof v)
#define NEG(v)  memset(v, -1, sizeof v)
#define F first
#define S second
#define LD double
#define pw(x) (1LL << (x))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define PI 3.141592653589793
#define PII pair<LL, LL>
#define INF 0x3f3f3f3f
#define FUL(x) memset(x, 0x3f, sizeof(x));
#define debug(args...) {cerr << #args << " = "; errDebug(args); cerr << endl;}
void errDebug() {}
template<typename T, typename... Args>
void errDebug(T a, Args... args) {
    cerr << a << ' ';
    errDebug(args...);
}

LL b, k;
int res[55][55];
void solve()
{
    LL sum = 1;
    FOR(i,0,b - 2)
    {
        sum *= 2;
        if(sum >= k)
            break;
    }
    if(sum < k)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << "POSSIBLE" << endl;

    ZERO(res);
    res[0][b - 1] = 1;
    k--;
    sum = 1;
    int i;
    for(i = 1; i < b - 1; i++)
    {
        if(sum > k)
        {
            break;
        }
        else
        {
            FOR(j,0,i)
            res[j][i] = 1;
            res[i][b - 1] = 1;
            k -= sum;
            sum *= 2;
        }
    }
    if(k == 0)
    {
        FOR(i,0,b)
        {
            FOR(j,0,b)
            cout << res[i][j];
            cout << endl;
        }
        return;
    }
    res[i][b - 1] = 1;
    vector<int> bit;
    for(int j = 0; j < i; j++)
    {
        if(k & (1LL << j))
            bit.PB(j + 1);
    }
    FOR(j,0,bit.size())
    {
        res[bit[j]][i] = 1;
    }
    FOR(i,0,b)
    {
        FOR(j,0,b)
        cout << res[i][j];
        cout << endl;
    }
    
    
}
int main(){
    int T;
    cin >> T;
    FOR(z,0,T)
    {
        cin >> b >> k;
        cout << "Case #" << z + 1 << ": ";
        solve();
    }
    return 0;
}