#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<string>
#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<utility>
#include<sstream>
using namespace std;

#define pi (2*acos(0.0))
#define inf 1<<30
#define maxi(a,b) ((a>b)?a:b)
#define mini(a,b) ((a>b)?b:a)
#define pb(a) push_back(a)
#define sz 10000010
#define LL long long

LL fa_pr[100];
int cnt;
bool ispal(LL num)
{
     LL rev=0,copy=num;
     while(num!=0)
     {
         rev=(rev*10)+(num%10);
         num/=10;
     }

     if(copy==rev)
        return true;
     return false;
}
void precal()
{
    LL i,j;
    cnt=0;
    for(i=1;i<=10000000;i++)
    {
        LL sq=i*i;
        if(ispal(i) && ispal(sq))
        {
            fa_pr[cnt++]=sq;
        }
    }
}

int main()
{
    LL i,j,k,num,t,test,a,b,ans;


    freopen("C-large-1.in","r",stdin);
    freopen("C-large-1.out","w",stdout);

    precal();


    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld%lld",&a,&b);

        printf("Case #%lld: ",t);
        ans=0;
        for(i=0;i<40;i++)
        {
            if(fa_pr[i]>=a && fa_pr[i]<=b)
                ans++;
        }
        printf("%lld\n",ans);

    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
