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
    #ifdef ccsnoopy
        freopen("C:/Users/SONY/Desktop/a.txt", "r", stdin);
        freopen("C:/Users/SONY/Desktop/out.txt","w",stdout);
    #endif
    //to compile: g++ -o foo filename.cpp -lm -Dccsnoopy for debug.
    int tc,casecounter = 1;
    queue<int> q;
    q.push(1);
    int dist[1000010];
    FOR(i,1000002){
        dist[i] = INF;
    }
    dist[1] = 1;
    while(!q.empty()){
        int y = q.front();
        q.pop();
        if(y+1 <= 1000000 && dist[y+1]>dist[y]+1){
            dist[y+1] = dist[y] + 1;
            q.push(y+1);
        }
        int temp = y;
        int tot = 0;
        while(y){
            tot = tot*10 + y%10;
            y/=10;
        }
        if(tot <= 1000000 && dist[tot] > dist[temp]+1){
            dist[tot] = dist[temp] + 1;
            q.push(tot);
        }
    }

    sc(tc);
    int x;
    while(tc--){
        sc(x);
        printf("Case #%d: %d\n",casecounter++,dist[x]);
    }

    return 0;
}



