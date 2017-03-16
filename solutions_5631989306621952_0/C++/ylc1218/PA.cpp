#include<cstdio>
#include<cstdlib>
#include<cstring>

int T;
char S[1005], ans[1005];

void dfs(int s, int e, int layer){
    if(s>e) return;

    char ch=S[s];
    int idx = s;
    for(int i=s;i<=e;i++){
        if(S[i] >= ch){
            ch = S[i];
            idx = i;
        }
    }
    ans[layer] = ch;
    dfs(s, idx-1, layer+1);

    int p = layer+(idx-s)+1;
    for(int i=idx+1;i<=e;i++){
        ans[p++] = S[i];
    }
}


int main(){
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        scanf("%s", S);
        int len = strlen(S);
        dfs(0, len-1, 0);
        ans[len] = '\0';
        printf("Case #%d: %s\n", t, ans);
    }
    return 0;
}
