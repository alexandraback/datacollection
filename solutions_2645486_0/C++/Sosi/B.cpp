#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T; cin>>T;
    int dp[15][15];
    for(int t=1; t<=T; t++)
    {
        memset(dp, 0, sizeof(dp));
        int E,R,N;
        vector<int> C;
        cin>>E>>R>>N;
        int temp;
        for(int i=0; i<N; i++)
        {
            cin>>temp; C.push_back(temp);
        }
        //dp[E][0] = R;
        for(int i=0; i<C.size(); i++)
        {
            for(int k= 0; k<=E; k++) // exit k
            for(int j=0; j<=k; j++) // use j
            {
                if(k-j+R>=E) dp[E][i+1] = max(dp[E][i+1],dp[k][i] + j*C[i]);
                else
                {
                    dp[k-j+R][i+1] = max(dp[k-j+R][i+1], dp[k][i] + j*C[i]);
                }
            }
        }
        int ret = 0;
        for(int i=0; i<=E; i++) ret = max(ret, dp[i][C.size()]);
        cout<<"Case #"<<t<<": "<<ret<<endl;
    }
}
