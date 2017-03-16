#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
char str[1000005];
int cnt[1000005];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        int n,m;
        scanf("%s %d",str+1,&n);
        m = strlen(str+1);
        int i;
        cnt[0]=0;
        vector<int> V;
        for(i=1;i<=m;i++)
        {
            if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u')
                cnt[i] = cnt[i-1]+1;
            else cnt[i] = 0;
            if(cnt[i]==n) V.push_back(i);
        }
        long long int answer=0;
        for(i=1;i<=m-n+1;i++)
        {
            if(cnt[i+n-1]>=n)
                answer+=(long long int)(m-(i+n-1)+1);
            else
            {
                vector<int>::iterator it = upper_bound(V.begin(),V.end(),i+n-1);
                if(it!=V.end())
                answer+=(long long int)(m+1-(*it));
            }
        }
        printf("Case #%d: %lld\n",t,answer);
    }
    return 0;
}
