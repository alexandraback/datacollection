#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T,N,flag[2505];
string S;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int casei = 1; casei <= T; ++casei){
        memset(flag,0,sizeof(flag));
        int N;
        scanf("%d",&N);
        for(int i = 0; i < 2 * N - 1; ++i){
            for(int j = 0; j < N; ++j){
                int t;
                scanf("%d",&t);
                flag[t] ^= 1;
            }
        }
        printf("Case #%d:",casei);
        for(int i = 1; i <= 2500; ++i){
            if(flag[i])
                printf(" %d",i);
        }
        printf("\n");
    }
    return 0;
}

