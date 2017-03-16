#include <cstdio>
#include <cstring>
#include <iostream>
#define maxRC 53
using namespace std;
int m,mine,r,c,a[maxRC][maxRC];
int Count1(int x,int y){
    int i,j,res=0;
    for (i=-1;i<=1;i++) for (j=-1;j<=1;j++)
        if (a[x+i][y+j]==1)res++;
    return res;
}
void fill0(int x,int y){
    int i,j;
    for (i=-1;i<=1;i++) for (j=-1;j<=1;j++)
        if (a[x+i][y+j]==1) a[x+i][y+j]=0;
}

void output(){
    if (mine==m){
        //return;
        int i,j;
        for (i=1;i<=r;i++){
            printf("\n");
            for (j=1;j<=c;j++){
                if (a[i][j]<0) printf("c");
                else{
                    if (a[i][j]==0)printf(".");
                    else printf("*");
                }
            }
        }
    }
    else{
        printf("\nImpossible");
        return;
        printf(" %d %d %d",r,c, (r*c-m));
        int i,j;
        for (i=1;i<=r;i++){
            printf("\n");
            for (j=1;j<=c;j++){
                if (a[i][j]<0) printf("c");
                else{
                    if (a[i][j]==0)printf(".");
                    else printf("*");
                }
            }
        }
    }
}

struct cell{int r,c;};
cell q[maxRC*maxRC]; int top; bool d[maxRC][maxRC];

void addq(int i,int j){
    if (d[i][j]==true||(i<=0||i>r)||(j<=0||j>c)) return;
    int k=Count1(i,j); if  (mine-k<m) return;
    d[i][j]=true;
    mine-=k;
    fill0(i,j);
    q[top].r=i; q[top].c=j; top++;
}
void process(){
    memset(a,0,sizeof(a)); int i,j,k; mine=0;
    for (i=1;i<=r;i++) for (j=1;j<=c;j++){
        a[i][j]=1; mine++;
    }
    memset(d,false,sizeof(d));
    k=Count1(1,1);
    if (mine-k>=m){
        mine-=k;
        fill0(1,1);
    }
    else mine--;
    a[1][1]=-1;
    q[0].r=1; q[0].c=1; d[0][0]=true; top=1;
    int u,v;
    for (i=0;i<top;i++){
        u=q[i].r; v=q[i].c;
        if (c>=r){
            addq(u,v+1);addq(u+1,v);
        }
        else{
            addq(u+1,v);addq(u,v+1);
        }
    }
    a[0][0]=-1;
}
int main(){
    freopen("C-small-attempt6.in","r",stdin);
    freopen("test4.txt","w",stdout);
    int test,ntest; scanf("%d",&ntest);
    for (test=1;test<=ntest;test++)
    {
        scanf("%d%d%d",&r,&c,&m);
        if (test>1) printf("\n");
        printf("Case #%d:",test);
        process();
        output();
    }
    return 0;
}
