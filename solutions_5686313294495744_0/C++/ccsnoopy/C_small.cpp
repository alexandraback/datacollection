#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#ifdef DEBUG
    #define cek(x) cout<<x
#else
    #define cek(x) if(false){}
#endif // DEBUG

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define PI acos(-1.0)
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define sc(x) scanf("%d",&x)

typedef struct{
    string x, y;
    bool palsu;
}asdf;

int main(void){
    freopen("C:/Users/SONY/Desktop/C-small-attempt0.in","r",stdin);
    freopen("D:/Code/GCJ/2016/1B/out.txt", "w", stdout);

    int tc, ctr = 1;
    sc(tc);

    while(tc--){
        int n;
        asdf a[20];
        sc(n);
        map<string, int> mapperL, mapperR;
        map<string, bool> mL, mR;
        string x, y;
        FOR(i,n){
            cin>>a[i].x>>a[i].y;
            mapperL[a[i].x]++;
            mapperR[a[i].y]++;
            mL[a[i].x] = false;
            mR[a[i].y] = false;
            a[i].palsu = true;
        }
        FOR(i,n){
            if(mapperL[a[i].x] == 1){
                mL[a[i].x] = true;
                a[i].palsu = false;
            }
            if(mapperR[a[i].y] == 1){
                mR[a[i].y] = true;
                a[i].palsu = false;
            }
        }

        FOR(i,n){
            if(a[i].palsu || (mL[a[i].x] && mR[a[i].y]))continue;
            a[i].palsu = false;
            mL[a[i].x] = true;
            mR[a[i].y] = true;
        }

        int ct = 0;
        FOR(i,n)if(a[i].palsu)ct++;

        printf("Case #%d: %d\n", ctr++, ct);
    }





    return 0;
}


