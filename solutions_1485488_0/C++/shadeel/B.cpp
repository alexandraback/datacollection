#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

double cei[102][102]={0}, flo[102][102]={0};
double t[102][102];
bool inqueue[1000000];
queue<int> que;

int main(void){
    
    freopen("BS.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, c=0, h, w;
    int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
    double water;
    
    scanf("%d", &cas);
    while(cas--){
        scanf("%lf %d %d", &water, &h, &w);
        for(int i=1; i<=h; ++i)
        for(int j=1; j<=w; ++j)
            scanf("%lf", &cei[i][j]);
        for(int i=1; i<=h; ++i)
        for(int j=1; j<=w; ++j)
            scanf("%lf", &flo[i][j]);
        
        for(int i=1; i<=h; ++i)
        for(int j=1; j<=w; ++j)
            t[i][j] = 1e7;
        t[1][1] = 0;
        
        int now, nowx, nowy, tmp, tmpx, tmpy;
        double tt;
        memset(inqueue,0,sizeof(inqueue));
        while( !que.empty() ) que.pop();
        now = 1001;
        que.push(now);
        inqueue[now] = true;
        
        while( !que.empty() ){
            now = que.front();
            que.pop();
            inqueue[now] = false;
            nowx = now/1000;
            nowy = now%1000;
            tt = water - 10*t[nowx][nowy];
            
            for(int i=0; i<4; ++i){
                tmpx = nowx + dx[i];
                tmpy = nowy + dy[i];
                if( cei[tmpx][tmpy]-flo[tmpx][tmpy] >= 50 ){
                    double need, tmpwater;
                    if( cei[tmpx][tmpy] - tt >= 50 ){
                        need = 0;
                        tmpwater = tt;
                    }
                    else{
                        need = (tt+50.0-cei[tmpx][tmpy])/10.0;
                        tmpwater = cei[tmpx][tmpy]-50;
                    }
                    
                    if( tmpwater==water )   need = 0;
                    else if( tmpwater-flo[nowx][nowy]>=20 )  need += 1.0;
                    else    need += 10.0;
                    
                    if( t[tmpx][tmpy] > t[nowx][nowy]+need ){
                        t[tmpx][tmpy] = t[nowx][nowy]+need;
                        tmp = tmpx*1000+tmpy;
                        if( !inqueue[tmp] ){
                            inqueue[tmp] = true;
                            que.push(tmp);
                        }
                    }
                    
                }
            }
            
        }
        printf("Case #%d: %lf\n", ++c, t[h][w]);
    }
    
    return 0;
}
