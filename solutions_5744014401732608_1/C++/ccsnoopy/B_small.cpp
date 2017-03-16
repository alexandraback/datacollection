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

int main(void){
    freopen("C:/Users/SONY/Desktop/B-large.in","r",stdin);
    freopen("D:/Code/GCJ/2016/1C/out.txt", "w", stdout);

    int tc, ctr = 1;
    sc(tc);

    while(tc--){
        int b, m;
        sc(b);sc(m);
        printf("Case #%d: ", ctr++);
        ll maxi = pow(2, b - 2);
        if(m > maxi){printf("IMPOSSIBLE\n");continue;}
        else printf("POSSIBLE\n");
        ll selisih = maxi - m;
        //cout<<"selisih: "<<selisih<<endl;
        int arr[52][52];
        FOR(i,b){
            FOR(j,b){
                if(i<j)
                    arr[i][j] = 1;
                else arr[i][j] = 0;
            }
        }
        FOR(i,b)arr[b-1][i] = 0;

        vi kurangin;
        FOR(i,b){
            if(selisih & 1 << i){
                //cout<<"nyala: "<<i<<endl;
                arr[i+1][b-1] = 0;

            }
        }

        FOR(i,b){
            FOR(j,b){
                printf("%d", arr[i][j]);
            }
            printf("\n");
        }
        //cout<<maxi<<endl;

    }





    return 0;
}


