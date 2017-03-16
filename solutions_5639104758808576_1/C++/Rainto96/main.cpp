#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
//#include <unordered_map>
#define N 1010
using namespace std;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
void Open()
{
    //#ifndef ONLINE_JUDGE
        freopen("A-large.in","r",stdin);
        freopen("A-large.out","w",stdout);
    //#endif // ONLINE_JUDGE
}
char aud[N];
int main()
{
    Open();
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        int n;
        int ans=0;
        int exist=0;
        scanf("%d%s",&n,aud);
        for(int i=0;i<=n;i++)
        {
            int cur=aud[i]-'0';
            if(i<=exist){
                exist+=cur;
            }else{
                ans+=i-exist;
                exist+=(i-exist);
                exist+=cur;
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
