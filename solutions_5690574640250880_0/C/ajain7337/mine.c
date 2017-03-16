#include<stdio.h>
char mine[50][50];
int arr[50][50][9][2];
int vis[50][50];
int r,c,m;
int rem;
int check(int,int);
void open(int,int);
void close(int,int);
void printmine();
int main()
{
    int t,i,j,k,flag,inv;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d%d",&r,&c,&m);
        inv=0;
        for(j=0;j<r;j++)
        {
            for(k=0;k<c;k++)
            {
                mine[j][k]='*';
                vis[j][k]=0;
            }
        }
        rem=r*c-m;
        mine[0][0]='c';
        rem--;
        flag=check(0,0);
        printf("Case #%d: \n",i+1);
        if(flag) printmine();
        else printf("Impossible\n");
    }
    return 0;
}

int check(int i, int j)
{
    int x,z;
    if(vis[i][j]==0 && i>=0 && i<r && j>=0 && j<c)
    {
        if(rem==0) return 1;
        else if(rem<0) return 0;
        else
        {
            vis[i][j]=1;
            open(i,j);
           if(check(i-1,j-1)||check(i-1,j)||check(i-1,j+1)||check(i,j-1)||check(i,j+1)||check(i+1,j-1)||check(i+1,j)||check(i+1,j+1)) return 1;
           vis[i][j]=0;
            close(i,j);
        }
    }
    return 0;
}


void open(int i, int j)
{
    int cnt=0,a3=0,a4=0,k,l;
    for(k=i-1;k<=i+1;k++)
    {
        if(k>=0 && k<r)
        {
            for(l=j-1;l<=j+1;l++)
            {
                if(l>=0 && l<c)
                {
                    if(mine[k][l]=='*')
                    {
                        mine[k][l]='.';
                        rem--;
                        cnt++;
                        arr[i][j][++a3][0]=k-i;
                        arr[i][j][a3][1]=l-j;
             //           printf("/////%d %d\n",arr[i][j][a3-1][0],arr[i][j][a3-1][1]);
                    }
                }
            }
        }
    }
    arr[i][j][0][0]=cnt;
}

void close(int i, int j)
{
    int x=arr[i][j][0][0],z;
    for(z=1;z<=x;z++)
    {
        mine[i+arr[i][j][z][0]][j+arr[i][j][z][1]]='*';
        rem++;
    }
    arr[i][j][0][0]=0;
}

void printmine()
{
    int k,l;
    for(k=0;k<r;k++)
    {
        for(l=0;l<c;l++)
        {
            printf("%c",mine[k][l]);
        }
        printf("\n");
    }
}



