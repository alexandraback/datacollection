#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

const double EPS = 1.0e-6f;
const double EPEPS = 1.0e-9f;

struct Seg{ double fx; double fy; double tx; double ty; int isTate; };

Seg seg[40*40*4];
int segNum = 0;

int hit[200][200];

int& getHit(int gx,int gy){
    return hit[gx + 100][gy + 100];
}

void setHit(int gx,int gy){
    getHit(gx,gy) = 1;
}

bool hasHit(int gx,int gy){
    return getHit(gx,gy) > 0;
}

int sign(double f,double eps=EPS){
    if( f >= eps ) return 1;
    if( f <= -eps ) return -1;
    return 0;
}

int round(double f){ return (int)(sign(f) * (abs(f) + 0.5f)); }
double fround(double f){ return round( f * 1.0e+6 ) * EPS; }

bool isSame(double a, double b, double eps = EPS){
    return sign(a-b,eps) == 0;
}

bool isZero(double a){ return isSame(a,0); }

bool isSame(double ax, double ay, double bx, double by, double eps = EPS){
    return isSame(ax,bx,eps) && isSame(ay,by,eps);
}

double getDD(double ax, double ay, double bx, double by){
    const double dx = ax - bx;
    const double dy = ay - by;
    return dx*dx + dy*dy;
}

double getDD(double x,double y){ return getDD(x,y,0,0); }

double getSqrtDD(double ax, double ay, double bx, double by){
    return sqrt(getDD(ax,ay,bx,by));
}

double getDot(double ax, double ay, double bx, double by){
    return ax*bx + ay*by;
}

double getCross(double ax,double ay,double bx,double by){
    return ax * by - ay * bx;
}

// ベクトルが平行かつ同じ方向を向いているか
bool isSameDir(double ax, double ay, double bx, double by){
    // 内積が正で、かつ、内積の２乗が距離の積の二乗と等しいなら全く同じ方向を向いている
    ax = fround(ax);
    ay = fround(ay);
    bx = fround(bx);
    by = fround(by);
    const double dot = getDot(ax,ay,bx,by);
    return sign(dot) > 0 && isSame( dot*dot, getDD(ax,ay) * getDD(bx,by), EPEPS );
}

// ベクトルが同じ方向を指しているか。平行でなくてもいい。
bool isLikeDir(double ax, double ay, double bx, double by){
    return sign( getDot(ax,ay,bx,by) ) >= 0;
}

// レイとセグメントの衝突判定
bool isColSeg(double tx, double ty, double dx, double dy, Seg& s, double& rayR, double& segR, double& cx, double& cy){
    // レイの始点からセグメント始点へのベクトル
    double vx,vy;
    vx = s.fx - tx;
    vy = s.fy - ty;

    double sdx = s.tx - s.fx;
    double sdy = s.ty - s.fy;

    // レイとセグメントの外積
    double crossRaySeg = getCross(dx,dy,sdx,sdy);
    // レイとセグメントが平行ならそもそも衝突しない
    if( isZero(crossRaySeg) ){ return false; }

    double crossVRay = getCross(vx,vy,dx,dy);
    double crossVSeg = getCross(vx,vy,sdx,sdy);
    double t1 = crossVSeg / crossRaySeg;
    double t2 = crossVRay / crossRaySeg;
    rayR = t1;
    segR = t2;
    // 交差点が線分外にある場合は交差なしと返答
    if( t1 + EPS < 0 || t1 - EPS > 1 || t2 + EPS < 0 || t2 - EPS > 1 ){
        return false;
    }
    // 本当に線分内で交差する場合のみ交点を計算
    cx = tx + dx * t1;
    cy = ty + dy * t1;
    // まじわるね。まちがいなくまじわるね。
    return true;
}

// セグメント端点と点の衝突
bool isSegOn( Seg& s, double x, double y ){
    return isSame(s.fx,s.fy,x,y) || isSame(s.tx,s.ty,x,y);
}

void dumpHit(int D,int px, int py){
#if 0
    for(int iy = -D;iy <= D;++iy){
        if( iy == 0 ){ for(int ix = -D;ix <= D + 2;++ix){ printf("　"); } printf("\n"); }
        for(int ix = -D;ix <= D;++ix){
            if( hasHit(px+ix,py+iy) ){
                printf("%s■%s",ix==0?"　":"",ix==0?"　":"");
            }else{
                printf("%s□%s",ix==0?"　":"",ix==0?"　":"");
            }
        }printf("\n");
        if( iy == 0 ){ for(int ix = -D;ix <= D + 2;++ix){ printf("　"); } printf("\n"); }
    }printf("\n");
#endif
}

enum CellType {
    C_E
    , C_W
    , C_P
};

int toType( char c )
{
    switch(c)
    {
    case '.': return C_E;
    case '#': return C_W;
    case 'X': return C_P;
    }
    return C_W;
}

