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
    freopen("C:/Users/SONY/Desktop/B-small-attempt1.in","r",stdin);
    freopen("D:/Code/GCJ/2016/1B/out3.txt", "w", stdout);
    int pw[] = {1, 10, 100, 1000};
    int tc, ctr = 1;
    sc(tc);

    while(tc--){
        char str[2][30];
        scanf("%s", str[0]);
        scanf("%s", str[1]);
        int len = strlen(str[0]);
        int diff = INF;
        int min1, min2;
        int sum1, sum2;
        sum1 = sum2 = 0;
        FOR(i,len){
            if(str[0][i] == '?')sum1 = sum1 * 10;
            else sum1 = sum1*10 + str[0][i] - '0';
            if(str[1][i] == '?')sum2 = sum2 * 10;
            else sum2 = sum2 * 10 + str[1][i] - '0';
        }
        min1 = sum1;
        min2 = sum2;
        diff = abs(sum1-sum2);

        FOR(i,pw[len]){
            FOR(j,pw[len]){
                int sum1, sum2;
                bool valid = true;
                sum1 = 0;
                sum2 = 0;
                FOR(k,len){
                    sum1 = (i/(pw[len-k-1]))%10;
                    sum2 = (j/(pw[len-k-1]))%10;
                    if(str[0][k] != '?' && str[0][k] - '0' != sum1)valid = false;
                    if(str[1][k] != '?' && str[1][k] - '0' != sum2)valid = false;
                }
                if(valid){
                    if(diff > abs(i-j)){
                        diff = abs(i-j);
                        min1 = i;min2 = j;
                    }
                }
            }
        }
        printf("Case #%d: ", ctr++);
        cout<<setfill('0')<<setw(len)<<min1;
        cout<<" ";
        cout<<setfill('0')<<setw(len)<<min2;
        cout<<endl;
    }





    return 0;
}



