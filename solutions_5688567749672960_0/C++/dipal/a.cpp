#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long flip(long long n)
{
    if (n%10==0) return n;
    long long ans=0;
    while (n)
    {
        ans=ans*10+n%10;
        n/=10;
    }

    return ans;
}

long long cnt(long long n)
{
    if (n==1) return 1;
    long long ans=0;
    while (n>1)
    {
        //cout<<"==>> "<<n<<endl;
        while (n%10!=1)
        {
            n--;
            ans++;
        }
        if (n==1) return ans+1;

        long long f = flip(n);
        if (n<=f)
        {
            n--;
            ans++;
        }
        else
        {
            n=f;
            ans++;
        }
        //cout<<n<<endl;
    }

    return ans;
}

long long cntdp(long long n)
{
    vector<long long> dp (n+1);
    for (int i=1; i<=n; i++) dp[i] = i;
    for (int i=11; i<=n; i++)
    {
        dp[i] = dp[i-1]+1;
        long long f = flip(i);
        if (f<i) dp[i] = min(dp[i], dp[f]+1);
        //cout<<i<<" "<<dp[i]<<endl;
    }

    return dp[n];
}
int main()
{
    //for (int i=1; i<=32; i++) cout<<i<<" "<<cnt(i)<<endl;
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    cin>>T;
    for (int cas=1; cas<=T; cas++)
    {
        long long n;
        cin>>n;

        cout<<"Case #"<<cas<<": "<<cntdp(n)<<endl;
    }
    return 0;
}

