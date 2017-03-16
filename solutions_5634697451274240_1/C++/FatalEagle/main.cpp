#include <bits/stdc++.h>

using namespace std;

int N;
char S[100001];

int solve(int pos, char want)
{
    if(pos<0)
        return 0;
    if(S[pos]==want)
        return solve(pos-1, want);
    return solve(pos-1, want^'+'^'-')+1;
}

void _main(int TEST)
{
    scanf("%s", S);
    N=strlen(S);
    printf("%d\n", solve(N-1, '+'));
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        printf("Case #%d: ", i);
        _main(i);
    }
    return 0;
}
