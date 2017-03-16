#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8

int check(int x)
{
    set <int>s;
    for(int i=1;i<=100000;i++)
    {
        long long t=(long long)i*x;
        while(t)
        {
            s.insert(t%10);
            t/=10;
        }
        if(s.size()==10)
            return i;
    }
    return -1;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        int ans=check(n);
        printf("Case #%d: ",cas);
        if(ans==-1)
        {
            printf("INSOMNIA\n");
        }
        else
            printf("%I64d\n",(long long)ans*n);
    }
    return 0;
}
