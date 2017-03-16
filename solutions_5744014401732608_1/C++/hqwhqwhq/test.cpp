#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <int,int > PII;
#define FOR(i,x,y)  for(int i = x;i < y;++ i)
#define IFOR(i,x,y) for(int i = x;i > y;-- i)
#define pb  push_back
#define mp  make_pair
#define fi  first
#define se  second

const int maxn = 55;
int a[40];
int matrix[maxn][maxn];

void work(){
    int n;
    LL m;
    scanf("%d%I64d",&n,&m);
    int wei = 0;
    while(m){
        a[wei++] = m%2;
        m >>= 1;
    }   
    if(wei > n-1)   {printf("IMPOSSIBLE\n");return;}
    else if(wei == n-1){
        bool flag = true;
        FOR(i,0,wei-1)    if(a[i])  {flag = false;break;} 
        if(!flag)   {printf("IMPOSSIBLE\n");return;}
        else{
            printf("POSSIBLE\n");
            FOR(i,0,n)  FOR(j,0,n)  matrix[i][j] = 0;
            FOR(i,0,n)  FOR(j,i+1,n)    matrix[i][j] = 1;
            FOR(i,0,n){  
                FOR(j,0,n)  printf("%d",matrix[i][j]);
                printf("\n");
            }
        }
        return;
    }
    else    {printf("POSSIBLE\n");}
    FOR(i,0,n)  FOR(j,0,n)  matrix[i][j] = 0;
    FOR(i,1,n)  FOR(j,i+1,n)    matrix[i][j] = 1;
    FOR(i,0,wei)    if(a[i])  matrix[0][n-2-i] = 1;
    FOR(i,0,n){  
        FOR(j,0,n)  printf("%d",matrix[i][j]);
        printf("\n");
    }
}

int main(){
    //freopen("B-large.in","r",stdin);
    //freopen("B_1.out","w",stdout);
    int T,tCase = 0;    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++tCase);
        work();
    }
    return 0;
}
