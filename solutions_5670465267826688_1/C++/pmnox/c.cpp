#include <algorithm>
#include <array>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,b) for(auto i=(0);i<(b);++i)
#define fo(i,a,b) for(auto i=(a);i<=(b);++i)
#define ford(i,a,b) for(auto i=(a);i>=(b);--i)
#define fore(a,b) for(auto a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

char buf[1111111];

int I = 1, J = 2, K = 3;

int tt[4][4] = {
    {0, I, J, K},
    {I, 0, K, J},
    {J, K, 0, I},
    {K, J, I, 0},
};

int pp[4][4] = {
    {0,0,0,0},
    {0,1,0,1},
    {0,1,1,0},
    {0,0,1,1}
};

void solve() {
    int L, X;
    scanf("%d%d", &L, &X);
    scanf("%s", buf);

    bool pos = 1;
    int num = 0;
    int state = 0;
    int did = 0;
    int did_s3 = 0;
    int last_zero_s3 = -1;
    for (int x = 0; x < X; x++) {
        if (state == 3) {
            if (did_s3 >= 100 && last_zero_s3 == -1) {
                printf("NO");
                printf("\n");
                return;
            }
            if (pos && num == 0) {
                if (last_zero_s3 == -1) {
                    last_zero_s3 = did_s3;
                }
                else {
                    int diff = did_s3 - last_zero_s3;
                    if ((X - x) % diff == 0) {
                        printf("YES");
                        printf("\n");
                        return;
                    }
                    else {
                        printf("NO");
                        printf("\n");
                        return;
                    }
                }
            }
            did_s3 += 1;
        }
        for (int i = 0; i < L; i++) {
            int next = 0;
            if (buf[i] == 'i') next = I;
            if (buf[i] == 'j') next = J;
            if (buf[i] == 'k') next = K;
            pos = pos ^ pp[num][next];
            num = tt[num][next];

//# cerr << buf[i] << " " << pos << " " << num << endl;

            if (state < 3 && pos && num == state + 1) {
                state += 1;
                pos = 1;
                num = 0;
            }
            did++;
        }
        if (state < 3 and did >= 10000000) {
            printf("NO");
            printf("\n");
            return;
        }
    }
    if (state == 3 && pos && num == 0)
        printf("YES");
    else
        printf("NO");
    printf("\n");
}

int main(int argc, char ** argv) {
    // ios::sync_with_stdio(false);

    //  freopen("../1.in","r",stdin);
    //  freopen("../2.in","r",stdin);
    //  freopen("../3.in","r",stdin);
    //  freopen("../A-small.in","r",stdin); freopen("../A-small.out","w",stdout);
    //  freopen("../A-small-attempt0.in","r",stdin);freopen("../A-small-attempt0.out","w",stdout);
    //  freopen("../A-small-attempt1.in","r",stdin);freopen("../A-small-attempt1.out","w",stdout);
    //  freopen("../A-small-attempt2.in","r",stdin);freopen("../A-small-attempt2.out","w",stdout);
    //  freopen("../A-large.in","r",stdin); freopen("../A-large.out","w",stdout);

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int t;
    scanf("%d", &t);
    fo (i, 1, t) {
        printf("Case #%d: ", i);
        solve();
        cerr.flush();
    }
	return 0;
}
