#include<vector>
#include<queue>
#include<map>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class point
{
public:
    int x;
    int y;
    int jump;
public:
    point(int xx,int yy,int j)
    {
        x=xx;
        y=yy;
        jump = j;
    }
    point(){}
};

#define pi pair<int,int>
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int xs,ye;
int ca=1;
map< pair<int,int>, pair<int,int> >m;
void im(int x,int y)
{
    //cout<<"x: "<<x<<" y: "<<y<<endl;
    pi aux = m[make_pair(x,y)];
    if(x == 0 && y==0) printf("Case #%d: ",ca++);
    else if(aux.second>y) {im(aux.first,aux.second);printf("S");}
    else if(aux.second<y) {im(aux.first,aux.second);printf("N");}
    else if(aux.first>x) {im(aux.first,aux.second);printf("W");}
    else if(aux.first<x) {im(aux.first,aux.second);printf("E");}
}
void Dij()
{
    queue<point>q;
    m=map< pair<int,int>, pair<int,int> >();
    q.push(point(0,0,1));
    vector<vector<long> > l(101,vector<long>(101,0));
    m[make_pair(0,0)]=make_pair(0,0);
    while(!q.empty())
    {
        point aux = q.front();
        //cout<<aux.x<<" "<<aux.y<<endl;
        q.pop();
        if(aux.x == xs && aux.y == ye){ im(xs,ye);return ;}
        for(int i=0;i<4;i++)
        {
            int u = aux.x + dx[i]*aux.jump;
            int v = aux.y + dy[i]*aux.jump;
            if(m.find(make_pair(u,v))==m.end())
            {
                q.push(point(u,v,aux.jump+1));
                m[make_pair(u,v)]=make_pair(aux.x,aux.y);
            }
        }
    }
}
int main()
{
    int n;
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&n);
    while(n-- && scanf("%d%d",&xs,&ye)){
        Dij();printf("\n");}
    return 0;
}
