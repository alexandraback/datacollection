#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repf(i, f, l) for(int i = f; i < (int)l; ++i)
#define repit(it, t) for(__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++)

#define endl "\n"

#ifdef ONLINE_JUDGE
#define DEBUG false
#else
#define DEBUG true
#endif

#define pb emplace_back
#define lb lower_bound
#define ul unsigned long
#define ull unsigned long long
#define ll long long
#define INF 1000000007
#define MOD 1000000007
#define fs first
#define sd second
#define DBG0(x) if(DEBUG){ cout << #x << ": " << x << "\t"; }
#define DBG(x) if(DEBUG){DBG0(x); cout << endl;}
#define DBG2(x, y) if(DEBUG){DBG0(x); DBG(y);}
#define DBG3(x, y, z) if(DEBUG){DBG0(x); DBG2(y, z);}
#define DBG4(w, x, y, z) if(DEBUG){DBG0(w); DBG3(x, y, z);}

typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ul> vul;
typedef vector<ull> vull;
typedef vector<bool> vbl;
typedef pair<int, int> pii;

void solver(int test_case){
    printf("Case #%d: ", test_case);
    int n, m, k;
    int ret;
    cin >> n >> m >> k;
    if(n > m) swap(n, m);
    if(n <= 2){
        ret = k;
        goto lEnd;
    }
    if(n == 3){
        if(k <= 4){
            ret = k;
            goto lEnd;
        }
        if(k <= 7){
            ret = k - 1;
            goto lEnd;
        }
        if(m == 3){
            ret = k - 1;
            goto lEnd;
        }
        if(m == 4){
            ret = k - 2;
            goto lEnd;
        }
        if(m == 5){
            if(k <= 10){
                ret = k - 2;
                goto lEnd;
            }
            else{
                ret = k - 3;
                goto lEnd;
            }
        }
        if(m == 6){
            if(k <= 10){
                ret = k - 2;
                goto lEnd;
            }
            if(k <= 13){//HERE;
                ret = k - 3;
                goto lEnd;
            }
            ret = k - 4;
            goto lEnd;
        }
    }
    if(n == 4){
        if(k <= 4){
            ret = k;
            goto lEnd;
        }
        if(k <= 7){
            ret = k - 1;
            goto lEnd;
        }
        if(k <= 9){
            ret = k - 2;
            goto lEnd;
        }
        if(k <= 11){
            ret = k - 3;
            goto lEnd;
        }
        if(k <= 13){
            ret = k - 4;
            goto lEnd;
        }
        if(m == 4){
            ret = k - 4;
            goto lEnd;
        }
        if(m == 5){
            if(k <= 15){
                ret = k - 5;
                goto lEnd;
            }
            ret = k - 6;
            goto lEnd;
        }
    }
lEnd:
    printf("%d\n", ret);
    return;
}
int main(void){
    int t;
    cin >> t;
    rep(i, t) solver(i + 1);
    return 0;
}
