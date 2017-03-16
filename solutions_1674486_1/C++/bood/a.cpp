#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>

using namespace std;
int t,n,s,p;
int d[1001][1001];
int m[1001][1001];
int visited[1001];
queue<int> q;
vector<int> path;
int ret;
bool visit(int c)
{
    for(int i=0;i<path.size();i++) {
        int temp = path[i];
        if(++m[temp][c]>=2) return true;
        if(visited[c])
            for(int j=1;j<=n;j++) {
                m[temp][j]+=m[c][j];
                if(m[temp][j]>=2) return true;
            }
    }
    if(!visited[c]) {
        visited[c]=1;
        path.push_back(c);
        for(int i=1;i<=n;i++) {
            if(!d[c][i]) continue;
            if(visit(i)) return true;
        }
        path.pop_back();
    }
    return false;
}
void calc()
{
    path.clear();
    path.reserve(1000);
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            m[i][j]=0;
    for(int i=1;i<=n;i++)
        visited[i]=0;
    ret = 0;
    for(int i=1;i<=n;i++) {
        if(visited[i]) continue;
        if(visit(i)) {
            ret=1;
            break;
        }
    }
}
void input()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=0;
    for(int i=1;i<=n;i++) {
        int m,j;
        cin>>m;
        while(m>0) {
            cin>>j;
            d[i][j]=1;
            m--;
        }
    }
}
void output(int ncase)
{
    printf("Case #%d: %s\n",ncase,(ret==0)?"No":"Yes");
}
int main(void)
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        input();
        calc();
        output(i+1);
    }
    return 0;
}
