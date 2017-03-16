#include<stdio.h>
#include<string.h>

struct pp
{
    int x,y;
    double v;
};
bool use[100][100];
double c[100][100],f[100][100],time[100][100];
int n,m,size;
double h;
pp st[20000],heap[20000];
int dx[4],dy[4],pos[100][100];

bool check(int x,int y,int xx,int yy)
{
    if (c[xx][yy]-h<50.0) return false;
    if (c[xx][yy]-f[xx][yy]<50.0) return false;
    if (c[xx][yy]-f[x][y]<50.0) return false;
    if (c[x][y]-f[xx][yy]<50.0) return false;
    return true;
}

double work(int x,int y,int xx,int yy)
{
    if (c[xx][yy]-f[xx][yy]<50.0) return -1;
    if (c[xx][yy]-f[x][y]<50.0) return -1;
    if (c[x][y]-f[xx][yy]<50.0) return -1;
    double ans=time[x][y];
    double hh,h1,h2;
    hh=h-time[x][y]*10.0;
    if (c[xx][yy]-hh<50.0)
    {
        ans+=(50.0-c[xx][yy]+hh)/10.0;
        hh=c[xx][yy]-50.0;
    }
    h1=hh-f[x][y];
    if (h1>=20.0) {ans+=1.0;} else {ans+=10.0;}
    return ans;
}

void up(int o)
{
    int p=o/2;
    if (p==0) return;
    if (heap[o].v<heap[p].v)
    {
        pp tmp=heap[o];heap[o]=heap[p];heap[p]=tmp;
        pos[heap[o].x][heap[o].y]=o;
        pos[heap[p].x][heap[p].y]=p;
        up(p);
    }
}

void down(int o)
{
    int p=o*2;
    if (p>size) return;
    if ((p+1<=size)&&(heap[p].v>heap[p+1].v)) p++;
    if (heap[o].v>heap[p].v)
    {
        pp tmp=heap[o];heap[o]=heap[p];heap[p]=tmp;
        pos[heap[o].x][heap[o].y]=o;
        pos[heap[p].x][heap[p].y]=p;
        down(p);
    }
}

int main()
{
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("2.txt","w",stdout);
    int tt;
    dx[0]=0;dy[0]=1;
    dx[1]=0;dy[1]=-1;
    dx[2]=1;dy[2]=0;
    dx[3]=-1;dy[3]=0;
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%lf%d%d",&h,&n,&m);
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%lf",&c[i][j]);
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) {scanf("%lf",&f[i][j]);time[i][j]=-1;pos[i][j]=-1;}
        memset(use,false,sizeof(use));
        use[0][0]=true;
        time[0][0]=0;
        size=1;
        st[0].x=st[0].y=0;
        while (size!=0)
        {
            int x=st[size-1].x,y=st[size-1].y;
            size--;
            for (int i=0;i<4;i++)
            if ((x+dx[i]>=0)&&(x+dx[i]<n)&&(y+dy[i]>=0)&&(y+dy[i]<m)
              &&(!use[x+dx[i]][y+dy[i]])&&(check(x,y,x+dx[i],y+dy[i])))
              {
                  use[x+dx[i]][y+dy[i]]=true;
                  time[x+dx[i]][y+dy[i]]=0.0;
                  st[size].x=x+dx[i];
                  st[size].y=y+dy[i];
                  size++;
              }
        }

        size=0;
        for (int i=0;i<n;i++)
         for (int j=0;j<m;j++)
          if (time[i][j]==0.0)
           for (int k=0;k<4;k++)
           if ((i+dx[k]>=0)&&(i+dx[k]<n)&&(j+dy[k]>=0)&&(j+dy[k]<m)&&(!use[i+dx[k]][j+dy[k]]))
           {
               double tmp=work(i,j,i+dx[k],j+dy[k]);
               if ((tmp>=0)&&((time[i+dx[k]][j+dy[k]]<0)||(time[i+dx[k]][j+dy[k]]>tmp)))
               time[i+dx[k]][j+dy[k]]=tmp;
           }

        for (int i=0;i<n;i++)
         for (int j=0;j<m;j++)
         if ((!use[i][j])&&(time[i][j]>0))
         {
             if (size==0)
             {
                 size++;
                 heap[size].x=i;
                 heap[size].y=j;
                 heap[size].v=time[i][j];
                 pos[i][j]=1;
                 continue;
             }
             size++;
             heap[size].x=i;
             heap[size].y=j;
             heap[size].v=time[i][j];
             pos[i][j]=size;
             up(size);
         }

        while (!use[n-1][m-1])
        {
            int x=heap[1].x,y=heap[1].y;
            for (int k=0;k<4;k++)
            if ((x+dx[k]>=0)&&(x+dx[k]<n)&&(y+dy[k]>=0)&&(y+dy[k]<m)&&(!use[x+dx[k]][y+dy[k]]))
            {
               double tmp=work(x,y,x+dx[k],y+dy[k]);
               if ((tmp>=0)&&((time[x+dx[k]][y+dy[k]]<0)||(time[x+dx[k]][y+dy[k]]>tmp)))
               {
                   time[x+dx[k]][y+dy[k]]=tmp;
                   if (pos[x+dx[k]][y+dy[k]]<0)
                   {
                       size++;
                       heap[size].x=x+dx[k];
                       heap[size].y=y+dy[k];
                       heap[size].v=tmp;
                       pos[x+dx[k]][y+dy[k]]=size;
                   } else {heap[pos[x+dx[k]][y+dy[k]]].v=tmp;}
                   up(pos[x+dx[k]][y+dy[k]]);
               }
            }
            use[x][y]=true;
            heap[1].v=1e9;
            down(1);
        }
        printf("Case #%d: %.6f\n",t,time[n-1][m-1]);
    }
    return 0;
}
