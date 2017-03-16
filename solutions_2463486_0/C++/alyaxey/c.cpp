#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define sz(X) ((int)(X).size())
#define pb push_back
#define mp make_pair
#define X first
#define all(X) (X).begin(),(X).end()
#define Y second
#define FOR(i, a, n) for(int i=(a), __ ## i=(n); i<__ ## i; i++)
#define REP(I,N) FOR(I,0,N)
#define PR(X) cout<<#X<<" = "<<(X)<<" "
#define PRL cout<<endl
#define PRV(X) {cout<<#X<<" = {";REP(__prv,sz(X)-1)cout<<(X)[__prv]<<",";if(sz(X))cout<<*(X).end();cout<<"}"<<endl;}

template<class T> ostream &operator<<(ostream &os, vector<T> &vec)
{
    os << '{';
    REP(i, sz(vec))
    {
        os << vec[i];
        if (i + 1 != sz(vec) )
            os << ',';
    }
    os << '}';
    return os;
}

template<class T1, class T2> ostream &operator<<(ostream &os, pair<T1, T2> &par)
{
    os << '(' << par.X << ',' << par.Y << ')';
    return os;
}

typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : abs(x);
}

int sqr(int x)
{
    return x * x;
}

std::string numSqr(const std::string & x)
{
    std::string ans(sz(x) * 2 - 1, '0');
    REP(i, sz(x))
        REP(j, sz(x))
            ans[i + j] += (x[i] - '0') * (x[j] - '0');
    return ans;
}

vector<string> nums;

void dec(string & s)
{
    int i = sz(s) - 1;
    while (i && s[i] == '0')
        s[i--] = '9';
    --s[i];
    if (sz(s) > 1 && s[0] == '0')
        s.erase(0, 1);
}

bool numLess(const string & a, const string & b)
{
    return sz(a) != sz(b) ? sz(a) < sz(b) : a < b;
}

int countLE(const string & s)
{
    return upper_bound(all(nums), s, numLess) - nums.begin();
}

void solve(int test)
{
    string a, b;
    cin >> a >> b;
    dec(a);
    int ans = countLE(b) - countLE(a);
    cout << "Case #" << test << ": " << ans << endl;
}

bool addNum(const std::string & s)
{
    int sum = 0;
    REP(i, sz(s))
        sum += sqr(s[i] - '0');
    if (sum >= 10)
        return false;
    nums.pb(numSqr(s));
    return true;
}

void generateNums(const string & s)
{
    if (sz(s) > 5)
        return;
    string rs = s;
    reverse(all(rs));
    addNum(s + rs.substr(1));
    if (!addNum(s + rs))
        return;
    REP(i, 3)
        generateNums(string(s + char(i + '0')));
}

void pre()
{
    FOR(i, 1, 10)
        generateNums(string(1, char(i + '0')));
    sort(all(nums), numLess);
}

int main()
{
    if (!freopen("1.in", "r", stdin))
    {
        cerr << "No input file" << endl;
        return 1;
    }
    if (!freopen("1.out", "w", stdout))
    {
        cerr << "Error creating output file" << endl;
        return 1;
    }
    ios::sync_with_stdio(false);
    pre();
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);
    for (int i = 1; i <= n; ++i)
    {
        solve(i);
    }
    return 0;
}
