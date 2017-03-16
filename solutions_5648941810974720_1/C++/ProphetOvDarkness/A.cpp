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


string num[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
string fuck = "ZOWRUFXSGI";
int mapp[28];
char str[2005];
string ans;

inline void add(int x) {
    int i;
    ans += x+'0';
    for(i=0; i<sz(num[x]); i++) {
        mapp[ num[x][i]-'A' ]--;
    }
}

void l1() {
    int i;
    rep(i, 10) {
        if(i==0 || i==2 || i==4 || i==6 || i==8) {
            while(mapp[ fuck[i]-'A' ]) add(i);
        }
    }
}

void l2() {
    int i;
    rep(i, 10) {
        if(!(i==0 || i==2 || i==4 || i==6 || i==8)) {
            while(mapp[ fuck[i]-'A' ]) add(i);
        }
    }
}

int main() {
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int test, kase=1, i, len;

    sdi(test);
    while(test--) {
        mem(mapp, 0);
        ans = "";

        sds(str);
        len = strlen(str);
        rep(i, len) mapp[ str[i]-'A' ]++;

        printf("Case #%d: ", kase++);
        l1();
        l2();
        sort(all(ans));
        puts(ans.c_str());
    }

    return 0;
}
