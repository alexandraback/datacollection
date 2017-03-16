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

struct node{
double val;
int ind;
};

node arr[2010];
int cum1[2010],cum2[2010],i,p,t,n,k,res1,res2;

int comp(node a,node b)
{
    return a.val<b.val;
}

main()
{
    FILE *read,*write;
    read=fopen("codejam_d_input.txt","r");
    write=fopen("codejam_d_output.txt","w");
    fscanf(read," %d",&t);
    for(p=1; p<=t; p++)
    {
        fscanf(read," %d",&n);
        for(i=1; i<=n; i++)
        {
            fscanf(read," %lf",&arr[i].val);
            arr[i].ind=1;
        }
        for(i=1; i<=n; i++)
        {
            fscanf(read," %lf",&arr[i+n].val);
            arr[i+n].ind=2;
        }
        k=n;
        n*=2;
        sort(arr+1,arr+n+1,comp);
        for(i=1;i<=n;i++)
        {
            if(arr[i].ind==1)
            {cum1[i]=cum1[i-1]+1;
            cum2[i]=cum2[i-1];}
            else
            {
            cum1[i]=cum1[i-1];
            cum2[i]=cum2[i-1]+1;
            }
        }
        /*for(i=1;i<=n;i++)
            printf("%d ",cum1[i]);
            printf("\n");
        for(i=1;i<=n;i++)
            printf("%d ",cum2[i]);
            printf("\n");
            printf("\n");*/
        res1=res2=0;
        for(i=1;i<=n;i++)
        {

            res1=max(res1,cum1[i]-cum2[i]);
            res2=max(res2,cum2[i]-cum1[i]);
        }
        fprintf(write,"Case #%d: %d %d\n",p,k-res1,res2);
    }
    fclose(read);
    fclose(write);
    return 0;
}









