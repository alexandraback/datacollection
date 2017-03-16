#include<stdio.h>

int n;
int bff[1000];
int indeg[1000], maxdepth[1000];

void process(){
    int i, j;
    for(i=0;i<n;i++){ indeg[i]=0; maxdepth[i] = 1; }

    for(i=0;i<n;i++) indeg[bff[i]]++;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(indeg[j] == 0){
                indeg[j] = -1;
                indeg[bff[j]]--;
                if(maxdepth[bff[j]] < maxdepth[j] + 1){
                    maxdepth[bff[j]] = maxdepth[j] + 1;
                }
            }
        }
    }

    int ans = 0, ans1 = 0, ans2 = 0;
    for(i=0;i<n;i++){
        if(indeg[i] != -1){
            int x = i, cnt = 0;
            while(1){
                indeg[x] = -1;
                cnt++;
                x = bff[x];
                if(x == i) break;
            }
            if(cnt == 2){
                ans1 += maxdepth[i] + maxdepth[bff[i]];
            }
            else{
                if(cnt > ans2) ans2 = cnt;
            }
        }
    }

    ans = ans1;
    if(ans2 > ans) ans = ans2;
    printf("%d\n",ans);
}

int main(){
    int T, t;
    int i;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&n);
        for(i=0;i<n;i++){ scanf("%d",&bff[i]); bff[i]--; }
        printf("Case #%d: ", t);
        process();
    }
    return 0;
}
