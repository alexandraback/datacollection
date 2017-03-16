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
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

double ar[2][1001];
int pre[1001],vis[1001];
vector<int>vc[1001];
int find(int id)
{
    int x,y,z;
    for(x=0;x<vc[id].size();x++)
    {
        if(vis[vc[id][x]]==0)
        {
            vis[vc[id][x]]=1;
            if(pre[vc[id][x]]==-1 || find(pre[vc[id][x]]))
            {
                pre[vc[id][x]]=id;
                return 1;
            }
        }
    }
    return 0;
}
int bpm(int n)
{
    int a=0,x;
    memset(pre,-1,sizeof pre);
    for(x=0;x<n;x++)
    {
        memset(vis,0,sizeof vis);
        a+=find(x);
    }
    return a;
}

main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f = 0,g,h = 0,x,y,z;
    cin >> a;
    FOR(ts, 1, a + 1){
        cin >> b;
        REP(i, b) cin >> ar[0][i];
        REP(i, b) cin >> ar[1][i];
        sort(ar[0], ar[0] + b);
        sort(ar[1], ar[1] + b);
        c = d = 0;
        REP(i, 1000) vc[i].clear();
        for(int i = 0; i < b; i++){
            for(int j = 0; j < b; j++){
                if(ar[0][i] > ar[1][j]) vc[i].pb(j);
            }
        }
        c = bpm(b);
        REP(i, 1000) vc[i].clear();
        for(int i = 0; i < b; i++){
            for(int j = 0; j < b; j++){
                if(ar[1][i] > ar[0][j]) vc[i].pb(j);
            }
        }
        d = bpm(b);
        cout << "Case #" << ts << ": " << c << " " << b - d << endl;
        cerr << "Case #" << ts << ": " << c << " " << b - d << endl;
    }
}
