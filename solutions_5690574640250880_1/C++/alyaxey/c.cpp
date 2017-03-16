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
        if (i + 1 != sz(vec))
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

bool a[55][55];
int r, c, m;
bool impossible;

void solveMinMax(){
    int d = r * c - m;
    impossible = false;
    if(c <= 2){
        impossible = c == 2 && ((d > 1 && d % 2 == 1) || d == 2);
        REP(i, r)
            REP(j, c)
                a[i][j] = d-- <= 0;
    }else{
        impossible = d == 2 || d == 3 || d == 5 || d == 7;
        if (!impossible)
        {
            if(d == 1){
                REP(i, r)
                    REP(j, c)
                    a[i][j] = d-- <= 0;
            }else{
                int cols = d > 3 * c ? c : 3;
                int rows = d / cols;
                bool edge = d % cols != 1;
                int last = edge ? d % cols : 2;
                REP(i, r)
                    REP(j, c)
                        a[i][j] = j >= cols || i > rows
                                || (i >= rows - 1
                                        && (i == rows - 1 ?
                                                (j == cols - 1 && !edge) :
                                                j >= last));
            }
        }
    }
}

void solve(int test)
{
    cin >> r >> c >> m;
    if (r >= c)
        solveMinMax();
    else
    {
        swap(r, c);
        solveMinMax();
        REP(i, r)
            REP(j, i)
                swap(a[i][j], a[j][i]);
        swap(r, c);
    }

    cout << "Case #" << test << ":";
    cout << fixed;
    cout << setprecision(8);
    cout << endl;
    if (impossible)
        cout << "Impossible" << endl;
    else
        REP(i, r)
        {
            REP(j, c)
                cout << (a[i][j] ? '*' : i == 0 && j == 0 ? 'c' : '.');
            cout << '\n';
        }
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
