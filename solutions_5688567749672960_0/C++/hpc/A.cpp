#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <queue>
#define MAXN 1000002
#define INF 1000000000
using namespace std;
int N,x;
bool v[MAXN];
int ans[MAXN];
struct NODE
{
    int n,c;
}tmp;
int BFS()
{
    x=N;
    if(x<=10)
        return x;
    //map<int,int>m;
    memset(v,0,sizeof(v));
    for(int i=1;i<=10;++i) v[i]=1;
    //m[i]=1,v[i]=1;
    queue<NODE>q;
    tmp.n=10;
    tmp.c=10;
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.front();
        int n=tmp.n;
        int c=tmp.c;
        q.pop();
        tmp.n=n+1;
        tmp.c=c+1;
        if(tmp.n==N) return tmp.c;
        //if(m[tmp.n]==0)
        if(!v[tmp.n])
        {
            q.push(tmp);
            //m[tmp.n]=tmp.c;
            v[tmp.n]=1;
        }
        tmp.n=0;
        while(n)
        {
            tmp.n*=10;
            tmp.n+=n%10;
            n/=10;
        }
        if(tmp.n==N) return tmp.c;
        if(!v[tmp.n])
//if(m[tmp.n]==0)
        {
            q.push(tmp);
            //m[tmp.n]=tmp.c;
            v[tmp.n]=1;
        }
    }
}
void ini()
{
    BFS();
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int Case=1,T;
    scanf("%d",&T);
    //ini();
    while(T--)
    {
        scanf("%d",&N);
        printf("Case #%d: %d\n",Case++,BFS());
    }
    return 0;
}
