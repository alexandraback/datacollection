#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 110
#define sz 50
#define maxque 1000000
int i,j,n,m,h;

int p[maxn][maxn];

int q[maxn][maxn];

typedef long long int lld;

lld ans[maxn][maxn];

struct point{
        int a,b;
        lld ans;
}que[maxque];

bool cmp(point a,point b){
        return a.ans>b.ans;
}

int t;

int di[4][2]={
        1,0,
        -1,0,
        0,1,
        0,-1
};

int mymin(int a,int b){
        return a<b?a:b;
}
int mymax(int a,int b){
        return a>b?a:b;
}

bool canMove(int l,int r,int ll,int rr){
        return (mymin(r,rr)-mymax(l,ll))>=sz;
}

inline void make(){
        int i=1,t=1,x,y,xx,yy;
        que[0].a=que[0].b=1;
        que[0].ans=0;
        point now;
        int lv,ta,tb;
        while(t){
                if(t>=maxque){
                        printf("error!\n");
                        return;
                }
                now=que[0];
                pop_heap(que,que+t,cmp);
                t--;
                if(ans[now.a][now.b]>=0)
                        continue;
                ans[now.a][now.b]=now.ans;
                for(i=0;i<4;i++){
                        xx=now.a+di[i][0];
                        yy=now.b+di[i][1];

                        if(xx<1||xx>n||yy<1||yy>m){
                                continue;
                        }

                        if(ans[xx][yy]>=0)
                                continue;

                        if(h>now.ans){
                                lv=(int)(h-now.ans);
                        }else{
                                lv=0;
                        }

                        if(canMove(mymax(q[now.a][now.b],lv),p[now.a][now.b],mymax(q[xx][yy],lv),p[xx][yy])){
                                que[t].a=xx;
                                que[t].b=yy;
                                if(lv==h){
                                        que[t].ans=0;
                                }else
                                if(lv-q[now.a][now.b]>=20){
                                        que[t].ans=now.ans+10;
                                }else{
                                        que[t].ans=now.ans+100;
                                }
                                t++;
                                push_heap(que,que+t,cmp);
                        }else if (canMove(q[now.a][now.b],p[now.a][now.b],q[xx][yy],p[xx][yy])){
                                ta=mymin(p[now.a][now.b],p[xx][yy])-sz;
                                que[t].a=xx;
                                que[t].b=yy;

                                if(ta-q[now.a][now.b]>=20){
                                        que[t].ans=now.ans+10+(lv-ta);
                                }else{
                                        que[t].ans=now.ans+100+(lv-ta);
                                }
                                t++;
                                push_heap(que,que+t,cmp);
                        }
                }
        }
}

int main(){
        int ii,nn;
        scanf("%d",&nn);
        for(ii=1;ii<=nn;ii++){
                printf("Case #%d: ",ii);
                scanf("%d %d %d",&h,&n,&m);
                memset(ans,-1,sizeof(ans));
                for(i=1;i<=n;i++){
                        for(j=1;j<=m;j++){
                                scanf("%d",&p[i][j]);
                        }
                }
                for(i=1;i<=n;i++){
                        for(j=1;j<=m;j++){
                                scanf("%d",&q[i][j]);
                        }
                }
                make();
                printf("%lf\n",ans[n][m]*0.1);
                
        }
        return 0;
}
