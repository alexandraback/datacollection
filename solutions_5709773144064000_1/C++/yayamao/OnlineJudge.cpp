#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

// Template Begin(By yayamao)
#ifndef ONLINE_JUDGE
    #define READ(file_name) freopen(file_name, "r", stdin)
    #define WRITE(file_name) freopen(file_name, "w", stdout)
#else
    #define READ(file_name)
    #define WRITE(file_name)
#endif

#ifdef _MSC_VER
    #define int64 __int64
    #define uint64 unsigned __int64
#else
    #define int64 long long
    #define uint64 unsigned long long
#endif

#define EPS 1E-9
#define D_INF 1E99
#define I_INF 0x7FFFFFFF
#define L_INF 0x7FFFFFFFFFFFFFFFLL

#define S(x) ((int)x.size())
#define L(x) ((int)x.length())

#define X first
#define Y second

#define VI vector<int>
#define VS vector<string>
#define PB(x) push_back(x)

#define MII map<int, int>
#define MSI map<string, int>
#define MIS map<int, string>

#define PII pair<int, int>
#define PSI pair<string, int>
#define PIS pair<int, string>
#define MP(x,y) make_pair(x, y)

#define TWO(x)          (1 << (x))
#define TWOL(x)         (1LL << (x))
#define LOWER_BIT(x)    ((x) & (-(x)))
#define CONTAIN(s,x)    (((s) & TWO(x)) != 0)
#define CONTAINL(s,x)   (((s) & TWOL(x)) != 0)

template<class T>inline void checkMax(T &a, const T &b){if (a < b) a = b;}
template<class T>inline void checkMin(T &a, const T &b){if (b < a) a = b;}
template<class T>inline std::string toString(const T &n){std::ostringstream out;out << n;out.flush();return out.str();}
template<class T>inline T toValue(const std::string &s){T x;std::istringstream in(s);in >> x;return x;}
bool hasNext(){char c;if (scanf(" %c", &c) == EOF) return false;ungetc(c, stdin);return true;}

int dx[]={ 0, 0,-1, 1,-1, 1,-1, 1};
int dy[]={-1, 1, 0, 0,-1,-1, 1, 1};
std::string dir[]={"L", "R", "U", "D", "LU", "LD", "RU", "RD"};

int tenPower[10]={0x1, 0xA, 0x64, 0x3E8, 0x2710, 0x186A0, 0xF4240, 0x989680, 0x5F5E100, 0x3B9ACA00};

#define setv(a, v) memset(a, v, sizeof(a))

// [l, r]
#define range(i, l, r) for(int i = (l); i <= (int)(r); ++i)
#define rangeD(i, r, l) for(int i = (r); i >= (int)(l); --i)

// [0, n)
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define repD(i, n) for(int i = (int)(n) - 1; i >= 0; --i)

#define all(c) (c).begin(), (c).end()
#define foreach(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
// Template Ended(By yayamao)

void preProcess() {
}

void run(const int caseId) {
    double C, F, X;
    cin >> C >> F >> X;

    double result = X / 2.0;

    double num_farms = 0;
    double num_cookies = 0;
    double elapsed_time = 0;
    while (true) {
        double current_speed = (2 + num_farms * F);
        // Keep util win.
        double done = elapsed_time + max(0.0, (X - num_cookies)) / current_speed;
        checkMin(result, done);

        // Buy one more farm.
        double wait_time = max(0.0, (C - num_cookies)) / current_speed;

        elapsed_time += wait_time;
        num_cookies += current_speed * wait_time - C;
        num_farms += 1;

        // Break if no need.
        if (elapsed_time > result) {
            break;
        }
    }

    printf("Case #%d: %.7lf\n", caseId, result);
    // cout << "Case #" << caseId << ": " << result << endl;
}

void runWithCaseT() {
    int caseT;
    scanf("%d\n", &caseT);
    for(int caseId = 1; caseId <= caseT; ++caseId) {
        clock_t begin = clock();
        run(caseId);
        clock_t end = clock();
        fprintf(stderr, "Case #%d cost time %.0lfms.\n", caseId, (double)(end - begin) * 1000.0 / CLOCKS_PER_SEC);
    }
}

void runWithoutCaseT() {
    int caseId = 0;
    while(hasNext()) {
        clock_t begin = clock();
        run(++caseId);
        clock_t end = clock();
        fprintf(stderr, "Case #%d cost time %.0lfms.\n", caseId, (double)(end - begin) * 1000.0 / CLOCKS_PER_SEC);
    }
}

void makeData() {
    freopen("in", "w", stdout);
    int T = 100;
    cout << T << endl;
}

int main(int argc, char *argv[]) {
    //makeData(); return 0;
    srand(time(NULL));

    if (argc == 3) {
        READ(argv[1]);
        WRITE(argv[2]);
    } else {
        READ("in");
        WRITE("out");
    }

    preProcess();

    clock_t begin = clock();
    runWithCaseT();
    //runWithoutCaseT();
    clock_t end = clock();
    fprintf(stderr, "Total case cost time %.3lfs.\n", (double)(end - begin) / CLOCKS_PER_SEC);

    return (EXIT_SUCCESS);
}

