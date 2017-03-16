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
    int st, num, m;
}orang;

bool sort_cmp(orang a, orang b){
    return a.m < b.m;
}

int main(void){
    #ifdef ccsnoopy
        freopen("C:/Users/SONY/Desktop/C-small-1-attempt0.in", "r", stdin);
        freopen("C:/Users/SONY/Desktop/out.txt","w",stdout);
    #endif
    //to compile: g++ -o foo filename.cpp -lm -Dccsnoopy for debug.
    int tc,casecounter = 1;
    sc(tc);
    int x;
    orang orgz[3];
    while(tc--){
        sc(x);
        FOR(i,x){
            sc(orgz[i].st);sc(orgz[i].num);sc(orgz[i].m);
        }
        int jml;
        if(x == 1)jml = 0;
        else{
            sort(orgz, orgz+x,sort_cmp);
            double t = (double)orgz[0].m * orgz[0].st/360;
            double jarak = t * orgz[1].m;
            double tempuh = jarak + orgz[1].st - 360;
            if(tempuh >= 360)jml = 1;
            else jml = 0;
        }
        printf("Case #%d: %d\n",casecounter++,jml);
    }

    return 0;
}




