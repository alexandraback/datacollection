#include<stdio.h>
#include<algorithm>
#include<ctype.h>
#include<stack>
#include<queue>
#include<string.h>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
#define MAX(a,b) ( (a>b)? (a) : (b) )
#define MIN(a,b) ( (a<b)? (a) : (b) )
#define forab(i,a,b) for(int i=a;i<=b;i++)
#define forabd(i,a,b) for(int i=a;i>=b;i--)
#define pb(a) push_back(a)
#define ll long long
#define forabL(i,a,b) for(ll int i=a;i<=b;i++)
int ans[1000005];
int rev(int n)
{
    int x=n;
    int ans=0,rem;
    if(x%10==0)
        return n;
    while(x)
    {
        rem=x%10;
        ans=ans*10+rem;
        x/=10;
    }
    if(ans>n)
        return n;
    return ans;
}
int main()
{

    int t;
   FILE *ifp, *ofp;
    ifp=fopen("A-small-attempt0.in", "r");
   ofp=fopen("Google1","w");
    fscanf(ifp,"%d ",&t);
    //scanf("%d",&t);
    int n;
    ans[1]=1;
    for(int i=2;i<=1000000;i++)
        ans[i]=(1<<30);
    for(int i=2;i<=1000000;i++)
        ans[i]=MIN(ans[i-1]+1,ans[rev(i)]+1);
    //for(int i=1;i<=100;i++)
      //  printf("%d %d\n",i,ans[i]);
    for(int j=1;j<=t;j++)
    {
       // scanf("%d",&n);
        //printf("%d\n",ans[n]);
        fscanf(ifp,"%d ",&n);
        fprintf(ofp,"Case #%d: %d\n",j,ans[n]);

    }

	return 0;
}
