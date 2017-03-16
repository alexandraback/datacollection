#include<stdio.h>
#define N 105

int pan[N][N];
int n,m;

int is_ok(int r, int c){
    int i;

    //row test...
    for(i=0;i<m;i++){
        if(pan[r][i]>pan[r][c])
            break;
    }
    if(i==m)
        return 1;

    //col test...
    for(i=0;i<n;i++){
        if(pan[i][c]>pan[r][c])
            break;
    }
    if(i==n)
        return 1;

    return 0;

}

int solve(void){
    int i,j;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(is_ok(i,j)==0)
                return 0;
        }
    }

    return 1;

}

int main(void){
    int t,i,j,k;

    FILE *in,*out;
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");

    fscanf(in,"%d",&t);
    for(i=1;i<=t;i++){
        fscanf(in,"%d %d",&n,&m);
        for(j=0;j<n;j++){
            for(k=0;k<m;k++){
                fscanf(in,"%d",&pan[j][k]);
            }
        }

        j=solve();
        if(j==0){
            fprintf(out,"Case #%d: NO\n",i);
        }else{
            fprintf(out,"Case #%d: YES\n",i);
        }
    }

    return 0;
}
