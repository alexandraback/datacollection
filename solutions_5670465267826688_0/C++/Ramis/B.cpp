#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <assert.h>
using namespace std;

void smain();
int main(){
    ios_base::sync_with_stdio(0);
#ifdef TASK
    //freopen(TASK".in","rt",stdin);
    freopen("/Users/ramis/Downloads/C-small-attempt0.in.txt","rt",stdin);
    freopen("output.txt","wt",stdout);

    const clock_t start = clock();
#endif
    smain();
#ifdef TASK
    cerr << "\nTotal Execution Time: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define fori(i,a) for(auto i=a.begin(); i!=a.end(); ++i)
#define rfori(i,a) for(auto i=a.rbegin(); i!=a.rend(); ++i)
#define int long long
#define LL long long
#define mp(a,b) make_pair(a,b)
#define INF 2000000000//2305843009213693951LL
#define MOD 1000000007
#define EPS 1E-9
#define N 2000
/* --------- END TEMPLATE CODE --------- */

int m[4][4] = {
    //1-1 2-i 3-j 4-k
    {1, 2, 3, 4},
    {2,-1, 4,-3},
    {3,-4,-1, 2},
    {4, 3,-2,-1}
};

inline int mult(int a, int b){
    int res = m[abs(a) - 1][abs(b) - 1];
    return a * b < 0 ? -res : res;
}

inline int pow(int a, int n){
    if(abs(a) == 1) return a == -1 && n % 2 ? -1 : 1;
    int n2 = n / 2;
    int res = n2 % 2 ? -1 : 1;
    if(n % 2) res *= a;
    return res;
}

inline void add(vector<int> &b, int pr, int cnt){
    int th = 4;
    forn(_i, min(cnt, th)) b.push_back(pr);
    cnt -= min(cnt, th);
    if(cnt > th) b.push_back(pow(pr, cnt - th));
    forn(_i, min(cnt, th)) b.push_back(pr);
}

inline void compress(vector<int> &a) {
    int n = a.size();
    int pr = 0, cnt = 0;

    vector<int> b;
    forn(i, n) {
        if(a[i] != pr){
            if(pr != 0) add(b, pr, cnt);
            pr = a[i], cnt = 1;
        }else{
            cnt += 1;
        }
    }
    if(pr != 0) add(b, pr, cnt);
    a = b;
}

bool solve(string s, int x){
    vector<int> a(s.size());
    int n = s.size();
    forn(i, n){
        if(s[i] == '1') a[i] = 1;
        else a[i] = s[i] - 'i' + 2;
    }
    compress(a);
    n = a.size();
    //for(auto i : a) cout << i << ' '; cout << endl;

    vector<int> b, eb;
    for(;x > 0 && b.size() < 100; --x){
        forn(i, n){
            if(i < N || (x == 1 && i > n - N)) b.push_back(a[i]);
            else b.back() = mult(b.back(), a[i]);
        }
    }
    for(;x > 0 && eb.size() < 100; --x){
        rforn(i, n){
            if(i > n - N) eb.push_back(a[i]);
            else eb.back() = mult(a[i], eb.back());
        }
    }
    if(x > 0){
        int r = 0;
        forn(i, n) r = r == 0 ? a[i] : mult(r, a[i]);

        b.push_back(pow(r, x));
        //forn(iii, x) forn(i, n) b.push_back(a[i]);
    }
    b.insert(b.end(), eb.rbegin(), eb.rend());

    //for(auto i : b) cout << i << ' '; cout << endl;

    n = b.size();
    vector<bool> oki(n, false), okk(n, false);
     
    int ri = 0;
    forn(i, n) {
        if(i == 0) ri = b[i];
        else ri = mult(ri, b[i]);
        oki[i] = ri == 2;
    }
    
    int rk = 0;
    rforn(i, n) {
        if(rk == 0) rk = b[i];
        else rk = mult(b[i], rk);
        okk[i] = rk == 4;
    }

    forn(i, n) if(oki[i]) {
        int rj = 0;
        for(int j=i+1; j < n - 1; ++j){
            if(rj == 0) rj = b[j];
            else rj = mult(rj, b[j]);
            if(rj == 3 && okk[j + 1]){
                //cout << i << ' ' << j << endl;
                return true;
            }
        }
    }

    return false;
}


bool solve_naive(string &s, int x){
    int n = s.length();
    vector<int> a;
    forn(j, x) forn(i, n){
        if(s[i] == '1') a.push_back(1);
        else a.push_back(s[i] - 'i' + 2);
    }
    n = a.size();
    int ri = 0;
    forn(i, n) {
        if(ri == 0) ri = a[i];
        else ri = mult(ri, a[i]);
        if(ri != 2) continue;
        
        int rj = 0;
        for(int j=i+1; j < n - 1; ++j){ 
            if(rj == 0) rj = a[j];
            else rj = mult(rj, a[j]);
            if(rj != 3) continue;

            int rk = 0;
            for(int k=j+1; k < n; ++k){
                if(rk == 0) rk = a[k];
                else rk = mult(rk, a[k]);
            }
            
            if(rk == 4){
                cout << i << ' ' << j << endl;
                return true;
            }
        }
    }
    return false;
}

void smain() {
    int x, n;
    string s;
    cin >> n;
    for(int t = 1; cin >> n >> x; ++t){
        cin >> s;
        bool r1 = solve(s, x);
        cout << "Case #" << t << ": " << (r1 ? "YES" : "NO") << '\n';
    }
    
    return;
    for(int t = 1; t < 100 || cin >> n >> x; ++t){
        //cin >> s;
        s.clear();
        n = 10, x = rand() % 300 + 1;
        forn(i, n) s.push_back((rand() % (i + 1)) % 3 + 'i');
        bool r1 = solve(s, x);
        bool r2 = solve_naive(s, x);
        if(r1 != r2){
            cout << "Expected " << r2 << " Found " << r1 << " at " << x << endl << s << endl;
            return;
        }
        cout << "Case " << t << ": " << (r1 ? "YES" : "NO") << '\n';
    }
}
