/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int ar[5][5] = {
{0, 0, 0, 0, 0},
{0, 1, 2, 3, 4},
{0, 2, -1, 4, -3},
{0, 3, -4, -1, 2},
{0, 4, 3, -2, -1}
}, val[10005], pref[10005], suf[10005];
string s;
vector < int > vc[2], vp[2];
int mdval[5];
int multiply(int x, int y){
    if(x < 0 && y < 0){
        return ar[-x][-y];
    } else if(x < 0 && y > 0){
        return -ar[-x][y];
    } else if(x > 0 && y < 0){
        return -ar[x][-y];
    } else return ar[x][y];
}
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    FOR(ts, 1, T+1){
        LL L,X; cin >> L >> X;
        cin >> s;
        REP(i, L){
            if(s[i] == 'i') val[i] = 2;
            else if(s[i] == 'j') val[i] = 3;
            else val[i] = 4;
        }

        vc[0].clear(); vc[1].clear();
        vp[0].clear(); vp[1].clear();

        //overall
        int v = 1;
        REP(i, L){
            v = multiply(v, val[i]);
        }
        int total = v;
        mdval[0] = v = 1;
        FOR(i, 1, 4){
            v = multiply(v, total);
            mdval[i] = v;
        }

        // prefix
        v = 1;
        REP(i, L){
            v = multiply(v, val[i]);
            pref[i] = v;
            REP(j, 4){
                if(multiply(mdval[j], v) == 2){
                    vc[0].pb(i);
                    vp[0].pb(j);
                    break;
                }
            }
        }

        v = 1;
        for(int i = L-1; i >= 0; i--){
            v = multiply(val[i], v);
            suf[i] = v;
            REP(j, 4){
                if(multiply(v, mdval[j]) == 4){
                    vc[1].pb(i);
                    vp[1].pb(j);
                    break;
                }
            }
        }

        int fl = 0;
        REP(i, vc[0].size()){
            if(L == 1) continue;
            int vi = vc[0][i], ci = vp[0][i];
            REP(j, vc[1].size()){
                int vk = vc[1][j], ck = vp[1][j];

                LL cnt = ci + ck + 1;
                if(vi < vk-1 && cnt <= X && (X-cnt)%4 == 0 && multiply(pref[vi], 3) == pref[vk-1]){
                    fl = 1;
                }

                if(vi == L-1 && vk == 0) cnt += 2;
                else cnt++;
                if(cnt > X) continue;
                cnt = X - cnt; cnt %= 4ll;
                int vj = 1;
                if(vc[0][i] < L-1) vj = suf[ vc[0][i]+1 ];

                vj = multiply(vj, mdval[cnt]);
                if(vc[1][j] > 0) vj = multiply(vj, pref[ vc[1][j]-1 ]);

                if(vj == 3) fl = 1;
            }
        }

        string res;
        if(fl) res = "YES";
        else res = "NO";

        cout << "Case #" << ts << ": " << res << endl;
        cerr << "Case #" << ts << ": " << res << endl;
    }
}


