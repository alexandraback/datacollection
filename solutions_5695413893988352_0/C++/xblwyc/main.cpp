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

string s1, s2;
string ss1, ss2;
int res ;
void check()
{
    int val1 = stoi(s1);
    int val2 = stoi(s2);
    if(abs(val1 - val2) < res)
    {
        res = abs(val1 - val2);
        ss1 = s1;
        ss2 = s2;
    }
    else if(abs(val1 - val2) == res)
    {
        if(s1 < ss1)
        {
            ss1 = s1;
            ss2 = s2;
        }
        else if(s1 == ss1)
            ss2 = min(ss2, s2);
    }
}
int ten(int exp)
{
    int res = 1;
    FOR(i,0,exp)
    res *= 10;
    return res;
}
void solve()
{
    int cnt1 = 0;
    int cnt2 = 0;
    vector<int> a1;
    vector<int> a2;
    FOR(i,0,s1.size())
    if(s1[i] == '?')
        a1.PB(i);
    FOR(i,0,s2.size())
    if(s2[i] == '?')
        a2.PB(i);
    res = INF;
    ss1 = ss2 = "";
    FOR(i,0,ten(a1.size()))
    FOR(j,0,ten(a2.size()))
    {
        int ii = i;
        int jj = j;
        for(int p = 0; p < a1.size(); p++)
        {
            s1[a1[p]] = ii % 10 + '0';
            ii /= 10;
        }
        for(int q = 0; q < a2.size(); q++)
        {
            s2[a2[q]] = jj % 10 + '0';
            jj /= 10;
        }
        check();

    }
    cout << ss1 << " " << ss2 << endl;
}
int main(){
    int T;
    cin >> T;
    FOR(h,0,T)
    {
        cin >> s1 >> s2;
        cout << "Case #" << h + 1 << ": ";
        solve();
    }
    return 0;
}