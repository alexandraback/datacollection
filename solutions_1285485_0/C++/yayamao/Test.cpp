#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

// Template Begin(By yayamao)
#ifndef ONLINE_JUDGE
	#define READ freopen("D-small-attempt1.in", "r", stdin)
	#define WRITE freopen("D-small-attempt1.out", "w", stdout)
#else
	#define READ
	#define WRITE
#endif

#ifdef _MSC_VER
	#define int64 __int64
	#define uint64 unsigned __int64
#else
	#define int64 long long
	#define uint64 unsigned long long
#endif

#define S(x) ((int)x.size())
#define L(x) ((int)x.length())

#define X first
#define Y second
#define MII map<int, int>
#define MSI map<string, int>
#define MIS map<int, string>
#define PII pair<int, int>
#define PSI pair<string, int>
#define PIS pair<int, string>
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)

#define TWO(x)			(1 << (x))
#define TWOL(x)			(1LL << (x))
#define LOWER_BIT(x)	((x) & (-(x)))
#define CONTAIN(s,x)	(((s) & TWO(x)) != 0)
#define CONTAINL(s,x)	(((s) & TWOL(x)) != 0)

template<class T>inline void checkMax(T &a,const T &b){if(a < b) a = b;}
template<class T>inline void checkMin(T &a,const T &b){if(b < a) a = b;}
template<class T>inline string toString(const T &n){ostringstream out; out << n; out.flush(); return out.str();}
template<class T>inline T toValue(const string &s){T x; istringstream in(s); in >> x; return x;}
bool hasNext(){char c;if(scanf(" %c",&c)==EOF) return false; ungetc(c, stdin); return true;}

const double EPS  = 1E-9;
const double D_INF = 1E99;
const int I_INF = 0x7FFFFFFF;
const int64 L_INF = 0x7FFFFFFFFFFFFFFFLL;

int dx[]={ 0, 0,-1, 1,-1, 1,-1, 1};
int dy[]={-1, 1, 0, 0,-1,-1, 1, 1};
string dir[]={"L", "R", "U", "D", "LU", "LD", "RU", "RD"};

int tenPower[10]={0x1,0xA,0x64,0x3E8,0x2710,0x186A0,0xF4240,0x989680,0x5F5E100,0x3B9ACA00};

// [l, r]
#define range(i, l, r) for(int i = (l); i <= (int)(r); ++i)
#define rangeD(i, r, l) for(int i = (r); i >= (int)(l); --i)

// [0, n)
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define repD(i, n) for(int i = (int)(n) - 1; i >= 0; --i)

// [begin, end)
#define foreach(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define setv(a, v) memset(a, v, sizeof(a))
#define all(c) (c).begin(), (c).end()
// Template Ended(By yayamao)

void preProcess() {
}

const int MAX_H = 1024;
const int MAX_W = 1024;

int H = 0, W = 0, D = 0;
int maxH = 0, maxW = 0;
char grid[MAX_H][MAX_W];

void outputGrid(int H, int W) {
    rep (i, H) {
        rep (j, W) {
            cerr << grid[i][j];
        }
        cerr << endl;
    }
}

void readData() {
    setv(grid, 0x0);

    cin >> H >> W >> D;
    getchar();

    H -= 2;
    W -= 2;

    char buffer[128];
    gets(buffer);
    rep (i, H) {
        getchar();
        rep (j, W) {
            cin >> grid[i][j];
        }
        getchar();
        getchar();
    }
    gets(buffer);
}

void reflectLeft(int upLeftX, int upLeftY) {
    for (int x = upLeftX; x < upLeftX + H; ++x) {
        for (int y = upLeftY; y < upLeftY + W; ++y) {
            grid[x][W - (y - upLeftY) - 1 + upLeftY + W] = grid[x][y];
        }
    }
}

void reflectDown(int upLeftX, int upLeftY) {
    for (int x = upLeftX; x < upLeftX + H; ++x) {
        for (int y = upLeftY; y < upLeftY + W; ++y) {
            grid[H - (x - upLeftX) - 1 + upLeftX + H][y] = grid[x][y];
        }
    }
}

void expandGrid() {
    int eH = (D + H - 1) / H;
    int eW = (D + W - 1) / W;

    maxH = (4 * eH + 1) * H;
    maxW = (4 * eW + 1) * W;

    if (maxH > MAX_H || maxW > MAX_W) {
        cerr << "Too large" << endl;
        return;
    }
    
    int nowI = 0;
    rep (i, 4 * eH + 1) {
        int nowJ = 0;
        rep (j, 4 * eW) {
            reflectLeft(nowI, nowJ);
            nowJ += W;
        }
        reflectDown(nowI, 0);
        nowI += H;
    }
}

int solve() {
    int eH = (D + H - 1) / H;
    int eW = (D + W - 1) / W;

    int meX = (2* eH + 1) * H, meY = (2 * eW + 1) * W;

    rep (i, H) {
        bool findX = false;
        rep (j, W) {
            if ('X' == grid[i + meX][j + meY]) {
                meX += i;
                meY += j;
                findX = true;
                break;
            }
        }
        if (findX) {
            //cerr << "Find X" << endl;
            break;
        }
    }

    set<PII> angleSet;
    angleSet.clear();

    rep (x, maxH) {
        rep (y, maxW) {
            if (grid[x][y] != 'X') {
                continue;
            }
            if (x == meX && y == meY) {
                continue;
            }
            int dx = x - meX;
            int dy = y - meY;
            if (dx * dx + dy * dy <= D * D) {
                int d = __gcd(abs(dx), abs(dy));
                dx /= d;
                dy /= d;

                angleSet.insert(MP(dx, dy));
            }
        }
    }

    return S(angleSet);
}

void run(const int &caseID) {
    readData();
    expandGrid();

    // debug
    //cerr << H << ' ' << W << endl;
    //cerr << maxH << ' ' << maxW << endl;
    //cerr << maxH / H << ' ' << maxW / W << endl;
    //outputGrid(maxH, maxW);
    
    cout << "Case #" << caseID << ": " << solve() << endl;
}

void runWithCaseT() {
    int caseT;
    scanf("%d", &caseT);
    getchar();
    for(int caseID = 1; caseID <= caseT; ++caseID) {
        run(caseID);
    }
}

void runWithoutCaseT() {
    int caseID = 0;
    while(hasNext()) {
        run(++caseID);
    }
}

int main(int argc, char *argv[]) {
    READ;
    WRITE;

    preProcess();

    runWithCaseT();
    //runWithoutCaseT();

    return (EXIT_SUCCESS);
}

