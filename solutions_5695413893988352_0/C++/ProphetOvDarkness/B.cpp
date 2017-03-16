#include <bits/stdc++.h>

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin(); i!=(n).end(); i++)

#define sz(x) (int) x.size()
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define uu first
#define vv second
#define mem(x, y) memset(x, y, sizeof(x));

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define eps 1e-9
#define OK printf("ok\n")
#define DB(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pii;

inline int setBit(int N, int pos) { return N=N | (1<<pos); }
inline int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


vector <string> s[2];
int n[2], mn;
char str[2][10];
string outA, outB;

void bt(int type, int idx, string cur) {
    if(idx >= n[type]) {
        s[type].pb(cur);
        return;
    }

    if(str[type][idx] != '?') {
        cur += str[type][idx];
        bt(type, idx+1, cur);
    }
    else {
        int i;
        rep(i, 10) {
            cur += i+'0';
            bt(type, idx+1, cur);
            cur.pop_back();
        }
    }
}

void solve() {
    for(auto a : s[0]) {
        for(auto b : s[1]) {
            int x = abs(atoi(a.c_str()) - atoi(b.c_str()));
            if(x < mn) {
                mn = x;
                outA = a;
                outB = b;
            }
            else if(x == mn) {
                if(atoi(a.c_str()) < atoi(outA.c_str())) {
                    outA = a;
                    outB = b;
                }
                else if(atoi(a.c_str()) == atoi(outA.c_str()) &&
                        atoi(b.c_str()) == atoi(outB.c_str())) {
                    outA = a;
                    outB = b;
                }
            }
        }
    }
}

int main() {
    freopen("B-small.in","r",stdin);
    freopen("B-small.out","w",stdout);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int test, kase=1, i;

    sdi(test);
    while(test--) {
        mn = INT_MAX;
        outA = outB = "";

        sds(str[0]);
        sds(str[1]);
        rep(i, 2) {
            s[i].clear();
            n[i] = strlen(str[i]);
            bt(i, 0, "");
        }
        solve();
        printf("Case #%d: %s %s\n", kase++, outA.c_str(), outB.c_str());
    }

    return 0;
}
