#include<iostream>
#include<cassert>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<iterator>
#include<ctime>
#include<map>
#include<sstream>
#include<set>
#include<cctype>
#include<queue>
#include <memory.h>

using namespace std;

#define all(c) (c).begin(), (c).end()

template<typename T> inline string intToString(T x){ostringstream q;q << x;return q.str();}
template<typename T> inline T myPow(T x, T n, T MOD){T res = 1;while (n>0) {if (n & 1) {res = 1ll*res * x % MOD;}x = 1ll*x * x % MOD;n/=2;}return res;}
template<typename T> inline T gcd(T a, T b){a=abs(a);b=abs(b);while ((a>0) && (b>0)) {if (a>b)a%=b;else b%=a;}return a+b;}


typedef unsigned long long LLong;
typedef long double LDb;

int n;
string a[411];
long long b[411];
long long res;
long long K;
int w[411];
int used[311];
int used2[311];
bool usedC[311];
const long long MOD = 1000000007;

long long fact(int n) {
    long long res = 1;
    for (int i = 1; i <= n; ++i) {
        res = (res*i)%MOD;
    }
    return res;
}


void check()
{
    string s;
    for (int i = 0; i < n; ++i) {
        s += a[w[i]];
    }
    cout << s << endl;
    
    int len = s.length();
    char l = s[0];
    memset(usedC, 0, sizeof usedC);
    for (int i = 0; i < len; ++i) {
        if (usedC[s[i]] && s[i] != l) {
            return;
        }
        usedC[s[i]] = true;
        l = s[i];
    }

    res = (res+1)%MOD;
}


void rec(int v)
{
    if (v==n) {
        check();
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            w[v] = i;
            used[i] = true;
            rec(v+1);
            used[i] = false;
        }
    }
}

int main()
{
#ifdef m0stik
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("river.in","r",stdin);
    //freopen("river.out","w",stdout);
#endif
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        cout << "Case #" << tt+1 << ": ";
        K = 1;
        cin >> n;
        res = 0;
        memset(used,0,sizeof used);
        memset(b,0,sizeof b);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n; ++i) {
            if (a[i][0] == a[i][a[i].length()-1]) {
                ++b[a[i][0]];
            }
        }

        
        for (int i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
            if (b[i]>0) {
                K = (K*fact(b[i])) % MOD;   
            }
        }

        for (int i = 0; i < n; ++i) {
            if (a[i][0] == a[i][a[i].length()-1]) {
                for (int j = 0; j < n; ++j) {
                    if (i!=j && a[j][a[j].length()-1] == a[i][0]) {
                        a[j] += a[i];
                        swap(a[i],a[n-1]);
                        n--;
                        i=0;
                        break;
                    }
                    if (i!=j && a[j][0] == a[i][0]) {
                        a[j] = a[i] + a[j];
                        swap(a[i],a[n-1]);
                        n--;
                        i=0;
                        break;
                    }
                }
            }
        }
        
        for (;;) {
            bool any = false;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j && a[i][a[i].length()-1] == a[j][0]) {
                         
                        a[i] = a[i]+a[j];
                        if (j != n-1) {
                            swap(a[j],a[n-1]);
                        }

                        --n;
                        any = true;
                        break;
                    }
                }
            }
            if (!any)
                break;
        }

        for (int i = 0; i < 300; ++i) {
            used[i] = -1;
        }

        bool bad = false;

        for (int i = 0; i < n; ++i) {
            for (size_t j = 0; j < a[i].length(); ++j) {
                if (used[a[i][j]] != -1) {
                    if (used[a[i][j]] != i || used2[a[i][j]] != j-1) {
                        bad = true;
                        break;
                    }
                }
                used[a[i][j]] = i;
                used2[a[i][j]] = j;
            }
            if (bad)
                break;
        }




        if (bad) {
            cout << 0 << endl;
            continue;
        }


        memset(used, 0, sizeof used);

        long long qq = 1;
        for (int i = 1; i <= n; ++i) {
            qq = (qq*i)%MOD;
        }
        
        
        //rec(0);
        cout << (qq*K)%MOD << endl;
        
    }
    return 0;
} 