int main(void)
{
    int T;
    scanf("%d\n",&T);
    for(int r = 0;r < T;++r){
        printf("Case #%d: ",r+1);
        int H,W,D;
        int ans = 0;
        scanf("%d %d %d\n",&H,&W,&D);
        // フィールド情報を収集
        // あとで X を原点とするために全体をシフトする必要がある要注意。
        int map[50][50];
        int px,py;
        for(int y = 0;y < H;++y){
            for(int x = 0;x < W;++x){
                char c;
                do{ scanf("%c",&c); }while( c == '\n' );
                map[x][y] = toType(c);
                if(map[x][y] == C_P){
                    px = x;
                    py = y;
                }
            }
        }

        // セグメントのリストを作る
        segNum = 0;
        for(int y = 1;y < H;++y){
            for(int x = 1;x < W;++x){
                if( map[x][y] != C_W ){
                    // 空間の上下左右に壁があれば、そこをセグメントとして登録
                    int v[] = {0,-1, 1,0, 0,1, -1,0};
                    bool tate[] = {false, true, false, true};
                    for(int i = 0;i < 4;++i){
                        int vx = v[i*2+0];
                        int vy = v[i*2+1];
                        if( map[x+vx][y+vy] == C_W ){
                            // セグメントを形成する
                            int nvx = -vy;
                            int nvy = vx;
                            seg[segNum].fx = (double)x + 0.5f * vx - 0.5f * nvx;
                            seg[segNum].fy = (double)y + 0.5f * vy - 0.5f * nvy;
                            seg[segNum].tx = seg[segNum].fx + nvx;
                            seg[segNum].ty = seg[segNum].fy + nvy;
                            seg[segNum].isTate = tate[i];
                            //printf("(%.2f,%.2f)-(%.2f,%.2f)\n",seg[segNum].fx,seg[segNum].fy,seg[segNum].tx,seg[segNum].ty);
                            ++segNum;
                        }
                    }
                }
            }
        }

        // セグメントへのヒットと自分へのヒットの距離を比較して、
        // 自分へのヒットの方が近ければ、ヒット確定。
        
        // 自分を原点として [-D,D] の範囲を距離１で離散的にしらみつぶしに調べる。
        // たぶん間に合う。
        // 自分にヒットした位置。
        for(int i = 0;i < 200;++i){
            memset(&hit[i],0,sizeof(int)*200);
        }
        for(int ilnx = -D;ilnx <= D;++ilnx){
            for(int ilny = -D;ilny <= D;++ilny){
                //if( ilnx == 5 && ilny == -1 ){
                //    printf("debug\n");
                //}
                double gnx = (double)(ilnx + px);
                double gny = (double)(ilny + py);
                // X 自身の場所は見なくていい
                if( ilnx == 0 && ilny == 0 ) continue;
                // すでにヒットしてるならもう見なくていい
                if( hasHit(gnx,gny) ) continue;
                // X から (gnx,gny) にレイを飛ばす
                double dx = (double)(ilnx);
                double dy = (double)(ilny);
                double dd = getDD(dx,dy);
                // 遠すぎる点は狙わない
                if( dd > D*D ) continue;
                // 移動ベクトルを計算
                double d = sqrt(dd);
                //dx = dx / d;
                //dy = dy / d;
                // X から移動ベクトル方向にぽつぽつ移動する
                double tx = px + dx / d * 0.25f;
                double ty = py + dy / d * 0.25f;
                double remD = d - 0.25f;
                while(true){

                    // 今のレイ R(=(tx,ty)+r(dx,dy)) は X と衝突するか
                    double tgx = px - tx;
                    double tgy = py - ty;
                    double hitDD = 200 * 200;
                    if( isSameDir(dx,dy,px-tx,py-ty) ){
                        // ヒットしそう。距離は？
                        hitDD = getDD(px,py,tx,ty);
                    }

                    // 今のレイから、最短で衝突するセグメントを見つける
                    double segDD = 200 * 200;
                    int nnSegID = -1;
                    double segR = 0;
                    double cx,cy;
                    double tempCx, tempCy;
                    for(int z = 0;z < segNum;++z){
                        double dr;
                        double tempSR;
                        Seg& s = seg[z];
                        if( isColSeg(tx,ty,dx,dy,s,dr,tempSR,tempCx,tempCy) ){
                            // 交差を見つけた。
                            // より近い？
                            // でも零距離での交差は無視。
                            double tDD = getDD(tx,ty,tempCx,tempCy);
                            if( tDD < segDD && !isSame( tDD, EPEPS ) ){
                                segDD = tDD;
                                nnSegID = z;
                                segR = tempSR;
                                cx = tempCx;
                                cy = tempCy;
                            }
                        }
                    }

                    // 最短衝突セグメントよりも近くでXと衝突してたら
                    // 衝突を確定させる
                    if( hitDD < segDD ){
                        // 距離足りる？
                        double segD = sqrt(hitDD);
                        if( segD > remD + EPS ){
                            // 霧に飲み込まれた
                            break;
                        }else{
                            // おめでとう
                            // 移動距離から到達地点を計算する。
                            // 思ったより早くXに到達するケースをカバーするため。
                            remD -= segD;
                            double moveD = d - remD;
                            int ax = round(px + (double)ilnx * moveD / d);
                            int ay = round(py + (double)ilny * moveD / d);
                            if( hasHit( ax, ay ) == false ){
                                setHit( ax, ay );
                                //printf("setHit:L(%d,%d) -> (%d,%d) -> (%d,%d)\n",ilnx,ilny,(int)(ilnx*moveD/d),(int)(ilny*moveD/d),ax,ay);
                                dumpHit(D,px,py);
                                ++ans;
                            }
                        }
                        break;
                    }

                    // セグメントに当てる
                    // セグメントへの距離が残り移動距離を超えてたら
                    // 何にもヒットせず霧の中に消えてしまう。
                    double segD = sqrt(segDD);
                    if( segD >= remD ){
                        // 霧の中に消えた
                        break;
                    }

                    // まだ消えない。
                    // 残り距離を減らす。
                    remD -= segD;

                    // いよいよセグメントに衝突。
                    // カド当たりか否かを確認。
                    if( isSame(segR,0) || isSame(segR,1) ){
                        // セグメントのカドに当たってる。
                        // 光が消滅するか否かを判定。
                        // (cx,cy) にくっついているセグメントが何本かでまずざっくりわける。
                        // 4 -> 挟まれたところを華麗に通り抜けるパターン
                        // 2 -> 壊れるか、反射するか、通り抜けるかの分かれ目
                        //      a. 縦縦または横横なら１枚の巨大なミラーとみたてて反射
                        //      b. ２本とも自分の側にセグメントがあるならXY反射
                        //      c. １本だけ自分の側にセグメントがあるなら通り抜け
                        //      d. それ以外なら消滅

                        // (cx,cy) にくっついているセグメントを列挙
                        int id[8];
                        int idNum = 0;
                        for(int z = 0;z < segNum;++z){
                            if( isSegOn( seg[z], cx, cy ) ){
                                id[ idNum++ ] = z;
                            }
                        }

                        if( idNum == 4 ){
                            // 華麗にスルー
                        }else{
                            if( idNum != 2 ){
                                //printf("invalid case!!\n");
                            }else{
                                // 巨大な１枚ミラーと判定できるか確認
                                Seg& s1 = seg[id[0]];
                                Seg& s2 = seg[id[1]];
                                if( s1.isTate && s2.isTate ){
                                    // 縦縦の巨大なミラー
                                    dx = -dx;
                                }else if( !(s1.isTate) && !(s2.isTate) ){
                                    // 横横の巨大なミラー
                                    dy = -dy;
                                }else{
                                    // XY反射、スルー、消滅の判定。
                                    // 鏡が自分側にあるか、向こう側にあるかで判定可能。
                                    // 自分側を表すベクトル
                                    double ctx = -dx;
                                    double cty = -dy;
                                    double csx,csy;
                                    if( !isSame(s1.fx,s1.fy,cx,cy) ){
                                        csx = s1.fx - cx;
                                        csy = s1.fy - cy;
                                    }else{
                                        csx = s1.tx - cx;
                                        csy = s1.ty - cy;
                                    }
                                    int likeDirNum = 0;
                                    if( isLikeDir(ctx,cty,csx,csy) ){ ++likeDirNum; }
                                    if( !isSame(s2.fx,s2.fy,cx,cy) ){
                                        csx = s2.fx - cx;
                                        csy = s2.fy - cy;
                                    }else{
                                        csx = s2.tx - cx;
                                        csy = s2.ty - cy;
                                    }
                                    if( isLikeDir(ctx,cty,csx,csy) ){ ++likeDirNum; }
                                    if( likeDirNum == 2 ){
                                        // 完全反射
                                        dx = -dx;
                                        dy = -dy;
                                    }else if( likeDirNum == 1 ){
                                        // そのままスルー
                                    }else{
                                        // 壊れちゃった
                                        break;
                                    }
                                }
                            }
                        }
                    }else{
                        // セグメントのカドでないところに当たった。
                        // 縦セグメントか横セグメントかを確かめて
                        // 反射させるだけ。
                        if( seg[nnSegID].isTate ){
                            dx = -dx;
                        }else{
                            dy = -dy;
                        }
                    }
                    // 移動
                    tx = cx + dx / d * .0f;
                    ty = cy + dy / d * .0f;
                    remD -= .0f;
                }
            }
        }
        printf("%d\n",ans);
        dumpHit(D,px,py);
    }
    return 0;
}