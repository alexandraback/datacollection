#include<stdio.h>
int k,l,s;
char key[100],target[100],type[100];
int max=-999,sum=0,ncase=0;
void dfs(int depth){
    if(depth>=s){
        int count=0;
        for(int i=0;i<=s-l;i++){
            bool match = true;
            for(int j=0;j<l;j++){
                if(type[i+j]!=target[j]){
                    match = false;
                    break;
                }
            }
            if(match) count++;
        }
        if(count > max) max = count;
        sum += count;
        ncase++;
        return;
    }
    for(int i=0;i<k;i++){
        type[depth] = key[i];
        dfs(depth+1);
    }
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d%d%d",&k,&l,&s);
        scanf("%s%s",key,target);
        max=-999;
        sum=0;
        ncase=0;
        dfs(0);
        double ans=max - (sum*1.0/ncase);
        //printf("%d %d %d\n",max,sum,ncase);
        printf("Case #%d: %f\n",tt,ans);
    }
}
