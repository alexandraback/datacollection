#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#define MAXN 64
#define INF 1<<30
///
using namespace std;

const long long num[40]= {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,
                          102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,
                          12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,
                          1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004,100000020000001
                         };

int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    long long a,b;
    for(int c=1; c<=cases; c++)
    {
        scanf("%lld %lld",&a,&b);
        int ans=0;
        int s,t;
        for(int i=0; i<40; i++)
        {
            if(num[i]>=a)
            {
                s=i;
                break;
            }
        }
        for(int i=0; i<40; i++)
        {
            if(num[i]==b)
            {
                t=i;
                break;
            }
            else if(num[i]>b)
            {
                t=i-1;
                break;
            }
        }
        ans=t-s+1;
        printf("Case #%d: %d\n",c,ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
