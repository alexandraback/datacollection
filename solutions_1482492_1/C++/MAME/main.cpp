#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

const double EPS = 1.0e-6;

struct Car
{ double t; double x; };

double D;
Car c[3000];
double g[500];

void solve(int cn, int gid)
{
    // 1/2 a (t - ts)^2 のラインが
    // ts > 0 で相手をすべて飲み込むか、接するような ts を探し、
    // あとはその ts から最速で降下すればよい。
    // 相手がゴールする時間を調べる
    double t = 0;
    for(int i = 0;i < cn;++i){
        if( c[i].x >= D ){
            // ゴールした。
            // 詳細な時間を出す
            if( i <= 0 ){
                // 最初からゴールしてる
                t = 0;
                c[0].t = 0;
                c[0].x = D;
                cn = 1;
            }else{
                // 一つ前の地点からこの地点までの区間でゴールしてる
                double rem = D - c[i-1].x;
                double speed = (c[i].x - c[i-1].x)/(c[i].t - c[i-1].t);
                t = c[i-1].t + rem / speed;
                c[i].t = t;
                c[i].x = D;
                cn = i+1;
            }
            break;
        }
    }

    // (0,0) から開始して、各c点を通る ts を計算し、
    // 最初にすべての c 点を通過できた時刻を採用する

    for(int i = -1;i < cn;++i){
        Car dc;
        if( i < 0 ){
            dc.t = 0;
            dc.x = 0;
        }else{
            dc = c[i];
        }

        // dc を通るための ts はいくつ？
        double ts = dc.t - sqrt(2*dc.x/g[gid]);

        // 過去にさかのぼらなければならないようなら棄却
        if( ts < 0 - EPS ) continue;

        // cn より後の c 点をすべて回避できるならこれを採用
        bool cleared = true;
        for(int z = i+1;z < cn;++z){
            // ここへ至った時点での位置が、この点を超えてなければOK。
            // 超えてたらアウト。
            double p = 0.5 * g[gid] * (c[z].t - ts) * (c[z].t - ts);
            if( p > c[z].x ){
                cleared = false;
                break;
            }
        }

        // 採用されてたらそれが答えとなるパス
        if( cleared ){
            // かかる時間は ts + sqrt(2D/g)
            printf("%.6f\n",ts + sqrt(2 * D / g[gid]));
            break;
        }
    }

}

int main(void)
{
    int T;
    scanf("%d\n",&T);
    for(int r = 0;r < T;++r){
        printf("Case #%d: ", r+1);
        printf("\n");
        // 相手がゴールする時間がとても大事
        int N;
        int A;
        scanf("%lf %d %d\n",&D,&N,&A);
        //printf("\n%.6f %d %d\n",D,N,A);
        for(int n = 0;n < N;++n){
            scanf("%lf %lf\n",&(c[n].t),&(c[n].x));
            //printf("%.6f %.6f\n",c[n].t,c[n].x);
        }
        for(int a = 0;a < A;++a){
            scanf("%lf",&g[a]);
            //printf("%.6f ",g[a]);
            solve(N,a);
        }
    }
    return 0;
}