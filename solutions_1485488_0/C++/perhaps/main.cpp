#include<stdio.h>
int floor[200][200], ceil[200][200];
double f[200][200];
double maxt=1e10;
int x[100000],y[100000];
int s,t,h,n,m;
FILE *inf, *outf;

bool inside(int nowx,int nowy){
    if(nowx>=n || nowx<0) return false;
    if(nowy>=m || nowy<0) return false;
    return true;
}

void update(int nowx,int nowy,double v){
    if (v>maxt-1) return;
    if (f[nowx][nowy]==-1 ||f[nowx][nowy]>v){
        f[nowx][nowy]=v;
        x[t]=nowx;
        y[t]=nowy;
        t++;
    }
}

double move(int nowx, int nowy, int nextx, int nexty, double t){
    double nowh = (double)h-t*10.0;
    if (floor[nextx][nexty]>ceil[nowx][nowy]-50) return maxt;
    if (floor[nextx][nexty]>ceil[nextx][nexty]-50) return maxt;
    if (ceil[nextx][nexty]<floor[nowx][nowy]+50) return maxt;
    double waittime = 0;
    if(nowh>ceil[nextx][nexty]-50)
        waittime = (nowh - (double)(ceil[nextx][nexty]-50)) / 10.0;
    nowh = nowh - waittime*10.0;
    double usetime =1.0;
    if (floor[nowx][nowy]+20>nowh) usetime =10.0;
    if (waittime <1e-9 && t<1e-9) return 0;
    return t+waittime+usetime;
}

void expand(int nowx, int nowy){
    if (inside(nowx-1,nowy))
        update(nowx-1,nowy, move(nowx,nowy,nowx-1,nowy,f[nowx][nowy]));
    if (inside(nowx+1,nowy))
        update(nowx+1,nowy, move(nowx,nowy,nowx+1,nowy,f[nowx][nowy]));
    if (inside(nowx,nowy-1))
        update(nowx,nowy-1, move(nowx,nowy,nowx,nowy-1,f[nowx][nowy]));
    if (inside(nowx,nowy+1))
        update(nowx,nowy+1, move(nowx,nowy,nowx,nowy+1,f[nowx][nowy]));
}

int main(){
    outf = fopen("b.out","w");
    inf = fopen("b.in","r");

    int ii,nn,i,j;
    fscanf(inf,"%d",&nn);
    for (ii=0;ii<nn;ii++){
        fscanf(inf,"%d %d %d",&h, &n, &m);
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                fscanf(inf,"%d",&ceil[i][j]);
        for (i=0;i<n;i++)
            for (j=0;j<m;j++){
                fscanf(inf,"%d",&floor[i][j]);
                f[i][j]=-1;
            }
        x[0]=0; y[0]=0; s=0; t=1;
        f[0][0]=0;
        while (s<t){
            int nowx = x[s];
            int nowy = y[s];
            s++;
            expand(nowx,nowy);
        }
        for (i=0;i<n;i++){
            for (j=0;j<m;j++)
                printf("%.2lf ", f[i][j]);
            printf("\n");
        }
        fprintf(outf,"Case #%d: %.6lf\n",ii+1,f[n-1][m-1]);
    }
    fclose(outf);
    fclose(inf);
}
