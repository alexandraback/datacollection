#include<bits/stdc++.h>
using namespace std;

int t,c,d,v,arr[35],x,i,j,cnt,X;
int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {

        X++;
        scanf("%d %d %d",&c,&d,&v);
        memset(arr,0,sizeof(arr));
        arr[0]=1;
        std::queue<int>q;
        for(i=0; i<d; i++)
        {
            scanf("%d",&x);
            for(j=0; x+j<=v; j++)
                if(arr[j]==1)
                    q.push(x+j);
            while(!q.empty())
            {
                arr[q.front()]=1;
                q.pop();
            }
        }
        cnt=0;
        for(i=1; i<=v; i++)
        {
            if(arr[i]==0)
            {
                cnt++;
                for(j=0; i+j<=v; j++)
                    if(arr[j]==1)
                        q.push(i+j);
            }
            while(!q.empty())
            {
                arr[q.front()]=1;
                q.pop();
            }
        }

        printf("Case #%d: %d\n",X,cnt);
    }
    return 0;
}
