#include<stdio.h>
#include<string.h>
#include<queue>
#define siz 60
using namespace std;
char a[siz][siz];
bool ch[siz][siz], ch0[siz][siz];
struct par{
    int x, y;
    par(){}
    par(int xx, int yy){
        x=xx;y=yy;
    }
};
queue<par> myq;
int r, c, m;
void print(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
                if(i==0&&j==0)printf("c");
            else if(ch[i][j]==1)printf(".");
            else printf("*");
            //printf("%c",a[i][j]);
        }printf("\n");
    }
}
int get0(int y, int x){
    int cc=0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(y+i>=r||y+i<0||x+j>=c||x+j<0)continue;
            cc+=1-ch[y+i][x+j];
        }
    }
    return cc;
}
void func0(int y, int x){
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(y+i>=r||y+i<0||x+j>=c||x+j<0)continue;
            if(ch[y+i][x+j]==0){//printf("-%d %d\n", y+i, x+j);
                ch[y+i][x+j]=1;
                myq.push(par(x+j,y+i));
            }
        }
    }
}
bool is0(int y, int x){
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(y+i>=r||y+i<0||x+j>=c||x+j<0)continue;
            if(ch[y+i][x+j]==0)return false;
        }
    }
    return true;
}
bool check2(int y, int x){
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(y+i>=r||y+i<0||x+j>=c||x+j<0)continue;
            if(is0(y+i,x+j)){//printf("-%d %d\n", y+i, x+j);
                return true;
            }
        }
    }
    return false;
}
bool check(int y, int x){
    ch[y][x]=0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(y+i>=r||y+i<0||x+j>=c||x+j<0)continue;
            if(ch[y+i][x+j]==1){//printf("-%d %d\n", y+i, x+j);
                if(check2(y+i,x+j))continue;
                else {ch[y][x]=1;return false;}
            }
        }
    }
    return true;
}
void print2(){
    //print();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
                if(i==0&&j==0)continue;
            if(ch[i][j]==1&&!is0(i,j)&&check(i,j)){
                    //printf("%d %d\n", i, j);
                ch[i][j]=0;
                print();return ;
            }
        }
    }
    printf("Impossible\n");
}
int main(){
//    freopen("C-small-attempt4.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int t;
    bool bb=0;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++){
        int i,j , k;
        if(bb==0)scanf("%d%d%d", &r, &c, &m);
        memset(ch,0,sizeof(ch));
        memset(ch0,0,sizeof(ch0));
        k=r*c-m;
        int cc=1;
        myq.push(par(0,0));
        ch[0][0]=1;
        while(!myq.empty()){
            par t=myq.front();
//            printf("%d %d = %d  (%d)\n", t.y, t.x, cc, myq.size());
//            print();
            ch[t.y][t.x]=1;
            myq.pop();
            if(ch0[t.y][t.x]==1||cc==k)continue;
            ch0[t.y][t.x]=1;
            int ss=get0(t.y,t.x);
            if(cc+ss>k)continue;//printf(",");
            cc+=ss;
            func0(t.y,t.x);
        }
        while(!myq.empty())myq.pop();
        if(cc==k-1&&bb==0){m--;tt--;bb=1;continue;}
        printf("Case #%d:\n", tt);
        if(bb==1){bb=0;print2();continue;}
        if(cc!=k)printf("Impossible\n");
        else print();
    }
}
