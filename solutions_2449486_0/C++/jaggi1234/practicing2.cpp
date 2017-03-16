#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<cassert>
#include<ctime>
#define debug(i) cout<<#i" = "<<i<<"\n";system("pause");
#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p,0,sizeof(p))
#define S(n) scanf("%d",&n)
#define P(n) printf("%d\n",n)
#define Sl(n) scanf("%lld",&n)
#define Pl(n) printf("%lld\n",n)
#define Sf(n) scanf("%lf",&n)
#define Ss(n) scanf("%s",n)
#define LL long long
#define ULL unsigned long long
#define pb push_back
using namespace std;
int findmax(int *start,int *end,int increment)
{
    int *p;
    int max=*start;
    for(p=start; p<=end; p+=increment)
    {
        if(*p>max)
            max=*p;
    }
    return max;
}
int main()
{
    bool flag;
    register int i,j;
    int t,row,col,counter=1;
    scanf("%d",&t);
    while(t--)
    {
        flag=true;
        scanf("%d%d",&row,&col);
        int n[row][col];
        int maxes[row+col];
        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                scanf("%d",&n[i][j]);
            }
        }
        cout<<"Case #"<<counter++<<": ";
        for(i=0;i<row;i++)
        {
            maxes[i]=findmax(n[i],n[i]+col-1,1);
        }
        for(j=0;j<col;j++)
        {
            maxes[i+j]=findmax(n[0]+j,n[row-1]+j,col);
        }
/*
        for(i=0;i<row+col;i++)
        {
            cout<<maxes[i]<<" ";
        }
        cout<<"\n";
*/
        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                if((n[i][j]==maxes[i])||(n[i][j]==maxes[row+j]))
                {
                    continue;
                }
                else
                {
                    flag=false;
                    break;
                }
            }
            if(flag==false)
               break;
        }
        if(flag)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}
