#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

int C, D, V;

int input[11];
bool take[31];
int ans;
bool dp[31];
int pos;

void decide()
{
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    int goal = V;
    for(int i=0; i<pos; i++)
    {
        for(int j=V; j>=input[i]; j--)
            if(!dp[j] && dp[j-input[i]])
            {
                dp[j] = true;
                goal--;
            }
        if(goal == 0)
        {
            ans = min(ans, pos - D);
            return;
        }
    }
}

void dfs(int n, int p) // p<=16, n<=5
{
    if(p == 17)
    {
        decide();
        return;
    }
    if(n > 0 && !take[p])
    {
        input[pos++] = p;
        dfs(n-1, p+1);
        pos--;
        dfs(n, p+1);
    }
    else
    {
        dfs(n, p+1);
    }
}


int main()
{
    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        cin >> C >> D >> V;
        pos = D;
        memset(take, 0,sizeof(take));
        ans = 5;
        for(int d=0; d<D; d++)
        {
            cin >> input[d];
            take[input[d]] = true;
        }
        dfs(5, 1);
        cout << "Case #" << t << ": " <<ans << endl;
    }
    return 0;
}
