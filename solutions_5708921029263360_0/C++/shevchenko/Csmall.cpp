#include<stdio.h>

int J,P,S,K;
int n;
int idx[9][2];
int x[512];
int ans, anspath[3];
int path[3];

void dfs(int l){
    int i,j;
    if(l == J){
        for(i=0;i<n;i++){
            int v = 0;
            for(j=0;j<l;j++){
                if( (path[j] | (1<<i)) == path[j] ){
                    v++;
                }
            }
            if(v > K) return;
        }
        int sum = 0;
        for(i=0;i<l;i++) sum += x[path[i]];
        if(sum > ans){
            ans = sum;
            for(i=0;i<l;i++) anspath[i] = path[i];
        }
        return;
    }
    for(i=0;i<(1<<n);i++){
        if(x[i] == -1) continue;
        path[l] = i;
        dfs(l+1);
    }
}

void p(int J, int I){
    int i;
    for(i=0;i<n;i++){
        if( (I | (1<<i)) == I){
            printf("%d %d %d\n", J, idx[i][0], idx[i][1]);
        }
    }
}

void process(){
    int i,j,k;
    if(S <= K){
        printf("%d\n", J*P*S);
        for(i=1;i<=J;i++){
            for(j=1;j<=P;j++){
                for(k=1;k<=S;k++){
                    printf("%d %d %d\n",i,j,k);
                }
            }
        }
        return;
    }
    n = 0;
    for(i=1;i<=P;i++){
        for(j=1;j<=S;j++){
            idx[n][0] = i; idx[n][1] = j;
            n++;
        }
    }
    for(i=0;i<(1<<n);i++){
        int cnt[2][4] = {{0,},};
        x[i] = 0;
        for(j=0;j<n;j++){
            if( (i | (1<<j)) == i){
                cnt[0][idx[j][0]]++;
                cnt[1][idx[j][1]]++;
                x[i]++;
            }
        }
        for(j=1;j<=P;j++) if(cnt[0][j] > K) break;
        if(j <= P) x[i] = -1;
        for(j=1;j<=S;j++) if(cnt[1][j] > K) break;
        if(j <= S) x[i] = -1;
    }
    ans = 0;
    dfs(0);
    printf("%d\n",ans);
    for(i=0;i<J;i++){
        p(i+1, anspath[i]);
    }
}

int main(){
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d%d%d%d",&J,&P,&S,&K);
        printf("Case #%d: ",t);
        process();
    }
    return 0;
}
