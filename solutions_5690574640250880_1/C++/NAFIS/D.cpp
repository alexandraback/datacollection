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
#define PI         2.0*acos(0.0)
#define linf       (1<<60)-1
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

int ar[55][55], tmp[55][55];
int ok = 0, im = 0;
void go(int a, int b){
    set0(tmp);
    queue < pair < int, int > > Q;
    Q.push(mp(1, 1));
    while(!Q.empty()){
        pair < int, int > pp = Q.front();
        Q.pop();
        tmp[pp.xx][pp.yy] = 1;
        for(int i = max(pp.xx - 1, 1); i <= min(pp.xx + 1, a); i++){
            for(int j = max(pp.yy - 1, 1); j <= min(pp.yy + 1, b); j++){
                if(ar[i][j] == 1)tmp[pp.xx][pp.yy]++;
            }
        }
        for(int i = max(pp.xx - 1, 1); i <= min(pp.xx + 1, a); i++){
            for(int j = max(pp.yy - 1, 1); j <= min(pp.yy + 1, b); j++){
                if(tmp[pp.xx][pp.yy] == 1 && ar[i][j] != 1 && tmp[i][j] == 0)Q.push(mp(i, j));
            }
        }
    }
    im++;
    FOR(i, 1, a + 1){
        FOR(j, 1, b + 1){
            if(ar[i][j] != 1 && tmp[i][j] == 0){
                cerr << "ERROR" << endl;
                return;
            }
        }
    }
    cerr << "OK" << endl;
    ok++;
}

main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a;
    FOR(ts, 1, a + 1){
        set0(ar);
        cin >> b >> c >> d;
        cout << "Case #" << ts << ":" << endl;
//        cerr << "Case #" << ts << ":" << endl;
        if(b == 1){

                ar[1][1] = 2;
                for(int i = c; i > 2; i--){
                    if(d == 0)continue;
                    ar[1][i] = 1;
                    d--;
                }
                for(int i = 1; i <= b; i++){
                    for(int j = 1; j <= c; j++){
                        if(ar[i][j] == 2)cout << "c";
                        else if(ar[i][j] == 1) cout << "*";
                        else cout << ".";
                    }
                    cout << endl;
                }
//                go(b, c);
        } else if(c == 1){
                ar[1][1] = 2;
                for(int i = b; i > 2; i--){
                    if(d == 0)continue;
                    ar[i][1] = 1;
                    d--;
                }
                for(int i = 1; i <= b; i++){
                    for(int j = 1; j <= c; j++){
                        if(ar[i][j] == 2)cout << "c";
                        else if(ar[i][j] == 1) cout << "*";
                        else cout << ".";
                    }
                    cout << endl;
                }
//                go(b, c);
        } else {
            g = 0;
            if(d == (b*c) - 1){
                FOR(i, 1, b + 1) FOR(j, 1, c + 1) ar[i][j] = 1;
                ar[1][1] = 2;
                g = 1;
                goto pp;
            }
            if(d > (b * c) - 4){
                goto pp;
            }
            for(int i = 0; i <= (b - 2); i++){
                for(int j = 0; j <= (c - 2); j++){
                    f = i * c + j * b - i * j;
                    e = (b - i)*2 + (c - j)*2 - 4;
                    if((b * c - e) < d || f > d)continue;
                    g = 1;
                    for(int k = b; k >= b - i + 1; k--){
                        for(int l = 1; l <= c; l++){
                            if(ar[k][l] == 0){
                                ar[k][l] = 1;
                                d--;
                            }
                        }
                    }
                    for(int k = c; k >= c - j + 1; k--){
                        for(int l = 1; l <= b; l++){
                            if(ar[l][k] == 0){
                                ar[l][k] = 1;
                                d--;
                            }
                        }
                    }
                    for(int k = (b - i); k >= 3; k--){
                        for(int l = (c - j); l >= 3; l--){
                            if(d == 0)continue;
                            if(ar[k][l] == 0){
                                ar[k][l] = 1;
                                d--;
                            }
                        }
                    }
                    ar[1][1] = 2;
                    goto pp;
                }
            }
            pp:
            if(g == 0) cout << "Impossible" << endl;
            else {
//                go(b, c);
                for(int i = 1; i <= b; i++){
                    for(int j = 1; j <= c; j++){
                        if(ar[i][j] == 2)cout << "c";
                        else if(ar[i][j] == 1) cout << "*";
                        else cout << ".";
                    }
                    cout << endl;
                }
            }
        }
    }
    cerr << im << " " << ok << endl;
}
