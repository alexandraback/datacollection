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

int res,r,c,w,p,t,dp[22][22][22],res2,i,j,tp,k;

int rec(int pos,int prev,int taken)
{
    if((prev+w)>c)
        return 99999999;
    int &ret=dp[pos][prev][taken];
    if(ret!=-1)
        return ret;
    ret=99999999;
   // printf("%d %d %d %d\n",pos,prev,taken,taken+min(w,c-pos+1)+(pos-prev-1));
    if((pos+w)>c)
    ret=min(ret,taken+min(w,c-pos+1)+(pos-prev-1));
    if((pos+1-prev)<=w)
    ret=min(ret,rec(pos+1,prev,taken));
    ret=min(ret,rec(pos+1,pos,taken+1));
    return ret;
}

int main()
{
    freopen("A-large1.in","r",stdin);
    freopen("battleshipout.txt","w",stdout);
    scanf(" %d",&t);

    for(p=1; p<=t; p++)
    {
        scanf(" %d %d %d",&r,&c,&w);
        printf("Case #%d: ",p);
        if(w==1)
        {
            printf("%d\n",r*c);
            continue;
        }
        //res=((c/w)*r)+(w-1);
        memset(dp,-1,sizeof(dp));

        res=rec(1,0,0);

        if(r==1)
        printf("%d\n",res);
        else
        printf("%d\n",res+((r-1)*(c/w)));
    }
    return 0;
}





