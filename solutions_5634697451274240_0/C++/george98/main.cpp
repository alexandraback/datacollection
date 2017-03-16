#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char sir[110];

int solve(char sir[])
{
    int n=strlen(sir+1),sol=0;
    if(sir[1]=='-') sol=1;
    for(int i=1;i<n;i++)
        if(sir[i]=='+' && sir[i+1]=='-') sol+=2;
    return sol;
}

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        scanf("%s",sir+1);
        int n=strlen(sir+1);
        int sol=solve(sir);
        for(int i=1;i<=n;i++)
            if(sir[i]=='-') sir[i]='+';
            else sir[i]='-';
        sol=min(sol,1+solve(sir));
        printf("Case #%d: %d\n",t,sol);
    }
    return 0;
}
