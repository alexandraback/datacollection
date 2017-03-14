#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
#define eps 10e-7

int gcd(int a, int b){
    int x=(a>=b)?(a):(b);
    int y=(a>=b)?(b):(a);
    while( x%y ){
        int z = y;
        y = x%y;
        x = z;
    }
    return y;
}

int main(void){
    
    freopen("DBin.txt", "r", stdin);
    freopen("DBout.txt", "w", stdout);
    
    int cas, c=0, h, w, d, ans, vx, vy, pdh, ndh, pdw, ndw;
    char bo[35][35];
    double recx, recy, x, y, dis, len;
    int dx, dy;    // true:+1 , false:-1
    bool use[201][201];
    
    scanf("%d", &cas);
    while( cas-- ){
        printf("Case #%d: ", ++c);
        scanf("%d %d %d", &h, &w, &d);
        for(int i=0; i<h; ++i)
            scanf("%s", bo[i]);
        for(int i=1; i<h; ++i)
        for(int j=1; j<w; ++j)
        if( bo[i][j] == 'X' ){
            recx = 0.5 + i;
            recy = 0.5 + j;
            pdh = i - 1;
            ndh = h - 3 - pdh;
            pdw = j - 1;
            ndw = w - 3 - pdw;
        }
        
        ans = 0;
        if( pdh*2+1 <= d )  ++ans;
        if( ndh*2+1 <= d )  ++ans;
        if( pdw*2+1 <= d )  ++ans;
        if( ndw*2+1 <= d )  ++ans;
        
        memset(use,0,sizeof(use));
        for(int k=0; k<4; ++k){
            // decide the direction of vx and vy
            if( k<2 )   dx=1;
            else        dx=-1;
            if( k&1 )   dy=1;
            else        dy=-1;
        for(int i=1; ; ++i){
            if( i>=d )  break;
            for(int j=1; j*j+i*i<=d*d; ++j){
                
                int g = gcd(i,j);
                vx = i/g;   vy = j/g;
                if( use[100+dx*vx][100+dy*vy] )   continue;
                use[100+dx*vx][100+dy*vy] = true;
                
                x = recx;    y = recy;
                dis = (double)d;
                len = sqrt(vx*vx+vy*vy);
                while(1){
                    
                    double tmpx=x-0.5*((int)(2*x)), tmpy=y-0.5*((int)(2*y)), take;
                    //printf("now %lf %lf\n", tmpx, tmpy);
                    if( dx>0 )      tmpx=0.5-tmpx;
                    if( tmpx < eps )tmpx=0.5;
                    if( dy>0 )      tmpy=0.5-tmpy;
                    if( tmpy < eps )tmpy=0.5;
                    //printf("need %lf %lf\n", tmpx, tmpy);
                    
                    if( tmpx/vx < tmpy/vy ) take = tmpx/vx;
                    else                    take = tmpy/vy;
                    if( len*take > dis+eps )    break;
                    else{
                        dis -= len*take;
                        if( dx>0 )  x += take*vx;
                        else        x -= take*vx;
                        if( dy>0 )  y += take*vy;
                        else        y -= take*vy;
                    }
                    if( fabs(x-recx)<eps && fabs(y-recy)<eps ){
                        ++ans;
                        break;
                    }
                    //printf("%lf %lf %lf\n", x, y, dis);
                    tmpx=x-(int)x; tmpy=y-(int)y;
                    if( (tmpx<eps || 1-tmpx<eps) && (tmpy<eps || 1-tmpy<eps) ){
                        //puts("yes");
                        int roundx, roundy;
                        if( dx>0 )  roundx = (int)(x-eps);
                        else        roundx = (int)(x+eps);
                        if( dy>0 )  roundy = (int)(y-eps);
                        else        roundy = (int)(y+eps);
                        //printf("%d %d\n", roundx, roundy);
                        if( bo[dx+roundx][dy+roundy]=='#' ){
                            if( bo[roundx][dy+roundy]!='#' && bo[dx+roundx][roundy]!='#' )  break;
                            if( bo[roundx][dy+roundy]=='#' )   dy*=(-1);
                            if( bo[dx+roundx][roundy]=='#' )   dx*=(-1);
                        }
                    }
                    else if( tmpx>eps && 1-tmpx>eps && (tmpy<eps || 1-tmpy<eps)  ){
                        dy*=(-1);
                    }
                    else if( (tmpx<eps || 1-tmpx<eps) && tmpy>eps && 1-tmpy>eps ){
                        dx*=(-1);
                    }
                    
                }
                
                
                
            }
        }
        }
        cout << ans << endl;
    }
    
    return 0;
}
