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

int p,t,k,from,to,mid;
double C,F,X;

double firm(int n)
{
    double ret=X/(2.0+(double(n)*F));
    for(int i=0;i<n;i++)
    {
        ret+=(C/(2.0+(i*F)));
    }
    return ret;
}

main()
{
    FILE *read,*write;
    read=fopen("codejam_b_input.txt","r");
    write=fopen("codejam_b_output.txt","w");
    fscanf(read," %d",&t);
    for(p=1;p<=t;p++)
    {
        fscanf(read," %lf %lf %lf",&C,&F,&X);
        from=0;
        to=100010;
        mid=(from+to)/2;
        k=30;
        while(k--)
        {
            if(firm(mid)>firm(mid+1))
                from=mid;
            else if(mid>0&&firm(mid)>firm(mid-1))
                to=mid;
            mid=(from+to)/2;
        }
        fprintf(write,"Case #%d: %.7lf\n",p,firm(mid));
    }
    fclose(read);
    fclose(write);
    return 0;
}

