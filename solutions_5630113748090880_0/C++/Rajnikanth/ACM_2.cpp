#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<iomanip>
#include<queue>
#include<map>
#include<list>
#include<stack>
#define fl(i,s,n) for(i=s;i<n;i++)
#define flr(i,s,n) for(i=s;i>n;i--)
#define ls(i,s) for(i=0;s[i]!='\0';i++)
#define gi(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define checkline(x) while(x!='\0' && x!='\n')
#define pt(s) printf(s)
#define PI acos(-1)
#define f_in freopen("input.in","r",stdin)
#define f_out freopen("output.txt","w",stdout)
#define in(i,j,k) ((j<=i) && (i<k))
#define ull unsigned long long int
#define lli long long int
#define ld long double
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define r0 return 0
#define mod 1000000007
using namespace std;
int prog()
{
    lli i,j,k,x,y,z,n;
    int hs[2501];
    gi(n);
    fl(i,0,2501)
        hs[i]=0;
    fl(i,0,(2*n)-1)
        fl(j,0,n)
        {
            gi(x);
            hs[x]+=1;
        }
    y=n;
    k=0;
    fl(i,1,2501)
    {
        if(y==0)
            r0;
        if((hs[i]%2==1))
            {cout<<i<<' ';y--;}

    }
    r0;
}
int main()
{
    f_in;
    f_out;
    lli t,i;
    gi(t);
    fl(i,1,t+1)
    {
        printf("Case #%lld: ",i);
        prog();
        cout<<endl;
    }
    r0;
}
