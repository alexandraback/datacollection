#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <utility>

using namespace std;

struct node{
    int x,y,t,r;
    node(int _x,int _y,int _t,int _r):x(_x),y(_y),t(_t),r(_r){}
};

struct node2{
    int x,y;
    node2(int _x,int _y):x(_x),y(_y){};
    node2(){node2(0,0);}
};

int x,y;
queue<node> q;
map<node2,node2> mp;
char ans[505];
int cnt;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};//N,S,E,W

bool operator<(const node2 &a,const node2 &b)
{
    if(a.x<b.x)return true;
    if(a.x==b.x && a.y<b.y)return true;
    return false;
}
void solve()
{
    node tmp(0,0,0,0);
    int tx,ty,tt;
    //cnt=-1;
    mp.clear();
    while(!q.empty())q.pop();
    q.push(node(0,0,0,0));
    bool flag=false;
    //cout<<"!"<<endl;
    while(!q.empty())
    {
        tmp=q.front();q.pop();
        //tx=tmp.x;ty=tmp.y;tt=tmp.t;
        for(int i=0;i<4;i++)
        {
            //if(flag)break;
            tt=tmp.t+1;
            tx=tmp.x+tt*dx[i];
            ty=tmp.y+tt*dy[i];
            if(tt<501)
            {
                if((tx!=0 || ty!=0) && 0==mp.count(node2(tx,ty)))
                {
                    //cout<<"push "<<" "<<tx<<" "<<ty<<" "<<tt<<" "<<i<<endl;
                    q.push(node(tx,ty,tt,i));
                    mp.insert(pair<node2,node2>(node2(tx,ty),node2(tmp.x,tmp.y)));
                    if(tx==x && ty==y)
                    {
                        cnt=tt;
                        flag=true;
                        break;
                    }
                }
            }
        }
        if(flag)break;
    }
    if(flag)
    {
        node2 temp=node2(tx,ty),temp2;
        cnt=0;
        while(temp.x!=0 || temp.y!=0)
        {
            //cout<<mp.count(temp)<<endl;
            temp2=mp[temp];
            //cout<<temp.x<<" "<<temp.y<<" : "<<temp2.x<<" "<<temp2.y<<endl;
            if(temp2.x<temp.x)ans[cnt++]='E';//E
            else if(temp2.x>temp.x)ans[cnt++]='W';//W
            else if(temp2.y<temp.y)ans[cnt++]='N';//N
            else if(temp2.y>temp.y)ans[cnt++]='S';//S
            temp=temp2;
        }
        //cout<<cnt<<endl;
        for(int i=cnt-1;i>=0;i--)
          cout<<ans[i];
        cout<<endl;
    }
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out.txt","w",stdout);
    int T;
    cin>>T;
    for(int ii=1;ii<=T;ii++)
    {
        cin>>x>>y;
        cout<<"Case #"<<ii<<": ";
        solve();
    }
    return 0;
}
