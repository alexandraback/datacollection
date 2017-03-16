#define ENABLE_MAIN 1
#if ENABLE_MAIN


#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <list>
#include <queue>
#include <numeric>
#include <iomanip>
#include <fstream>


using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<ll, ll> PLL;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;

const ll oo = 1LL << 60;
const int kNumMoves = 4;
const int kMoves[kNumMoves][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

#define FOR(i, n) for (int i = 0; i < int(n); ++i)
#define FORI(i, s, n) for (int i = s; i < int(n); ++i)
#define FORD(i, n) for (int i = n - 1; i >= 0; --i)
#define VALID(i, mx) (i >= 0 && i < mx)

string PrintCase(int i)
{     
    ostringstream os;
    os << "Case #" << (i + 1) << ": ";
    return os.str();
}

string kYes = "YES";
string kNo = "NO";

bool CanMow(int n, int m, vvi& grid)
{
    vi present(101, 0);
    vi rowMax(n, 0);
    vi colMax(m, 0);

    FOR(i, n) FOR(j, m)
    {
        int v = grid[i][j];
        present[v] = 1;
        rowMax[i] = max(rowMax[i], v);
        colMax[j] = max(colMax[j], v);
    }

    vi heights;
    FOR(i, 101) { if (present[i]) heights.push_back(i); }

    int h = heights.size();
    FOR(k, h)
    {
        int height = heights[k];
        FOR(i, n) FOR(j, m)
        {
            if (grid[i][j] != height) continue;
            if (rowMax[i] <= height) continue;
            if (colMax[j] <= height) continue;
            return false;
        }
    }

    return true;
}

int main()
{
     ofstream cout ("B-large.out");
     ifstream cin ("B-large.in");


    int t;
    cin >> t;

    FOR(c, t)
    {        
        int n, m;
        cin >> n >> m;
        vvi grid(n, m);

        FOR(i, n) FOR(j, m) cin >> grid[i][j];

        cout << PrintCase(c);

        if (CanMow(n, m, grid))
            cout << kYes << endl;
        else
            cout << kNo << endl;
    }

    return 0;
}
#endif