/**
* Change is impossible in this fog of ignorance.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>
using namespace std;

#define trace(x) {cerr << #x << "=" << x <<endl;}
#define trace2(x, y) {cerr << #x << "=" << x << " " << #y << "=" << y <<endl;}
#define track(x) {cerr << #x << ":" << endl; for (int q = 0; q < x.size(); q++) {cerr << x[q] << " ";} cerr << endl;}
#define trackarr(x, n) {cerr << #x << ":" << endl; for (int q = 0; q < n; q++) {cerr << x[q] << " ";} cerr << endl;}
#define trackvv(x) {cerr << #x << ":" << endl; for (int i = 0; i < x.size(); i++) { cerr << "i:" << i << endl; for (int j = 0; j < x[i].size(); j++){cerr << x[i][j] << " ";} cerr << endl;} cerr << endl;}
#define trackcr(x) {cerr << #x << ":" << endl; for (auto i = x.begin(); i != x.end(); i++) {cerr << *i << " ";} cerr << endl;}
template <typename Tk, typename Tv> ostream& operator<<(ostream& os, const pair<Tk, Tv> &p){os << "{" << p.first << ',' << p.second << "}";return os;}

typedef long long ll;

const int MAX = 100005;
const int MOD = 1000000000+7;
const int INF = 1000000000;

void inout() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
}


int n;
ll a[25], b[25];

const int MAXSIZE = 1<<20;
int dp[MAXSIZE];
bool exist[MAXSIZE];

int canMake(int mask, int i) {
    bool ap, bp;
    ap=bp=false;
    for (int j = 0; j < n; j++) {
        bool isPresent = mask & (1<<j);
        if (isPresent) {
            if (a[i] == a[j]) ap=true;
            if (b[i] == b[j]) bp=true;
        }
    }
    return ap&&bp;
}

int solve(int idx, int mask) {
    if (idx==n) {
        return 0;
    } else if (!exist[mask]) {
        int maxAnswer = 0;
        for (int i = 0; i < n; i++) {
            bool isPresent = mask & (1<<i);
            if (!isPresent) {
                int cost=canMake(mask, i);
                int newmask = mask | (1<<i);
                maxAnswer = max(maxAnswer, cost + solve(idx+1, newmask));
            }
        }
        dp[mask] = maxAnswer;
        exist[mask] = true;
    }
    return dp[mask];
}


long long power(long long n, long long m, long long MOD){
    if (m == 0) return 1;
    long long x = power(n, m / 2, MOD);
    if (!(m & 1)) return (x * x) % MOD;
    else return (((x * x) % MOD) * n) % MOD;
}

const long long B = 100000007;
const long long M = 1000000009;
const long long invB = power(B, M-2, M);

long long getHash(const string s) {
	long long h = 0; // hash of the string
	int length = s.size();
	for (int i = length-1; i >= 0; i--) {
		h *= B;
		h += (s[i] - 'A');
		h %= M;
	}
	return h;
}

void init() {
    memset(exist, 0, sizeof(exist));
}

void doTask() {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char temp[25];
        scanf("%s", temp);
        a[i]=getHash(temp);
        scanf("%s", temp);
        b[i]=getHash(temp);
    }
    int maxTopics = solve(0, 0);
    printf("%d\n", maxTopics);
}

int main() {
    inout();
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        cerr << t << endl;
        printf("Case #%d: ", t);
        doTask();
    }
}
