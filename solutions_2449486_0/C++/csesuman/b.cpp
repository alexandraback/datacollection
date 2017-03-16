#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

#define MX 100 + 10

struct DT{

    int x,y;
    int sz;

    void set(int a,int b,int c)
    {
        x  = a;
        y  = b;
        sz = c;
    }

    bool operator<(const DT &b) const
    {
        return sz>b.sz;
    }
} ob;

//codejam
priority_queue<DT>pq;
int lawn[MX][MX],row,col,val;
bool chk,r,c,vis[MX][MX];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);

    int t,n,m,cc=1;

    cin>>t;

    while(t--)
    {
        memset(vis,false,sizeof(vis));
        cin>>n>>m;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>lawn[i][j];
                ob.set(i,j,lawn[i][j]);
                pq.push(ob);
            }
        }

        chk = true;

        while(!pq.empty())
        {
            ob = pq.top();
            pq.pop();


            val = ob.sz;
            row = ob.x;
            col = ob.y;

//            cout<<"s " <<val<<endl;

            if(vis[row][col]) continue;

            r = true;

            for(int i=1;i<=m;i++)
            {
                if(!vis[row][i] && lawn[row][i]>val)
                {
                    r = false;
                    break;
                }
            }

            if(r){
            for(int i=1;i<=m;i++)
                vis[row][i] = true;
            }

            c = true;

            for(int i=1;i<=n;i++)
            {
                if(!vis[i][col] && lawn[i][col]>val)
                {
                    c = false;
                    break;
                }
            }

            if(c){
                for(int i=1;i<=n;i++)

                    vis[i][col] = true;
            }

            if(!(c||r)) {chk = false; break;}
        }

        cout<<"Case #"<<cc++<<": ";

        if(chk) cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;


        while(!pq.empty()) pq.pop();
    }

    return 0;
}
