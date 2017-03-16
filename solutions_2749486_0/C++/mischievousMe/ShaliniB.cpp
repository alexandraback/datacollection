
//header files
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int limit=500;
string ans;
map<pair<int,int>,int>m;
int xx,yy;

struct node
{
    int x;
    int y;
    int steps;
    string s;
    node(int x1,int y1,int steps1,string s1)
    {
        x=x1; y=y1; s=s1; steps=steps1;
    }
};

int main()
{
    freopen("B00.in","r",stdin);
    freopen("B00.out","w",stdout);
    int t,tt=0;
    cin>>t;
    while(t--)
    {
        tt++;
        m.clear();
        cin>>xx>>yy;
        ans="";
        queue<node>q;
        q.push(node(0,0,0,""));
        while(!q.empty())
        {
            node v=q.front();
            q.pop();
            if(v.steps>500) continue;
            if(v.x==xx&&v.y==yy)
            {
                ans=v.s;
                break;
            }
            if(m[make_pair(v.x,v.y)]) continue;
            m[make_pair(v.x,v.y)]=1;
            string ss=v.s;
            ss+='E';
            q.push(node(v.x+v.steps+1,v.y,v.steps+1,ss));
            ss=v.s;
            ss+='W';
            q.push(node(v.x-v.steps-1,v.y,v.steps+1,ss));
            ss=v.s;
            ss+='N';
            q.push(node(v.x,v.y+v.steps+1,v.steps+1,ss));
            ss=v.s;
            ss+='S';
            q.push(node(v.x,v.y-v.steps-1,v.steps+1,ss));
        }
        cout<<"Case #"<<tt<<": "<<ans<<"\n";
    }
    return 0;
}
