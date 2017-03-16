#include <bits/stdc++.h>
using namespace std;

int M[4][4] = {1, 2, 3, 4,
               2,-1, 4,-3,
               3,-4,-1, 2,
               4, 3,-2,-1};

int mul(int i, int j)
{
    int ans = M[abs(i)-1][abs(j)-1];
    if(i < 0)
        ans *= -1;
    if(j < 0)
        ans *= -1;
    return ans;
}

string s;
int dp[10005][3];
int n;

int solve(int pos, int cant)
{
    if(pos == n && cant == 3) return 1;
    if(pos == n && cant != 3) return 0;
    if(cant >= 3) return 0;
    if(dp[pos][cant] != -1) return dp[pos][cant];

    int ans = 0;
    int cur = 1;
    for(int i = pos; i < n && !ans; i++)
    {
        cur = mul(cur, (s[i] == 'i')? 2 : ((s[i] == 'j')? 3 : 4));
        if(cant == 0 && cur == 2 && solve(i + 1, cant + 1))
            ans = 1;
        else if(cant == 1 && cur == 3 && solve(i + 1, cant + 1))
            ans = 1;
        else if(cant == 2 && cur == 4 && solve(i + 1, cant + 1))
            ans = 1;
    }
    return dp[pos][cant] = ans;
}

int main()
{
    int T,L,X,ntest=1;
    string aux;
    char cad[10005];
    scanf("%d\n",&T);
    while(T--)
    {
        scanf("%d %d\n",&L,&X);
        scanf("%s\n",cad);
        aux = string(cad);
        s = "";
        for(int i = 0; i < X; i++)
            s += aux;
        memset(dp, -1, sizeof dp);
        n = (int)s.size();
        printf("Case #%d: %s\n",ntest++, solve(0,0)? "YES" : "NO");
    }
    return 0;
}
