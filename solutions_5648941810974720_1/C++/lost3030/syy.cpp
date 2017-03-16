#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
//const ll INF=(_I64_MAX)/2;
//#pragma comment(linker, "/STACK:102400000,102400000")
const int inf = 0x3f3f3f3f;
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define minn(a) memset(a, 0xC0, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define FILL(a,b) memset(a, b, sizeof(a))
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
#define fi first
#define se second
typedef pair <int, int> PII;
typedef pair <ll , ll > PX ;

string a[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int b[300];

int c[10][30];

int se[10]={0,2,6,4,5,8,9,7,3,1};

bool ok(int x) {
    int i,j;
    rep(i,26) {
        if(b[i] < c[x][i]) return 0;
    }
    return 1;
}


void work() {
    string s;
    cin>>s;
    int i,j;
    zero(b);
    rep(i,s.length()) {
        b[s[i]-'A']++;
    }

    int ans[10];
    zero(ans);
    rep(i,10){
        int x = se[i];
        while(ok(x)){
            rep(j,26){
                b[j] -= c[x][j];
            }
            ans[x]++;
        }
    }
    rep(i,10){
        while(ans[i]) {
            cout<<i;
            ans[i]--;
        }
    }
    cout<<endl;
}

int main() {
#ifdef LOCAL
    freopen( "in.txt", "r" , stdin);
 freopen ("out.txt","w",stdout );
#endif

//     int i;
//     rep(i,10){
//         cout<<a[i]<<endl;
//     }
 int i,j;
 rep(i,10) {
     rep(j,a[i].length()) {
         c[i][a[i][j]-'A']++;
     }
 }

    int T,cas=1;
    cin>>T;
    while(T--) {
        printf("Case #%d: ",cas++);
        work();
    }



    return 0;
}



