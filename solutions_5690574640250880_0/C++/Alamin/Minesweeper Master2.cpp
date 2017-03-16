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
#define pi 2*acos(0)
#define SF scanf
#define SFd1(a) scanf("%d",&a)
#define SFd2(a,b) scanf("%d%d",&a,&b)
#define SFd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define PF printf
#define inf 99999999
#define eps 0.00000001
#define ll long long
#define ull long long unsigned
#define fr(i,n) for(i=0;i<n;i++)
#define dist(x1,y1,x2,y2) sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) )
using namespace std;
//int rr[]={1,2,-1,-2,1,2,-1,-2};
//int cc[]={2,1,2,1,-2,-1,-2,-1};

int r,c,n,bombs,p,t,i,ext,fil,j,k,flag,arr[110][110];

main()
{
    FILE *read,*write;
    read=fopen("codejam_c_input.txt","r");
    write=fopen("codejam_c_output.txt","w");
    fscanf(read," %d",&t);
    for(p=1;p<=t;p++)
    {
        memset(arr,0,sizeof(arr));
        flag=0;
        fscanf(read," %d %d %d",&r,&c,&bombs);
        if(r>c)
        {
            ext=r-c;
            ext*=c;
            fil=bombs/c;
            if(fil>(r-c))
            fil=r-c,flag=1;
            bombs-=fil*c;
            for(i=0;i<fil;i++)
            {
                for(j=1;j<=c;j++)
                {
                    arr[r-i][j]=1;
                }
            }
            for(i=r-fil;i>c;i--)
            {
                for(j=c;j>2&&bombs>0;bombs--,j--)
                    arr[i][j]=1;//printf("%d-%d\n",r-fil,j);
            }
        }
        else if(c>r)
        {
            ext=c-r;
            ext*=r;
            fil=bombs/r;
            if(fil>(c-r))
            fil=c-r,flag=1;
            bombs-=fil*r;
            //printf("%d\n",fil);
            for(i=0;i<fil;i++)
            {
                for(j=1;j<=r;j++)
                {
                    arr[j][c-i]=1;
                }
            }
            /*if(bombs<=(r-2))
            {
                for(j=r;j>=1&&bombs>0;bombs--,j--)
                    arr[j][c-fil]=1;//,printf("%d-%d\n",j,c-fil);
            }*/
            for(i=c-fil;i>r;i--)
            {
                for(j=r;j>2&&bombs>0;bombs--,j--)
                    arr[j][i]=1;//printf("%d-%d\n",r-fil,j);
            }
        }
        n=min(r,c);
        //printf("%d\n",bombs);
        while((n*2-1)<=bombs)
        {
            bombs-=(n*2-1);
            for(i=1;i<=n;i++)
            {
                    arr[i][n]=arr[n][i]=1;
            }
            n--;
        }
        for(i=n;i>2&&bombs>0;i--)
        {
            if(bombs>=i)
            {
                bombs-=i;
                for(j=1;j<=i;j++)
                    arr[i][j]=1;
            }
            else if(bombs>0)
            {
                for(j=i;bombs>0&&j>2&&i>2;bombs--,j--)
                    arr[i][j]=1;
            }
            if(bombs>=i)
            {
                bombs-=i;
                for(j=1;j<=i;j++)
                    arr[j][i]=1;
            }
            else if(bombs>0)
            {
                for(j=i-1;bombs>0&&j>2&&i>2;bombs--,j--)
                    arr[j][i]=1;
            }

        }
        /*for(i=n;i>0&&bombs>0;i--)
        {
            for(j=i;j>0&&bombs>0;j--)
            {
                if(i>2&&j>2)
                {
                    if(bombs>0)
                    {
                        arr[i][j]=1;
                        bombs--;
                    }
                    if(bombs>0&&j!=i)
                    {
                        arr[j][i]=1;
                        bombs--;
                    }
                }
            }
        }*/
        fprintf(write,"Case #%d:\n",p);
        if(bombs>0)
        {
            fprintf(write,"Impossible\n");
        }
        else
        {
            arr[1][1]=2;
             for(i=1;i<=r;i++)
            {
                for(j=1;j<=c;j++)
                {
                    if(arr[i][j]==1)
                        fprintf(write,"*");
                    else if(arr[i][j]==0)
                        fprintf(write,".");
                    else
                        fprintf(write,"c");
                }
                fprintf(write,"\n");
            }
        }
    }
    fclose(read);
    fclose(write);
    return 0;
}


