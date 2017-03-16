#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<map>
#include<list>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>




#define FOREACH(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define all(s) s.begin(),s.end()
#define pb push_back
#define mp make_pair
#define sd(x) scanf("%d",&x)
#define sl(x) scanf("%I64d",&x)
#define pd(x) printf("%d",x)
#define ll long long
const int mod = ((1E9)+7);
const int intmax = ((1E9)+7);




#ifndef ONLINE_JUDGE
#define TRACE
#endif
#ifdef TRACE
    #define trace(x)            cerr<<x<<endl;
    #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#else
    #define trace(x)
    #define trace1(x)
    #define trace2(x,y)
    #define trace3(x,y,z)
#endif

using namespace std;



#define n_ 1000006

int dp[n_];


int reverse_(int n)
{

    int sum=0;

    while(n)
    {

        int r= n%10;
        sum=sum*10+r;
        n=n/10;
    }


    return sum;
}




int N;

int cal(int n)
{


    if(n==N) return 0;
    if(n>N) return intmax;


    if(dp[n]!=-1) return dp[n];

    int x=reverse_(n);

    int ans1=intmax,ans2=intmax;
    if(x>n)
    {
            ans1=cal(x)+1;

    }

    ans2=cal(n+1)+1;

    return dp[n]=min(ans1,ans2);


}




int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int test,a,b,c;



    sd(test);
    int t=1;

    while(test--)
    {
        memset(dp,-1,sizeof(dp));

        sd(N);
        cout<<"Case #"<<t<<": "<<cal(1)+1<<endl;
        t++;

    }

    return 0;


}
