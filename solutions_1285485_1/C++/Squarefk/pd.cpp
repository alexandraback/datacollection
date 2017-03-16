#include <cstdio>
#include <cstring>

using namespace std;

bool oo[55][55][2],same[55][55][4];
int list[220];
int n,m,d,dx,dy,sx,sy,ans,top,times;
char data[33][33];

int cj(int x1,int y1,int x2,int y2)
{
    return x1*y2-x2*y1;    
}

bool xj(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
     if (cj(x3-x1,y3-y1,x4-x1,y4-y1)*
        cj(x3-x2,y3-y2,x4-x2,y4-y2)>0) return false;
     if (cj(x1-x3,y1-y3,x2-x3,y2-y3)*
        cj(x1-x4,y1-y4,x2-x4,y2-y4)>0) return false;
     return true;
}

int gcd(int x,int y)
{
    if (!y) return x;
    return gcd(y,x%y);
}

void work1(int x,int y,int kind)
{
     int tttt=gcd(x,y);
     if (same[x/tttt][y/tttt][kind]) return;
     memset(oo,0,sizeof(oo));
     top=0;
     for (int i=0;i<=x;++i)
         for (int j=0;j<=y;++j){
             if (xj((i+i+1),(j+j-1),(i+i+1),(j+j+1),0,0,x+x,y+y))
                oo[i][j][0]=true;
             if (xj((i+i-1),(j+j+1),(i+i+1),(j+j+1),0,0,x+x,y+y))
                oo[i][j][1]=true;
         }
     int xx=0,yy=0;
     while (!((xx==x)&&(yy==y))){
           if ((oo[xx][yy][0])&&(oo[xx][yy][1])) list[++top]=3,++xx,++yy;
           else if (oo[xx][yy][0]) list[++top]=1,++xx;
           else if (oo[xx][yy][1]) list[++top]=2,++yy;
     }
}

void work2(int xxx,int yyy,int kind)
{
    int tttt=gcd(xxx,yyy);
    if (same[xxx/tttt][yyy/tttt][kind]) return;
    int x=sx,y=sy;
    for (int i=1;i<=top;++i)
    {
        if (list[i]==3){
           int xx=x+dx,yy=y+dy;
           if (data[xx][yy]=='.') x=xx,y=yy;
           else if (data[x][yy]=='.') y=yy,dx=-dx;
           else if (data[xx][y]=='.') x=xx,dy=-dy;
           else dx=-dx,dy=-dy;
        }
        if (list[i]==1){
           int xx=x+dx;
           if (data[xx][y]=='.') x=xx;
           else dx=-dx;
        }
        if (list[i]==2){
           int yy=y+dy;
           if (data[x][yy]=='.') y=yy;
           else dy=-dy;
        }
    }
    if ((x==sx)&&(y==sy))
       ++ans,same[xxx/tttt][yyy/tttt][kind]=true;
}

int extra()
{
    int x=sx,y=sy,dd=0;
    while (data[x][y]=='.')
          x+=dx,y+=dy,++dd;
    dd=dd+dd-1;
    if (dd<=d) ++ans;
}

int main()
{
    scanf("%d\n",&times);
    for (int t=1;t<=times;++t)
    {
        memset(same,0,sizeof(same));
        scanf("%d%d%d\n",&n,&m,&d);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j){
                scanf("%c",&data[i][j]);
                if (data[i][j]=='X'){
                   sx=i;sy=j;
                   data[i][j]='.';
                }
                if (j==m) scanf("\n");
            }
        ans=0;
        for (int i=1;i<=d;++i)
            for (int j=1;j<=d;++j)
                if (i*i+j*j<=d*d){
                   dx=1;dy=1;work1(i,j,0);work2(i,j,0);
                   dx=1;dy=-1;work1(i,j,1);work2(i,j,1);
                   dx=-1;dy=1;work1(i,j,2);work2(i,j,2);
                   dx=-1;dy=-1;work1(i,j,3);work2(i,j,3);
                }
        dx=0;dy=1;extra();
        dx=1;dy=0;extra();
        dx=-1;dy=0;extra();
        dx=0;dy=-1;extra();
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
