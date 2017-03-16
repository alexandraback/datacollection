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
	#define READ freopen("B-large.in", "r", stdin)
	#define WRITE freopen("B-large.out", "w", stdout)
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

const int MAX_SUM = 30;

int normalTripletsMaxScore[MAX_SUM + 1];
int surprisingTripletsMaxScore[MAX_SUM + 1];

int getState(int a, int b, int c) {
    int maxV = max(a, max(b, c));
    int minV = min(a, min(b, c));
    if (maxV - minV > 2) {
        return -1;
    } else if (maxV - minV == 2) {
        return 1;
    } else {
        return 0;
    }
}

void preProcess() {
    range (i, 0, MAX_SUM) {
        normalTripletsMaxScore[i] = -1;
        surprisingTripletsMaxScore[i] = -1;
    }

    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            for (int k = 0; k <= 10; ++k) {
                int state = getState(i, j, k);
                if (-1 == state) {
                    continue;
                } else if (0 == state) {
                    checkMax(normalTripletsMaxScore[i + j + k], max(i, max(j, k)));
                } else if (1 == state) {
                    checkMax(surprisingTripletsMaxScore[i + j + k], max(i, max(j, k)));
                } else {
                    cerr << "Get all triplets error!" << endl;
                }
            }
        }
    }
}

int calc(const int score, const int p) {
    return score >= p;
}

const int MAX_N = 128;
void run(const int &caseID) {
    int n = 0, s = 0, p = 0;
    cin >> n >> s >> p;

    int sum[MAX_N] = {0};
    range (i, 1, n) {
        cin >> sum[i];
    }

    int dp[MAX_N][MAX_N];
    setv(dp, 0x0);

    range (i, 1, n) {
        range (j, 0, i) {
            if (normalTripletsMaxScore[sum[i]] != -1) {
                checkMax(dp[i][j], dp[i - 1][j] + calc(normalTripletsMaxScore[sum[i]], p));
            }
            if (j > 0 && surprisingTripletsMaxScore[sum[i]] != 0) {
                checkMax(dp[i][j], dp[i - 1][j - 1] + calc(surprisingTripletsMaxScore[sum[i]], p));
            }
            //fprintf(stderr, "dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }

    printf("Case #%d: %d\n", caseID, dp[n][s]);
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

