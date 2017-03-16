#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;
char s[1005];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("2.out","w",stdout);
    int t;
    int ca=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        printf("Case #%d: ",++ca);
        deque<char>q;
        for(int i=0;s[i];++i)
            if(!q.empty())
        {
            if(s[i]>=q.front())
                q.push_front(s[i]);
            else q.push_back(s[i]);
        }
        else q.push_back(s[i]);
        for(int i=0;i<q.size();++i)
            putchar(q[i]);
        puts("");

    }
}
