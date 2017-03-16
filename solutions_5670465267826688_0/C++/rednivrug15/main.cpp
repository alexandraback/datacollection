/*Author:rednivrug15*/
#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
#define MOD 1000000007

long long power(long long a,long long b,long long mod)
{
    long long ret=1;

    while(b)
    {
        if(b%2==1)
            ret=(ret*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ret;
}

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

pair < int , int > dp[1001];
int ans[1001][1001],M[1001],m[1001];

pair < int , int > solve(int n)
{
    if(n==1) return mp(1,0);

    if(dp[n].first!=0)
        return dp[n];

    dp[n].first=n;
    dp[n].second=0;

    for(int i=1; i<=n; i++)
    {
        pair < int, int > x=solve(n-i);
        if(x.first+i<=1000)
         ans[n][x.first+i]=min(ans[n][x.first+i],x.second);

        if(x.first + i<dp[n].first)
        {
            dp[n].first=x.first+i;
            dp[n].second=x.second;
        }
        else if( x.first+ i==dp[n].second)
            dp[n].second=min(dp[n].second,x.second);
    }

    for(int j=1; j<n; j++)
    {
            pair < int, int > x=solve(j);
            pair < int, int > y=solve(n-j);

        	for(int lefts=m[j]; lefts<=M[j]; lefts++)
        		for(int rights=m[n-j]; rights<=M[n-j]; rights++)
        		 if(ans[j][lefts]!=MOD && ans[n-j][rights]!=MOD)
                 {
        		 	ans[n][1+max(lefts+ans[n-j][rights],rights+ans[j][lefts])]=min(ans[n][1+max(lefts+ans[n-j][rights],rights+ans[j][lefts])],1+ans[j][lefts]+ans[n-j][rights]);
        		 	m[n]=min(m[n],1+max(lefts+ans[n-j][rights],rights+ans[j][lefts]));
        		 	M[n]=max(M[n],1+max(lefts+ans[n-j][rights],rights+ans[j][lefts]));
                 }

            if(1+ max(x.first+y.second,y.first+x.second)<dp[n].first)
            {
                dp[n].first=1+ max(x.first+y.second,y.first+x.second);
                dp[n].second=1+x.second+y.second;
            }

            else if(1+ max(x.first+y.second,y.first+x.second)==dp[n].first)
                dp[n].second=min(dp[n].second,1+x.second+y.second);
    }
    return dp[n];
}

int sumans[1001][1001];
char str[100001];
int dpleft[100001],dpright[100001];
int arr[100001];

int decode(int x,int y)
{
    int sign;

    if(x*y>0)
        sign=1;
    else
        sign=-1;
    y=abs(y);

    if(abs(x)==1)
    {
        return sign*y;
    }
    else if(abs(x)==2)
    {
        if(y==1)
            return sign*x;
        else if(y==2)
            return -sign;
        else if(y==3)
            return 4*sign;
        else
            return -3*sign;
    }

    else if(abs(x)==3)
    {
        if(y==1)
            return sign*x;
        else if(y==2)
            return -4*sign;
        else if(y==3)
            return -sign;
        else
            return 2*sign;
    }
    else
    {
        //printf("y is %d and sign is %d\n",y,sign);
        if(y==1)
            return sign*x;
        else if(y==2)
            return 3*sign;
        else if(y==3)
            return -2*sign;
        else
            return -sign;
    }
}

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("op.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int cases=1; cases<=t; cases++)
    {
        printf("Case #%d: ",cases);
        int l,x;
        scanf("%d%d",&l,&x);
        scanf("%s",str);
        x--;

        for(int i=0; i<x; i++)
            for(int j=0; j<l; j++)
             str[(i+1)*l+j]=str[j];
        l=l+l*x;

        for(int i=0; i<l; i++)
        {
            if(str[i]=='i')
                arr[i]=2;
            else if(str[i]=='j')
                arr[i]=3;
            else
                arr[i]=4;
        }
        int current=arr[0];
        memset(dpleft,0,sizeof dpleft);
        memset(dpright,0,sizeof dpright);

        dpleft[0]=(arr[0]==2);
        //printf("%d--%d\n",0,current);

        for(int i=1; i<l; i++)
        {
            current=decode(current,arr[i]);
            dpleft[i]=(current==2);
            //printf("%d--%d %d\n",i,current,arr[i]);
        }

        int khasappearred=0;
        current=arr[l-1];
        khasappearred=(arr[l-1]==4);
        //printf("%d--%d\n",l-1,current);

        for(int i=l-2; i>=0; i--)
        {
            current=decode(arr[i],current);
            if(khasappearred==1)
            {
                dpright[i]=(current==2);
            }
            else
                khasappearred=(current==4);
            //printf("%d--%d\n",i,current);
        }

        int flag=0;
        for(int i=0; i<l; i++)
        {
            if(dpleft[i]==1 && dpright[i+1]==1)
                flag=1;
        }
        (flag==0)?puts("NO"):puts("YES");
    }
    return 0;
}
