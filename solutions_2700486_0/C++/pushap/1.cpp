#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <bitset>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <ctime>

#define ALL(i,n)    for(i = 0; i < (n); i++)
#define FOR(i,a,b)  for(i = (a); i < (b); i++)
#define SET(p)      memset(p,-1,sizeof(p))
#define CLR(p)      memset(p,0,sizeof(p))
#define S(n)	    scanf("%d",&n)
#define P(n)	    printf("%d\n",n)
#define Sl(n)	    scanf("%lld",&n)
#define Pl(n)	    printf("%lld\n",n)
#define Sf(n)       scanf("%lf",&n)
#define Ss(n)       scanf("%s",n)
#define LL long long
#define ULL unsigned long long
#define pb push_back
using namespace std;

double prob[3005][3005];

double func(int n,int i)
{
    if(prob[n][i]>=-0.5)
        return prob[n][i];
    if(n==0 && i==0)
    {
        prob[n][i]=1;
        return 1;
    }
    if(i>n || i<0)
    {
        prob[n][i]=0;
        return 0;
    }

    return prob[n][i]=(func(n-1,i-1)+func(n-1,i))/2;
}

int main()
{
    int t,n,x,y,m,i,j,k,l,case1=0;
    freopen("B-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);

    i=1;  k=0;

    for(i=0;i<3000;i++)
    {
        for(j=0;j<3000;j++)
        {
            prob[i][j]=-1;
        }
    }

    for(i=0;i<3000;i++)
        func(3000,i);

    for(i=0;i<3000;i++)
    {
        for(j=0;j<3000;j++)
        {
            func(i,j);
        }
    }

    S(t);
    while(t--)
    {
        S(n);  S(x);  S(y);

        double ans=0;
        x=max(x,-x);
        int sum=0;
        i=1;  j=0;  k=x+y;

        while(1)
        {
            sum+=i;
            //printf("     %d %d %d\n",i,sum,j);
            if(j==k)
            {
                if(sum<=n)
                {
                    ans=1;
                }
                else if(x==0)
                {
                    ans=0;
                }
                else if(sum==0)
                {
                    ans=0;
                }
                else
                {
                    int tmp=n+i-sum;
                    //printf("            %d %d\n",tmp);
                    if(tmp>j)
                    {
                        int pp=(tmp-j);
                        for(l=y+1-pp;l<=tmp-2*pp;l++)
                            ans+=prob[tmp-2*pp][l];
                    }
                    else
                    {
                        for(l=y+1;l<=tmp;l++)
                            ans+=prob[tmp][l];
                    }
                }
                break;
            }


            if(sum>n)
            {
                ans=0;
                break;
            }

            j+=2;
            i+=4;
        }

        //printf("ans= %lf\n",ans);
        printf("Case #%d: %.9lf\n",++case1,ans);
    }
    return 0;
}
