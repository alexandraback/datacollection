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

int t,p,i,res,j,arr[1010],n,k;

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("InfiniteHouseofPancakesOutput.txt","w",stdout);

    scanf(" %d",&t);

    for(p=1;p<=t;p++)
    {
        scanf(" %d",&n);
        res=1000000010;
        for(i=1;i<=n;i++)
        {
            scanf(" %d",&arr[i]);
        }
        sort(arr+1,arr+1+n);
        res=min(res,arr[n]);

        for(i=1;i<=1000;i++)
        {
            k=0;
            for(j=n;arr[j]>i;j--)
            {
                k+=(arr[j]/i)+((arr[j]%i)==0?0:1)-1;
                if(j>1)
                res=min(res,k+max(arr[j-1],i));
                else
                res=min(res,k+i);
            }
        }
        printf("Case #%d: %d\n",p,res);
    }
    return 0;
}





