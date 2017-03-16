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

int t,p,n,i,res,stand,arr[1010],k;
char str[1010];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("StandingOvationOutput.txt","w",stdout);

    scanf(" %d",&t);

    for(p=1;p<=t;p++)
    {
        scanf(" %d %s",&n,str);
        for(i=0;i<=n;i++)
        {
            arr[i]=str[i]-'0';
        }
        res=0;
        stand=0;
        for(i=0;i<=n;i++)
        {
            if(arr[i]==0)
                continue;
            if(stand>=i)
            {
                stand+=arr[i];
            }
            else
            {
                k=i-stand;
                res+=k;
                stand+=(arr[i]+k);
            }
        }
        printf("Case #%d: %d\n",p,res);
    }
    return 0;
}





