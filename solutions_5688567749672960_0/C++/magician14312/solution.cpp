#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <fstream>
#include <ctime>
#include <iomanip>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOD(i,a,b) for(int i=a;i>b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef pair<int, int>II;
typedef pair<int,II>PII;
template<class T> T gcd(T a, T b) {T r; while(b!=0) {r=a%b;a=b;b=r;} return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }

const double PI = 2*acos(0.0);
const double eps = 1e-15;
const int infi = 1e9;
const LL Linfi = (LL) 1e18;
const LL MOD = 1000000007;
const int c1 = 31;
const int c2 = 37;
#define maxn 1000005

int n;
int dp[maxn];
int pred[maxn];

int flip(int n){
    int m = n;
    vector<int> A;
    while(n){
        A.pb(n%10); n/= 10;
    }
    int tmp = 0;
    FO(i,0,A.size()) tmp = tmp*10 + A[i];
    //cout << m << " " << tmp << endl;
    return tmp;
}

void Init(){
    FOR(i,0,maxn-1) dp[i] = infi;
    dp[1] = 1;
    for (int i = 1; i + 1 < maxn; ++i) {
        if (dp[i + 1] > dp[i] + 1) {
            dp[i + 1] = dp[i] + 1;
            pred[i + 1] = i;
        }
        int j = flip(i);
        if (j < maxn) {
            if (dp[j] > dp[i] + 1) {
                dp[j] = dp[i] + 1;
                pred[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    Init();
    int sotest;
    cin >> sotest;
    FOR(test,1,sotest){
        cin >> n;
        cout << "Case #" << test << ": " << dp[n] << endl;
    }

    return 0;
}
