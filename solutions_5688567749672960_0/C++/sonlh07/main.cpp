#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#define pb push_back
#define mp make_pair
#define pp pair<int,int>
#define ppp pair<pp,pp>
#define st first
#define nd second
typedef long long ll;
using namespace std;

int n;
int dp[1000100];

int res(int x)
{
    int ans = 0;
    while (x > 0)
    {
       ans = ans*10 + x%10;
       x = x/10;
    }
    return ans;
}

int main()
{

   freopen("A.in","r",stdin);
   freopen("A.out","w",stdout);
    for (int i = 1; i<=1000001; i++)
         dp[i] = 1000000000;
    int nTest;
    cin>>nTest;
    dp[1] = 1;
    for (int i = 1; i<=1000000; i++)
    {
        // optimal tu dp [i];
        dp[i + 1] = min(dp[i + 1],dp[i] + 1);
        int x = res(i);
        if (x <= 1000000) dp[x] = min(dp[x],dp[i] + 1);
    }

    for (int kk = 1; kk<=nTest; kk++)
    {
        cin>>n;
        cout<<"Case #"<<kk<<": "<<dp[n]<<"\n";
    }
    return 0;
}
