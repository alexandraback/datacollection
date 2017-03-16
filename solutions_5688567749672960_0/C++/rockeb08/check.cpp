#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<climits>
#include<stack>
using namespace std;
typedef long long int ll;
bool visited[1000005]={0};
int main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    ll tc,val,t,val2,cnt,n,ans,tmp;
    cin>>tc;
    for(t=1;t<=tc;t++)
    {
        queue< pair<ll ,ll > > q;
        cin>>n;
        memset(visited,0,sizeof(visited));
        q.push(make_pair(1,1));
        visited[1]=1;
        while(!q.empty())
        {
            pair<ll,ll> p;
            p=q.front();
            val=p.first;
            cnt=p.second;
            q.pop();
            if(val==n)
            {
                ans=cnt;
                break;
            }
            else
            {
                if(visited[val+1]==0)
                {
                    visited[val+1]=1;
                    q.push(make_pair(val+1,cnt+1));
                }
                tmp=val;
                val2=0;
                while(tmp>0)
                {
                    val2=(val2*10)+(tmp%10);
                    tmp/=10;
                }
                if(visited[val2]==0)
                {
                    visited[val2]=1;
                    q.push(make_pair(val2,cnt+1));
                }

            }
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}
