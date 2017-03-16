#include<cstdio>
#include<cstdlib>
#include<vector>

const int MAXT = 100;
const int MAXN = 2831;

int num[MAXN];
int sum[MAXN];

int a[MAXT];
double ans[MAXT];
int x[MAXT];
int y[MAXT];
int la[MAXT];
int lc[MAXT];

double v[MAXN][MAXN];
int noc;

int main(int argc,char* argv[]){
    /*
    {
        int tot = 1000000;
        for (int i=0;i<10000;++i){
            tot -= i*4+1;
            if (tot<0){
                printf("%d %d\n",i,i*4+1);
                break;
            }
        }
    }
    */
    //freopen("input.txt","r",stdin);
    num[0] = 1;
    sum[0] = 1;
    for (int i=1;i<MAXN;++i){
        num[i] = i*4+1;
        sum[i] = sum[i-1]+num[i];
    }
    v[0][0] = 1;
    for (int i=1;i<MAXN;++i){
        v[i][0] = 0.5*v[i-1][0];
        for (int j=1;j<i;++j){
            v[i][j] = 0.5*(v[i-1][j]+v[i-1][j-1]);
        }
        v[i][i] = 0.5*v[i-1][i-1];
    }

    scanf("%d",&noc);
    for (int i=0;i<noc;++i){
        scanf("%d%d%d",&a[i],&x[i],&y[i]);
        for (int j=0;j<MAXN;++j){
            if (sum[j]>a[i]){
                la[i] = j;
                break;
            }
        }
        lc[i] = (((x[i]<0)?-x[i]:x[i])+y[i])/2;
        if (la[i]>lc[i]){
            ans[i] = 1.0;
        } else if (la[i]<lc[i]){
            ans[i] = 0.0;
        } else if (x[i]==0){
            ans[i] = (a[i]==sum[la[i]])?1:0;
        } else {
            ans[i] = 0;
            int tot = (la[i]==0)?a[i]:a[i]-sum[la[i]-1];
            int tmp = la[i]*2;
            for (int j=0;j<=tot;++j){
                int tt = tot-j-tmp;
                if (tt<0){
                    tt = j;
                } else {
                    tt += j;
                }
                if (tt>y[i]){
                    ans[i] = ans[i]+v[tot][j];
                }
            }
        }
        printf("Case #%d: %.20lf\n",i+1,ans[i]);
    }

    return 0;
}
