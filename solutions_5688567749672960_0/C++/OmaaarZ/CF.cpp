#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#define mod 1000000007
#define M_PI 3.14159265358979323846
using namespace std;
int dp[1000010];
int main()
{
   freopen("A-small-attempt3.in","r",stdin);
    freopen("output.in","w",stdout);
    cin.sync_with_stdio(false);
    int t ;
    int tc=1;
    cin >> t;
    memset(dp,-1,sizeof dp);
    while(t--)
    {
        long long n;
        cin >> n;
        int counter = 1;
        int start=1;
        dp[1]=0;
        for(int i = 2;i<=n;i++)
        {
            if(dp[i]!=-1)
                continue;
                stringstream ss;
            ss << i;
        string str = ss.str();
        reverse(str.begin(),str.end());
        stringstream sstr(str);
        long long temp;
        sstr>>temp;
            dp[i]=1+dp[i-1];

            if(temp<i && str[0]!='0')
                dp[i]=min(dp[i],1+dp[temp]);

        }
        cout << "Case #" <<tc++ <<": "<<1+dp[n] <<endl;
    }
    return 0;
}


