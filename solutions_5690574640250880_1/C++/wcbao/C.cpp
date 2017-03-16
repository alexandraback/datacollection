#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#define mm 1000005
#define clr(A) memset(A,0,sizeof(A))
using namespace std;
typedef long long LL;
typedef pair<int,int > P;
int hash[55][55];
bool dp[52][52][2600];
int path[52][52][2600];
int R,C,M,pp=0;
int sum = 0;
char map[55][55];
void print()
{
    map[R][C] = 'c';
    for(int i = 1;i<=R;i++){
        for(int j = 1;j<=C;j++)
        printf("%c",map[i][j]);
        printf("\n");
    }
}

void getpath(int x)
{
    int rem = M,r = R;
    while(r){
//        printf("%d %d\n",x,dp[r][x][rem]);
        for(int i = 1;i<=x;i++)
        map[r][i] = '*';
        int tmp = x;
        x = path[r--][x][rem];
        rem -= tmp;
    }
    print();
}

void solve(){

        for(int i = 1;i<=R;i++)
        for(int j =1;j<=C;j++)
        map[i][j] = '.';
        map[R][C] = 'c';

    if(R*C-M == 1) {
        for(int i = 1;i<=R;i++)
        for(int j =1;j<=C;j++)
        map[i][j] = '*';
        print();
        return ;
    }

    if(R == 1){
        for(int i = 1;i<=M;i++) map[R][i] = '*';
        print();return;
    }
    if(C == 1){
        for(int i = 1;i<=M;i++) map[i][C] = '*';
        print();return;
    }

    for(int i = 0; i <=R;i++)
    for(int j = 0;j<=C;j++)
    for(int s =max(i*j,M)+1;s>=0;s--)
    {
        dp[i][j][s] = false;
        path[i][j][s] = -1;
    }
    dp[0][C][0] = true;
    for(int i = 0; i<=R;i++)
    for(int j = 0;j<=C;j++)
    {
        int up = min(i*C,M);
        for(int s =0;s<=up;s++)
        if(dp[i][j][s]){
        for(int k = 0;k<=j;k++)
        if(k!=C-1) {
            dp[i+1][k][s+k] = true;
            if(path[i+1][k][s+k] != k) path[i+1][k][s+k] = j;
        }
        }
    }
    for(int i = 0; i <=C;i++)
    if(dp[R][i][M] && path[R][i][M]==i) { getpath(i);return;}
    printf("Impossible\n");
//    sum++;
}
int main()
{
//   freopen("BUAA.in","r",stdin);
//   freopen("C.out","w",stdout);
    int T,c = 0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&R,&C,&M);
        printf("Case #%d:\n",++c);
        solve();
    }
//    printf("%d\n",sum);
    return 0;
}
