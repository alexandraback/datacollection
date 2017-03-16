#include<bits/stdc++.h>
using namespace std;
#define NSIZ 110
#define mxint (-1u/2)
#define mxll (-1ull/2)
#define F first
#define S second
typedef pair<int,int> pii;

int n, o, re=0;
long long m;
int a[NSIZ][NSIZ], b[NSIZ];
bool chk[NSIZ];
int main(){
    int i, j, k, l;
    int test;
    scanf("%d", &test);
    for(int zz=1; zz<=test; zz++){
        scanf("%d %lld", &n, &m);
        memset(a,0,sizeof(a));
        printf("Case #%d: ", zz);
        m=(1LL<<(n-2))-m;
        printf("=%lld ", m);
        if(m<0){
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(i=1; i<n; i++){
            for(j=i+1; j<=n; j++){
                a[i][j]=1;
            }
        }
        long long ss=1;
        for(i=2; ss<=m; ss*=2,i++){
                printf("%d %lld %lld\n", i, ss, m);
            if((ss&m)>0){
                a[i][n]=0;
            }
        }
        printf("POSSIBLE\n");
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                printf("%d", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
