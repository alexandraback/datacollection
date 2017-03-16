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

int a, b, c , k;
map<pair<int,int> , int> umap[3];
set<pair<pair<int,int> , int> > uset;
bool valid(int aa ,int bb ,int cc)
{
    if(uset.count(MP(MP(aa,bb), cc)))
        return false;
    if(umap[0][MP(aa,bb)] >= k || umap[1][MP(aa,cc)] >= k || umap[2][MP(bb,cc)] >= k)
        return false;
    return true;
}
void solve()
{
    uset.clear();
    FOR(i,0,3)
    umap[i].clear();
    vector<pair<pair<int,int>, int > > res;
    while(true)
    {
        bool flag = false;
        int x,y,z;
        FOR(i,0,a)
        FOR(j,0,b)
        FOR(k,0,c)
        {
            if(valid(i,j,k))
            {
                x = i;
                y = j;
                z = k;
                flag = true;
                break;
            }
        }
        if(!flag)
            break;
        uset.insert(MP(MP(x,y),z));
        umap[0][MP(x,y)]++;
        umap[1][MP(x,z)]++;
        umap[2][MP(y,z)]++;
        
        res.PB(MP(MP(x,y),z));
    }
    cout << res.size() << endl;
    FOR(i,0,res.size())
    cout << res[i].F.F + 1 << " " << res[i].F.S + 1 <<  " " << res[i].S + 1 << endl;
}
int main(){
    int T;
    cin >> T;
    FOR(z,0,T)
    {
        cin >> a >> b >> c >> k;
        cout << "Case #" << z + 1 << ": ";
        solve();
    }
    return 0;
}