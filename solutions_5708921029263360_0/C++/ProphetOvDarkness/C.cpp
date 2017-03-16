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


int a, b, c, k, mapp[5][5][5], key, cnt;
struct data {
    int x, y, z;
} arr[40];

inline void fuck(data d) {
    if(mapp[0][d.x][d.y]+1 <= k &&
       mapp[1][d.y][d.z]+1 <= k &&
       mapp[2][d.z][d.x]+1 <= k) {
            arr[key++] = d;
            cnt++;
            mapp[0][d.x][d.y] += 1;
            mapp[1][d.y][d.z] += 1;
            mapp[2][d.z][d.x] += 1;
    }
}

int main() {
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int test, kase=1, i, j, l;

    sdi(test);
    while(test--) {
        cnt = key = 0;
        mem(mapp, 0);

        sdiii(a, b, c);
        sdi(k);
        if(k > max(a, max(b, c))) {
            printf("Case #%d: %d\n", kase++, a*b*c);
            repl(i, a) {
                repl(j, b) {
                    repl(l, c) {
                        pfiii(i, j, l);
                    }
                }
            }
            continue;
        }

        repl(l, c) {
            repl(j, b) {
                repl(i, a) {
                    fuck({ i, j, l });
                }
            }
        }

        printf("Case #%d: %d\n", kase++, cnt);
        rep(i, cnt) {
            pfiii(arr[i].x, arr[i].y, arr[i].z);
        }
    }

    return 0;
}
