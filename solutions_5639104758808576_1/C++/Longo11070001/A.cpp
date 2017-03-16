#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define pb push_back
using namespace std;

const int maxn = 1010;

char str[maxn];
int n;

int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    int T,cas,ans,sum;
    scanf("%d",&T);
    for(cas=1; cas<=T; cas++)
    {
        scanf("%d%s",&n,str);
        sum = str[0]-'0';
        ans = 0;
        for(int i=1; i<=n; i++)
        {
            if(i > sum) ans += i-sum,sum=i;
            sum += str[i]-'0';
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
