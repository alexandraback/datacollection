#include <iostream>
#include <string.h>
#include <stdio.h>
#include<algorithm>
using namespace std;
int a, b, k;
struct Node
{
    int id;
    string posid;
    bool operator<(const Node &p)const
    {
        return posid<p.posid;
    }
}nodes[50];
int edges[10][10];
int n,m;
int cnt;
bool dfs(int v)
{
    int id=nodes[v].id;
    cnt++;
    if(cnt==n)return true;
    while(1)
    {
        int w=cnt;
        if(edges[id][nodes[cnt].id])
        {
            if(dfs(cnt))return true;
        }
        if(w==cnt)return false;
    }

}
bool solve()
{

    cnt=0;
    if(dfs(0))return true;

    return false;

}
int main()
{
    freopen("C.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; ++cas)
	{
	    printf("Case #%d: ",cas);
		cin>>n>>m;
		for(int i=1;i<=n;++i)
		{
		    string x;
		    cin>>x;
		    nodes[i-1].id=i;
		    nodes[i-1].posid=x;
		}
		sort(nodes,nodes+n);
		memset(edges,0,sizeof(edges));
		for(int i=0;i<m;++i)
		{
		    int x,y;
		    scanf("%d%d",&x,&y);
		    edges[x][y]=edges[y][x]=1;
		}
		do
		{
            if(solve())
            {
                for(int i=0;i<n;++i)
                {
                    cout<<nodes[i].posid;
                }
                cout<<endl;
                break;
            }
		}while(next_permutation(nodes,nodes+n));
	}
	return 0;
}
