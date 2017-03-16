#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <utility>
#include <iomanip>

using namespace std;

typedef long long LL;
template<typename T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<typename T> inline T Sqr(const T& x) { return x * x; }

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const char dw[4] = {'W', 'N', 'E', 'S'};

const int inf = 1000000000;

const int maxn = 4000;

int b[2*maxn][2*maxn];
int d[2*maxn][2*maxn];
char p[2*maxn][2*maxn];
int dir[2*maxn][2*maxn];
pair<int, int> q[100000000];



void Solution() {
    int x, y;
    cin >> x >> y;
    string ans;
    
    while (x > 0) {
        ans += "WE";
        --x;
    }
    while (x < 0) {
        ans += "EW";
        ++x;
    }
    while (y > 0) {
        ans += "SN";
        --y;
    }
    while (y < 0) {
        ans += "NS";
        ++y;
    }
    
    cout << ans << endl;
} 


struct Timer {
    map<string, float> starts;
    void Tic(const string& name) { starts[name] = clock(); }
    float Toc(const string& name) { return (clock() - starts[name]) / CLOCKS_PER_SEC; }
} timer;

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    timer.Tic("global");
    int testsNumber;
    cin >> testsNumber;
    for (int curTest = 1; curTest <= testsNumber; ++curTest) {
        cout << "Case #" << curTest << ": ";
        cerr << "Case #" << setw(2) << setfill('0') << curTest << ": running...";
        timer.Tic("test");
        Solution();
        cerr << "done! Elapsed time is " << setprecision(3) << timer.Toc("test") << endl;
    }
    cerr << endl << "Total elapsed time is " << setprecision(3) << timer.Toc("global") << endl;

    return 0;
}
