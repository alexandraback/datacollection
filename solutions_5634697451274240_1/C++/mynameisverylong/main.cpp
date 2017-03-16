#include <stdio.h>

char s[110];
long f[110][110][2][2],l;

long findans(long x,long y,long k1,long k2){
    if (f[x][y][k1][k2]!=-1)
        return f[x][y][k1][k2];
    else {
        long i,j;
        if (k1==0){
            for (j=y;j>=x;j--)
                if (s[j]!=k2)
                    break;
            if (j<x){
                f[x][y][k1][k2]=0;
                return 0;
            }
            if (j<y){
                f[x][y][k1][k2]=findans(x, j, k1,k2);
                return f[x][y][k1][k2];
            }
            f[x][y][k1][k2]=10000;
            for (i=x;i<y;i++){
                j=findans(x, i, k1, 1-k2)+findans(i+1, y, 1-k1 ,1-k2)+1;
                if (j<f[x][y][k1][k2])
                    f[x][y][k1][k2]=j;
            }
            return f[x][y][k1][k2];
        }
        else {
            for (j=x;j<=y;j++)
                if (s[j]!=k2)
                    break;
            if (j>y){
                f[x][y][k1][k2]=0;
                return 0;
            }
            if (j>x) {
                f[x][y][k1][k2]=findans(j, y, k1, k2);
                return f[x][y][k1][k2];
            }
            f[x][y][k1][k2]=10000;
            for (i=y;i>x;i--){
                j=findans(i, y, k1, 1-k2)+findans(x, i-1, 1-k1, 1-k2)+1;
                if (j<f[x][y][k1][k2])
                    f[x][y][k1][k2]=j;
            }
            return f[x][y][k1][k2];
        }
    }
}

int main() {
    long i,j,t,tt;
    freopen("B-large.in.txt", "r", stdin);
    freopen("B-large.out.txt", "w", stdout);
    scanf("%ld",&t);
    for (tt=1;tt<=t;tt++){
        scanf("%s",s);
        for (l=0;s[l];l++);
        for (i=0;i<l;i++){
            for (j=0;j<l;j++){
                f[i][j][0][0]=-1;
                f[i][j][1][0]=-1;
                f[i][j][0][1]=-1;
                f[i][j][1][1]=-1;
            }
            if (s[i]=='+'){
                f[i][i][0][0]=0;
                f[i][i][1][0]=0;
                f[i][i][0][1]=1;
                f[i][i][1][1]=1;
            }
            else {
                f[i][i][0][0]=1;
                f[i][i][1][0]=1;
                f[i][i][0][1]=0;
                f[i][i][1][1]=0;
            }
        }
        for (i=0;i<l;i++)
            if (s[i]=='+')
                s[i]=0;
            else
                s[i]=1;
        printf("Case #%ld: %ld\n",tt,findans(0,l-1,0,0));
    }
    return 0;
}
