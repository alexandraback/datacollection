#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>
using namespace std;
struct XD{
    int x,y;
    int h;
    double t;
}tmp;
queue<XD> q;
int use[101][101][2001];
int cc[101][101],ff[101][101];
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int main (){
    int T,ca=0;
    int n,m,h,i,j;
    int nx,ny,nh;
    int nextx,nexty;
    double nt;
    double ans;
    scanf("%d",&T);
    while(T--){
        ca++;
        printf("Case #%d:",ca);
        memset(use,0,sizeof(use));
        scanf("%d%d%d",&h,&n,&m);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&ff[i][j]);
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&cc[i][j]);
            }
        }
        while(!q.empty())q.pop();
        tmp.t = 0;
        tmp.x = 0;
        tmp.y = 0;
        tmp.h = h;
        ans = 1e10;
        q.push(tmp);
        while(!q.empty()){
            //if(ans != 1e10)break;
            nx = q.front().x;
            ny = q.front().y;
            nh = q.front().h;
            nt = q.front().t;
            q.pop();
            for(i=0;i<4;i++){
                nextx = nx + dir[i][0];
                nexty = ny + dir[i][1];
                if(nextx < 0 || nexty < 0 || nextx >= n || nexty >= m)continue;
                if(ff[nextx][nexty] - cc[nextx][nexty] < 50)continue;
                if(ff[nextx][nexty] - cc[nx][ny] < 50)continue;
                if(ff[nx][ny] - cc[nextx][nexty] < 50)continue;
                tmp.x = nextx;
                tmp.y = nexty;
                //printf("tx %d ty %d\n",tmp.x,tmp.y);
                if(nh == h){
                    if(ff[nextx][nexty]- nh >= 50){
                        tmp.t = 0;
                        tmp.h = h;
                        if(nextx == n-1 && nexty == m-1){
                            if(tmp.t < ans)
                            ans = tmp.t;
                            //break;
                        }
                        if(use[tmp.x][tmp.y][tmp.h] == 0){
                            use[tmp.x][tmp.y][tmp.h] = 1;
                            q.push(tmp);
                        }
                    }
                }
                    if(ff[nextx][nexty] - nh < 50){
                        tmp.h = ff[nextx][nexty] - 50;
                        tmp.t = (nh - (ff[nextx][nexty] - 50)) / 10.0;
                        if(tmp.h - cc[nx][ny] >= 20){
                            tmp.h = tmp.h - 10;
                            tmp.t = tmp.t + 1;
                        }else{
                            tmp.h = tmp.h - 100;
                            if(tmp.h < 0)tmp.h = 0;
                            tmp.t = tmp.t + 10;
                        }
                        if(nextx == n-1 && nexty == m-1){
                            if(tmp.t < ans)
                            ans = tmp.t;
                            //break;
                        }
                        if(use[tmp.x][tmp.y][tmp.h] == 0){
                            use[tmp.x][tmp.y][tmp.h] = 1;
                            q.push(tmp);
                        }
                    }else{
                        if(nh - cc[nx][ny] >= 20){
                            tmp.h = nh - 10;
                            tmp.t = nt + 1;
                        }else{
                            tmp.h = nh - 100;
                            if(tmp.h < 0)tmp.h = 0;
                            tmp.t = nt + 10;
                        }
                        if(nextx == n-1 && nexty == m-1){
                            if(tmp.t < ans)
                            ans = tmp.t;
                            //break;
                        }
                        if(use[tmp.x][tmp.y][tmp.h] == 0){
                            use[tmp.x][tmp.y][tmp.h] = 1;
                            q.push(tmp);
                        }
                    }
            }
        }
        printf(" %lf\n",ans);
    }
    return 0;
}

