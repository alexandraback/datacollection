#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int height[3000];
int main(){
    int t;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("ans.out","w",stdout);
    scanf("%d",&t);
    for(int tt = 1; tt <= t; tt++){
        int n;
        cin>>n;
        memset(height,0,sizeof(height));
        int u;
        for(int i = 0;i < n*n*2-n ;i++){
            cin>>u;
            height[u]++;
        }
        printf("Case #%d:",tt);
        for(int i = 0;i <= 2500 ;i++){
            if(height[i] % 2 == 1) printf(" %d",i);
        }
        printf("\n");
    }
    return 0;
}
