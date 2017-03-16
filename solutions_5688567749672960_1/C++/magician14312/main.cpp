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
#define fi first
#define se second
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

LL k;
LL POW[20];
map<LL,int> M;

LL flip(LL n){
    if(n%10 == 0) return -1;
    LL m = n;
    vector<int> A;
    while(n){
        A.pb(n%10); n/= 10;
    }
    LL tmp = 0;
    FO(i,0,A.size()) tmp = tmp*10 + A[i];
    //cout << m << " " << tmp << endl;
    return tmp;
}

LL dequy(LL n){ //cout << n << endl;
    if(M.find(n) != M.end()) return M[n];
    if(n == 1) {
        return M[1] = 1;
    }
    LL ans = infi;
    int scs = 0;
    while(1){
        scs++;
        if(POW[scs-1] > n) break;
        LL z = n%POW[scs] - 1;
        if(z <= 0) continue;
        LL c = n - z;

        if(c == -1) continue; //cout << c << " " << z << endl;

        LL tmp;
        if(c == n) {
            tmp = 1 + dequy(n-1);
            ans = min(ans, tmp);
        }
        else{
            tmp = z + dequy(c);
            ans = min(ans, tmp);
        }
    }
    LL c = flip(n);
    if(c != -1 && c < n)  ans = min(ans, 1+dequy(c));
    if(n%10 == 0) ans = min(ans, 1+dequy(n-1));

    if((n-1)%POW[scs-2] == 0) ans = min(ans, 1 + dequy(n-1));

    M[n] = ans;
    //cout << n << " " << xet[n] << endl;
    return M[n];
}

void solve(){
    M.clear();
    dequy(k);
    cout << M[k] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    POW[0] = 1;
    FOR(i,1,18) POW[i] = POW[i-1]*10;
    int sotest;
    cin >> sotest;
    FOR(test,1,sotest){
        cin >> k;
        cout << "Case #" << test << ": ";
        solve();
    }



    return 0;
}


