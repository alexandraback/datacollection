#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1000005
using namespace std;
typedef long long LL;
char S[N];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t,m,n;
    scanf("%d",&t);
    for(int casenum=1;casenum<=t;casenum++)
    {
        scanf("%s",S);
        scanf("%d",&n);
        //printf("[%s %d]\n",S,n);
        m = strlen(S);
        LL lastS=-1,s=0;
        LL ans = 0;
        for(int i=0;i<m;i++)
        {
            if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u')
            {
                s = i+1;
            }
            else if(i-s==n-1)
            {
                ans += (m-i)*(s-lastS);
                lastS = s;
                s++;
            }
        }
        printf("Case #%d: %lld\n",casenum,ans);
    }
    return 0;
}
