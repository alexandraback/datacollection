#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int K, C, S;
    scanf("%d %d %d",&K,&C,&S);
    for(int i = 1; i <= K; i++)
        printf("%d%c",i,i==K?'\n':' ');
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 1; i <= T; i++)
    {
        printf("Case #%d: ",i);
        solve();   
    }
    return 0;
}