#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef long long LL;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

int main()
{
    int t, n, m;
    LL w;
    string text;
    cin >> t;
    FOR(cs, 1, t)
    {
        cin >> text >> m;
        n = SIZE(text);
        VI wzo(n, 1), spol(n), free(n);
        REP(x, n) if(text[x] == 'a' || text[x] == 'e' || text[x] == 'i' || text[x] == 'o' || text[x] == 'u') wzo[x] = 0;
        if(wzo[0]) spol[0] = 1;
        else spol[0] = 0;
        FOR(x, 1, n - 1) if(wzo[x]) spol[x] = spol[x - 1] + 1;
        else spol[x] = 0;
        if(spol[0] >= m) free[0] = 1;
        else free[0] = 0;
        FOR(x, 1, n - 1) if(spol[x] >= m) free[x] = x - m + 2;
        else free[x] = free[x - 1];
        w = 0;
        REP(x, n) w += free[x];
        cout << "Case #" << cs << ": " << w << endl;
    }
    return 0;
}
