#include <stdio.h>
#include <memory.h>

int check(int v,int p){
    int i,j,k;
    int msk=0;
    for (i=0;i<=10;i++) for (j=i;j<=10;j++){
        k = v-i-j;
        if (k<0 || k>10) continue;
        if (k<j) continue;
        if (k-i>2) continue;
        if (k>=p){
            if (k-i==2) msk|=1;
            else msk|=2;
        }else{
            if (k-i==2) msk|=4;
            else msk|=8;
        }
    }
    return msk;
}

void solve(int cas){
    int i,j,msk;
    int N,S,p,v[110];
    int opt[110][110];
    scanf("%d %d %d",&N,&S,&p);
    for (i=0;i<N;i++) scanf("%d",v+i);
    memset(opt,0xff,sizeof(opt));
    opt[0][0]=0;
    for (i=0;i<N;i++){
        msk = check(v[i],p);
        //printf("%d:%d\n",v[i],msk);
        for (j=0;j<=S;j++){
            if (opt[i][j]<0) continue;
            if ((msk&1) && opt[i+1][j+1]<opt[i][j]+1) opt[i+1][j+1]=opt[i][j]+1; 
            if ((msk&2) && opt[i+1][j]<opt[i][j]+1) opt[i+1][j]=opt[i][j]+1; 
            if ((msk&4) && opt[i+1][j+1]<opt[i][j]) opt[i+1][j+1]=opt[i][j]; 
            if ((msk&8) && opt[i+1][j]<opt[i][j]) opt[i+1][j]=opt[i][j]; 
        }
    }
/*    for (i=0;i<=N;i++){
        for (j=0;j<=S;j++){
            printf("%4d",opt[i][j]);
        }
        printf("\n");
    }*/
    printf("Case #%d: %d\n",cas, opt[N][S]);
}

int main(){
    int T,cas;
    scanf("%d",&T);
    for (cas=1;cas<=T;cas++) solve(cas);
    return 0;
}

