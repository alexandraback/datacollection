#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 35
int col[maxn],mask[maxn],f[maxn];
int ans;
int C,D,V;
void dfs(int cur, int cnt, int sum){
    int i,j;
    int ut,hav[maxn];
    if (sum == V){
        ans = min(ans, cnt);
        return ;
    }
    if (cnt >= ans) return ;
    if (cur > V) return ;
    if (mask[cur] == 1){
        dfs(cur + 1, cnt, sum);
        return ;
    }
    
    ut=0;
    for (j = V; j>=0; j--)
        if (j-cur >=0 && f[j-cur] == 1 && f[j] == 0){
            f[j] = 1;
            hav[ut++] = j;
        }
    dfs(cur + 1, cnt + 1, sum + ut);
    for (i = 0; i < ut; i++)
        f[hav[i]] = 0;
    dfs(cur + 1, cnt, sum);
}
    
        
        
    
int main(){
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-small-attempt2.out","w",stdout);
    int N;
    int t,cas,i,j;
    scanf("%d",&N);
    for (cas=1;cas<=N;cas++){
        scanf("%d%d%d",&C,&D,&V);
        memset(mask, 0, sizeof(mask));
        for (i = 0; i < D; i++)
            scanf("%d", &col[i]), mask[col[i]]  = 1;
        memset(f,0,sizeof(f));
        f[0] = 1;
        for (j = 0; j < D; j++){
        	for (i  = V; i > 0; i--){
            	if (i - col[j] >= 0 && f[i - col[j]] == 1)
                	f[i] = 1;
        	}
        }
        int sum = 0;
        for (i = 1; i <= V; i++)
        if (f[i]==1) sum ++;
        ans = V;
        dfs(1, 0, sum);
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}

