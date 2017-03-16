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

const double kPI = 3.14159265359;
const double kEps = 1E-9;
int main()
{
    ofstream cout ("A-small-attempt0.out");
    ifstream cin ("A-small-attempt0.in");

    int numCases;
    cin >> numCases;    
    FOR(cs, numCases)
    {
        double r, t;
        cin >> r >> t;

        double area = kPI * t;

        int rings = 0;
        double prev = r - 1;
        while (area > 0.0)
        {
            double cur = prev + 2;
            double newArea = kPI * (cur * cur - (cur - 1) * (cur - 1));
            area -= newArea;
            if (area < -kEps)
                break;

            ++rings;
            prev = cur;
        }

        cout << PrintCase(cs) << rings << endl;

    }

    int i;
    cin >> i;

    return 0;
}
#endif