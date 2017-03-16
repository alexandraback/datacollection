/* HellGeek */
/* Shiva Bhalla */
/* iit2012077 */


#include<stdio.h>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<set>
#include<string>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<math.h>

#define LL long long
#define FIT(i,t) for(i=0;i<t;i++)
#define FIN(i,n) for(i=0;i<n;i++)
#define FJT(j,t) for(j=0;j<t;j++)
#define FJN(j,n) for(j=0;j<n;j++)
#define MAX2(a,b) a>b?a:b
#define MIN2(a,b) a>b?b:a
#define REP(i,a,b) for(i=a;i<=b;i++)

#define mod 1000000007



using namespace std;
LL art[100005];

int main()
{
    freopen("alpha1.in","w",stdout);
    

    LL t,i;
    scanf("%lld",&t);
    LL chutiya=0,count=0;

    LL n,m,k;
    LL sqr;
    LL result=0;
    while(t--)
    {
        chutiya++;
        result=0;
        cin>>n;
        cin>>m;
        cin>>k;
        sqr=sqrt(k);
        
        if((sqr*sqr>k/2) && (sqr<=n)&& (sqr<=m))
        {
            result=k-(sqr*sqr-(sqr*2+2*(sqr-2)));
       

        result=result-(k-(sqr*sqr));
        
        }
        else
        {
LL l,b;

        l=sqr;
        b=sqr;
        bool con=true;
        do
        {
            if(con)
            {l++;
            con=false;
            }
            else{
            b++;
            con=true;
            }

        }while(l*b<=k);
        if(con)
        b--;
        else
        l--;
        result=k-(l*b-(b*2+2*(l-2)));
       

        result=result-(k-(l*b));
        
        }
        printf("Case #%lld: %lld\n",chutiya,result);


    }

return 0;
}
