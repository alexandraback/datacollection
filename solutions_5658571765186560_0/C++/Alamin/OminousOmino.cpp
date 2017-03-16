/*Author : Md. Al- Amin
           20th batch
           Dept. of CSE, SUST*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define pi (2*acos(0))
#define SF scanf
#define SFd1(a) scanf("%d",&a)
#define SFd2(a,b) scanf("%d%d",&a,&b)
#define SFd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define PF printf
#define inf 99999999
#define eps 0.00000001
#define ll long long
#define ull long long unsigned
#define int_max 2147483647
#define int_min -2147483648
#define long_max 9223372036854775807
#define long_min -9223372036854775808
#define fr(i,n) for(i=0;i<n;i++)
#define ms(dp,a) memset(dp,a,sizeof(dp))
#define dist(x1,y1,x2,y2) sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) )
#define PB push_back
#define mem(arr,val) memset(arr,val,sizeof(arr))

using namespace std;
//int rr[]={1,2,-1,-2,1,2,-1,-2};
//int cc[]={2,1,2,1,-2,-1,-2,-1};
//int rr[]={0,0,1,-1};
//int cc[]={-1,1,0,0};

int xx,yy,r,c,arr[6][6],tpa[6][5][5];
string th[110],fr[110];

int three(int k)
{
    int l=th[k].length();
    int x=xx;
    int y=yy;
    for(int i=0; i<l; i++)
    {
        if(th[k][i]=='R')
            y++;
        else if(th[k][i]=='D')
            x++;
        else
            y--;
        if(x>r||y>c||x<1||y<1)
            return 0;
        if(arr[x][y])
            return 0;
    }
    x=xx;
    y=yy;
    arr[xx][yy]=1;
    for(int i=0; i<l; i++)
    {
        if(th[k][i]=='R')
            y++;
        else if(th[k][i]=='D')
            x++;
        else
            y--;
        arr[x][y]=1;
    }
    return 1;
}

int four(int k)
{
    int l=fr[k].length();
    int x=xx;
    int y=yy;
    for(int i=0; i<l; i++)
    {
        if(fr[k][i]=='R')
            y++;
        else if(fr[k][i]=='D')
            x++;
        else
            y--;
        if(x>r||y>c||x<1||y<1)
            return 0;
        if(arr[x][y])
            return 0;
    }
    x=xx;
    y=yy;
    arr[xx][yy]=1;
    for(int i=0; i<l; i++)
    {
        if(fr[k][i]=='R')
            y++;
        else if(fr[k][i]=='D')
            x++;
        else
            y--;
        arr[x][y]=1;
    }
    return 1;
}

void putit(int k)
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
           tpa[k][i][j]=arr[i][j];
        }
    }
    return;
}

void callit(int k)
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
           arr[i][j]=tpa[k][i][j];
        }
    }
    return;
}

void nextpos(void)
{
    for(int i=xx; i<=r; i++)
    {
        for(int j=yy; j<=c; j++)
        {
            if(arr[i][j]==0)
            {
                xx=i;
                yy=j;
                return;
            }
        }
    }
    return;
}


int main()
{
    freopen("D-small-attempt3.in","r",stdin);
    freopen("OminousOminoOutput.txt","w",stdout);

    int flag[110],i,j,k,l,m,x,t,p,need,cnt,xx1,xx2,xx3,yy1,yy2,yy3,xx4,yy4;


    fr[1]="RDL";

    fr[2]="RLDD";
    fr[3]="RRD";
    fr[4]="DDL";
    fr[5]="DRR";

    fr[6]="DLL";
    fr[7]="DDR";
    fr[8]="RRLLD";
    fr[9]="RDD";

    fr[10]="DRLD";
    fr[11]="RRLD";
    fr[12]="DLRD";
    fr[13]="DLRR";


    fr[14]="DRD";
    fr[15]="RLDL";

    fr[16]="DLD";
    fr[17]="RDR";

    fr[18]="RRR";
    fr[19]="DDD";




    th[1]="RR";
    th[2]="DD";
    th[3]="RD";
    th[4]="DL";
    th[5]="DR";
    th[6]="RLD";

    scanf(" %d",&t);
    for(p=1; p<=t; p++)
    {
        scanf(" %d %d %d",&x,&r,&c);
        if(x==1)
        {
            printf("Case #%d: GABRIEL\n",p);
            continue;
        }
        if(x==2)
        {
            if((r*c)%2)
            {
                printf("Case #%d: RICHARD\n",p);
            }
            else
                printf("Case #%d: GABRIEL\n",p);
            continue;
        }
        if(x==3)
        {
            memset(flag,0,sizeof(flag));
            if((r*c)%3)
            {
                printf("Case #%d: RICHARD\n",p);
                continue;
            }

            need=(r*c)/3;
            cnt=0;
            for(i=1; i<=6; i++)
            {
                cnt=0;
                memset(arr,0,sizeof(arr));
                memset(tpa,0,sizeof(tpa));
                xx=1;
                yy=1;

                if(three(i)==0)
                    continue;
                cnt++;
                if(cnt==need)
                    flag[i]=1;
                nextpos();
                xx1=xx;
                yy1=yy;

                putit(1);

                for(j=1; j<=6; j++)
                {
                    callit(1);
                    xx=xx1;
                    yy=yy1;
                    if(three(j)==0)
                        continue;
                    cnt++;
                    if(cnt==need)
                        flag[i]=1,flag[j]=1;
                    nextpos();
                    xx2=xx;
                    yy2=yy;
                    putit(2);

                    for(k=1; k<=6; k++)
                    {
                        callit(2);
                        xx=xx2;
                        yy=yy2;
                        if(three(k)==0)
                            continue;
                        cnt++;
                        if(cnt==need)
                            flag[i]=1,flag[j]=1,flag[k]=1;
                        nextpos();

                        xx3=xx;
                        yy3=yy;
                        putit(3);

                        for(l=1; l<=6; l++)
                        {
                            callit(3);
                            xx=xx3;
                            yy=yy3;
                            if(three(l)==0)
                                continue;
                            cnt++;
                            if(cnt==need)
                                flag[i]=1,flag[j]=1,flag[k]=1,flag[l]=1;
                            nextpos();
                            xx4=xx;
                            yy4=yy;
                            putit(4);

                            for(m=1; m<=6; m++)
                            {
                                callit(4);
                                xx=xx4;
                                yy=yy4;
                                if(three(m)==0)
                                    continue;
                                cnt++;
                                if(cnt==need)
                                    flag[i]=1,flag[j]=1,flag[k]=1,flag[l]=1,flag[m]=1;
                            }
                        }
                    }
                }
            }

            if((flag[1]|flag[2])&&(flag[3]|flag[4]|flag[5]|flag[6]))
            {
                printf("Case #%d: GABRIEL\n",p);
            }
            else
                printf("Case #%d: RICHARD\n",p);
            continue;

        }

        if(x==4)
        {
            memset(flag,0,sizeof(flag));
            memset(tpa,0,sizeof(tpa));
            if((r*c)%4)
            {
                printf("Case #%d: RICHARD\n",p);
                continue;
            }

            need=(r*c)/4;
            cnt=0;
            for(i=1; i<=19; i++)
            {
                cnt=0;
                memset(arr,0,sizeof(arr));
                xx=1;
                yy=1;

                if(four(i)==0)
                    continue;
                cnt++;
                if(cnt==need)
                    flag[i]=1;
                nextpos();
                xx1=xx;
                yy1=yy;
                putit(1);
                for(j=1; j<=19; j++)
                {
                    callit(1);
                    xx=xx1;
                    yy=yy1;
                    if(four(j)==0)
                        continue;
                    cnt++;
                    if(cnt==need)
                        flag[i]=1,flag[j]=1;
                    nextpos();
                    xx2=xx;
                    yy2=yy;
                    putit(2);

                    for(k=1; k<=19; k++)
                    {
                        callit(2);
                        xx=xx2;
                        yy=yy2;
                        if(four(k)==0)
                            continue;
                        cnt++;
                        if(cnt==need)
                            flag[i]=1,flag[j]=1,flag[k]=1;
                        nextpos();
                        xx3=xx;
                        yy3=yy;
                        putit(3);
                        for(l=1; l<=19; l++)
                        {
                            callit(3);
                            if(four(l)==0)
                                continue;
                            cnt++;
                            if(cnt==need)
                                flag[i]=1,flag[j]=1,flag[k]=1,flag[l]=1;
                        }
                    }
                }
            }

            if(flag[1]&&(flag[2]|flag[3]|flag[4]|flag[5]|flag[6]|flag[7]|flag[8]|flag[9])&&(flag[10]|flag[11]|flag[12]|flag[13])&&(flag[14]|flag[15]|flag[16]|flag[17])&&(flag[18]|flag[19]))
            {
                printf("Case #%d: GABRIEL\n",p);
            }
            else
                printf("Case #%d: RICHARD\n",p);
            continue;

        }

    }

    return 0;
}




