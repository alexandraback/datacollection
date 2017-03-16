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
#define Y second
#define all(X) (X).begin(),(X).end()
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

template<class T> T sqr(T x)
{
    return x * x;
}

char a[10][10];

bool win(char her)
{
    vector<PII> lines;
    REP(i, 4)
        REP(j, 4)
            lines.pb(mp(i, j));
    REP(j, 4)
        REP(i, 4)
            lines.pb(mp(i, j));
    REP(i, 4)
        lines.pb(mp(i, i));
    REP(i, 4)
        lines.pb(mp(4 - 1 - i, i));

    bool result;
    REP(i, sz(lines) / 4)
    {
        result = true;
        REP(j, 4)
        {
            const PII & p = lines[i * 4 + j];
            char c = a[p.X][p.Y];
            result &= c == her || c == 'T';
        }
        if (result)
            return true;
    }
    return false;
}

void solve(int test)
{
    REP(i, 4)
        cin >> a[i];
    bool boardFull = true;
    REP(i, 4)
        REP(j,4)
            if (a[i][j] == '.')
                boardFull = false;

    cout << "Case #" << test << ": ";
    cout << fixed;
    cout << setprecision(8);
    cout
            << (win('X') ? "X won" : win('O') ? "O won" :
                boardFull ? "Draw" : "Game has not completed");
    cout << endl;
}

void pre()
{
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
