#include<bits/stdc++.h>
#define X first
#define Y second
#define INIT(x,y) memset((x),(y),sizeof(x))
using namespace std;
typedef pair<int,int> pii;
int t,ii,n,chk[2000005],x,y;
char tmp[133];
int main()
{
    freopen("A-small-attempt0.in","rb",stdin);
    freopen("output.txt","wb",stdout);
    scanf("%d",&t);
    for(ii=1;ii<=t;ii++)
    {
        scanf("%d",&n);
        INIT(chk,0);
        queue<pii> q;
        q.emplace(1,1);
        chk[1]=1;
        while(!q.empty())
        {
            x=q.front().X;
            y=q.front().Y;
            q.pop();
            if(y==n)break;
            if(!chk[y+1])
            {
                chk[y+1]=1;
                q.emplace(x+1,y+1);
            }
            sprintf(tmp,"%d",y);
            reverse(tmp,tmp+strlen(tmp));
            sscanf(tmp,"%d",&y);
            if(!chk[y])
            {
                chk[y]=1;
                q.emplace(x+1,y);
            }
        }
        printf("Case #%d: %d\n",ii,x);
    }
}
