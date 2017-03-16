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
    freopen("C:/Users/SONY/Desktop/C-small-attempt4.in","r",stdin);
    freopen("D:/Code/GCJ/2016/1C/out.txt", "w", stdout);

    int tc, ctr = 1;
    sc(tc);

    while(tc--){
        int a, b, c, k;
        sc(a);sc(b);sc(c);sc(k);
        printf("Case #%d: ", ctr++);
        if(a == 1 && b == 1 && c == 1){
            printf("1\n1 1 1\n");
        }else if(a == 1 && b == 1 && c == 2){
            if(k == 1){
                printf("1\n1 1 1\n");
            }else{
                printf("2\n1 1 1\n1 1 2\n");
            }
        }else if(a == 1 && b == 1 && c == 3){
            if(k == 1){
                printf("1\n1 1 1\n");
            }else if(k == 2){
                printf("2\n1 1 1\n1 1 2\n");
            }else{
                printf("3\n1 1 1\n1 1 2\n1 1 3\n");
            }
        }else if(a == 1 && b == 2 && c == 2){
            if(k == 1){
                printf("2\n1 1 1\n1 2 2\n");
            }else{
                printf("4\n1 1 1\n1 1 2\n1 2 1\n1 2 2\n");
            }
        }else if(a == 1 && b == 2 && c == 3){
            if(k == 1){
                printf("2\n1 1 1\n1 2 2\n");
            }else if(k == 2){
                printf("4\n1 1 1\n1 1 2\n1 2 2\n1 2 1\n");
            }else{
                printf("6\n");
                FOR(i,a)FOR(j,b)FOR(k,c)printf("%d %d %d\n", i + 1, j + 1, k + 1);
            }
        }else if(a == 1 && b == 3 && c == 3){
            if(k == 1){
                printf("3\n1 1 1\n1 2 2\n1 3 3\n");
            }else if(k == 2){
                printf("6\n1 1 1\n1 1 2\n1 3 1\n1 3 3\n1 2 2\n1 2 3\n");
            }else{
                printf("9\n");
                FOR(i,a)FOR(j,b)FOR(k,c)printf("%d %d %d\n", i + 1, j + 1, k + 1);
            }
        }else if(a == 2 && b == 2 && c == 2){
            if(k == 1){
                printf("4\n1 1 1\n1 2 2\n2 1 2\n2 2 1\n");
            }else{
                printf("8\n");
                FOR(i,a)FOR(j,b)FOR(k,c)printf("%d %d %d\n", i + 1, j + 1, k + 1);
            }
        }else if(a == 2 && b == 2 && c == 3){
            if(k == 1){
                printf("4\n1 1 1\n1 2 2\n2 1 2\n2 2 1\n");
            }else if(k == 2){
                printf("8\n");
                printf("1 1 1\n1 1 2\n1 2 1\n1 2 2\n2 1 1\n2 1 2\n2 2 1\n2 2 2\n");
            }else{
                printf("12\n");
                FOR(i,a)FOR(j,b)FOR(k,c)printf("%d %d %d\n", i + 1, j + 1, k + 1);
            }
        }else if(a == 2 && b == 3 && c == 3){
            if(k == 1){
                printf("6\n1 1 1\n1 2 2\n1 3 3\n2 1 2\n2 2 3\n2 3 1\n");
            }else if(k == 2){
                printf("12\n1 1 1\n1 1 2\n1 2 2\n1 2 3\n1 3 1\n1 3 3\n2 1 1\n2 1 2\n2 2 2\n2 2 3\n2 3 1\n2 3 3\n");
                //printf("12\n1 1 1\n1 1 2\n1 3 1\n1 3 3\n1 2 2\n1 2 3\n2 1 1\n2 1 2\n2 3 1\n2 3 3\n2 2 2\n2 2 3\n");
            }else{
                printf("18\n");
                FOR(i,a)FOR(j,b)FOR(k,c)printf("%d %d %d\n", i + 1, j + 1, k + 1);
            }
        }else if(a == 3 && b == 3 && c == 3){
            if(k == 1){
                printf("9\n1 1 1\n2 2 2\n3 3 3\n1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
            }else if(k == 2){
                //printf("18\n1 1 1\n1 1 2\n1 3 2\n1 3 3\n2 1 1\n2 1 3\n2 2 2\n2 2 3\n2 3 1\n2 3 2\n3 1 2\n3 1 3\n3 2 1\n3 2 2\n3 3 1\n3 3 3\n");
                printf("18\n1 1 1\n1 1 2\n1 2 1\n1 2 3\n1 3 1\n1 3 3\n2 1 2\n2 1 3\n2 3 1\n2 3 2\n3 1 1\n3 1 3\n3 2 1\n3 2 2\n3 3 2\n3 3 3\n");
            }else{
                printf("27\n");
                FOR(i,a)FOR(j,b)FOR(k,c)printf("%d %d %d\n", i + 1, j + 1, k + 1);
            }
        }

    }





    return 0;
}


