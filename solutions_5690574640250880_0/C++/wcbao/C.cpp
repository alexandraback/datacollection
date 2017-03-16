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
int hs[10][10][100];
int R,C,M;
int sum = 0;
void print()
{
//    return ;
        for(int i = 1;i<=R;i++){
         for(int j =1;j<=C;j++){
            if(i == 1&&j ==1) printf("c");
            else printf("%c", hash[i][j]?'.':'*');
            }
            printf("\n");
        }
}

void solve()
{
    clr(hash);
    int K = R*C - M;
    if(M ==0){
        for(int i =1;i<=R;i++)
        for(int j =1;j<=C;j++)
        hash[i][j] = 1;
        print();
        return;
    }
    if(K == 1) {
        hash[1][1] = 1;
        print();
         return ;
    }
    if(R == 1){
        for(int i = 1;i<=K;i++) hash[R][i] = 1;
        print();return ;
    }
    if(C == 1){
        for(int i = 1;i<=K;i++) hash[i][C] = 1 ;
        print();return ;
    }

    for(int c = 2;c<=C;c++)
    if(K%c!=1 && K/c>=2 && K/c<=R){
        if(K>c*R) continue;
         for(int i = 1;i<=K/c;i++)
            for(int j =1;j<=c;j++)
                hash[i][j] = 1;
                if(K/c<R)
                for(int i = 1;i<=K%c;i++)
                hash[K/c+1][i] = 1;
            print();
         return ;
    }

    for(int r = 2;r<=R;r++)
    if(K%r!=1 && K/r>=2 && K/r<=C){
        if(K>C*r) continue;
         for(int i = 1;i<=K/r;i++)
            for(int j =1;j<=r;j++)
                hash[j][i] = 1;
                if(K/r<C)
                for(int i = 1;i<=K%r;i++)
                hash[i][K/r+1] = 1;
            print();
         return ;
    }

    for(int i = 2;i<K;i++)
    if(K % i == 0)
    {
        int a = i;
        int b = K / a;
        if(R>C && a<b) swap(a,b);
        if(a<=R && b <=C){
            for(int x=1;x<=a;x++)
            for(int y=1;y<=b;y++)
            hash[x][y] = 1;
            print();
            return ;
        }
    }

    for(int i = 2;i<K;i++)
    if(M % i == 0)
    {
        int a = i;
        int b = M / a;
        if(R-a!=1 && R-a>0 && C-b!=1&&C-b>0){
            for(int x=1;x<=R;x++)
            for(int y=1;y<=C;y++)
            if(!(x<=a&&y<=b)) hash[R+1-x][R+1-y] = 1;
            print();
            return ;
        }
        swap(a,b);
            if(R-a!=1 && R-a>0 && C-b!=1&&C-b>0){
            for(int x=1;x<=R;x++)
            for(int y=1;y<=C;y++)
            if(!(x<=a&&y<=b)) hash[R+1-x][R+1-y] = 1;
            print();
            return ;
        }
    }

    if(R == 4 &&C==4&&M==3)
    {
        for(int i =1;i<=R;i++)
        for(int j = 1;j<=C;j++)
        hash[i][j] =  1;
        hash[R][C] = hash[R-1][C] = hash[R][C-1] = 0;
        print();
        return ;
    }
    printf("Impossible\n");
    hs[R][C][M] = 1;
    sum++;
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
//         printf("Case #%d: %d %d %d\n",++c,R,C,M);
        solve();
    }
//    printf("%d\n",sum);
//    for(int i =1;i<=5;i++)
//    for(int j =1;j<=5;j++)
//    {
//        R = i;C = j;
//        for(int s = 0;s<R*C;s++)
//        {
//            M = s;
////           printf("\nCase #%d: %d %d %d\n",++c,R,C,M);
//            solve();
//        }
//    }
//    printf("%d\n",sum);
//    for(int i = 1;i<=5;i++)
//    for(int j =i;j<=5;j++)
//    for(int s = 0;s<i*j;s++)
//    if(hs[i][j][s]^hs[j][i][s]) printf("NO!");
    return 0;
}
