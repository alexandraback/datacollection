#include <cstdio>
#include <algorithm>
using namespace std;

int C[25][25];
int main () {
    for (int i=0;i<=20;++i) for (int j=0;j<=20;++j) if (i || j) {
        if (!i) C[i][j]=0;
        else if (!j) C[i][j]=C[i-1][j];
        else C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    int T;
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
    int N,X,Y;
    scanf("%d %d %d",&N,&X,&Y);
    double p=0;
    if (!X && !Y) p=1;
    if (N==1) ;
    else if (N==2) {
        if (Y==0 && (X==-2 || X==2)) p=0.5;
    }
    else if (N==3) {
        if (Y==0 && (X==-2 || X==2)) p=3.0/4;
        else if (Y==1 && (X==1 || X==-1)) p=1.0/4;
    }
    else if (N==4) {
        if (Y==0 && X>=-2 && X<=2) p=1;
        else if (Y==1 && (X==1 || X==-1)) p=0.5;
    }
    else if (N==5) {
        if (Y==0 && X>=-2 && X<=2) p=1;
        else if (Y==1 && X>=-1 && X<=1) p=1;
    }
    else if (N==6) {
        if (Y==0 && X>=-2 && X<=2) p=1;
        else if (Y==1 && X>=-1 && X<=1) p=1;
        else if (Y==2 && X==0) p=1;
    }
    else {
        if (Y==0 && X>=-2 && X<=2) p=1;
        else if (Y==1 && X>=-1 && X<=1) p=1;
        else if (Y==2 && X==0) p=1;
        else {
            int l=1,r=N;
            while (l<r) {
                int m=(l+r)/2;
                int sz=2*m*m-m;
                if (sz<=N) l=m+1;
                else r=m;
            }
            int k=l;
            int n = 2*k*k-k-N;
            if (X+Y<=k-2 && X-Y>=-k+2) p=1;
            else if (X+Y==k-1 && X-Y>=-k+1 || X-Y==-k+1 && X+Y<=k-2) {
                int m = min(n,2*k-1);
                double tot=0;
                for (int h=X+1;h<=m;++h) {
                    tot+=C[n][h];
                }
                tot/=(1<<n);
                p=tot;
                printf("Here\n");
            }
        }
    }
    printf("Case #%d: %lf\n",z,p);
}
    return 0;
}
