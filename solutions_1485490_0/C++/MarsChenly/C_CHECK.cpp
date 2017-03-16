#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

long long n,m,ans;

struct dians
{	long long num,id;
}alice[105],bob[105];



void dfs(int x,int y,long long z)
{
     if (z>ans) ans=z;
     if (x>=n || y>=m) return;
     if (alice[x].id==bob[y].id)
	 {
        if (alice[x].num==bob[y].num)
		{
           dfs(x+1,y+1,z+alice[x].num);
        } else
        if (alice[x].num>bob[y].num)
		{
           alice[x].num-=bob[y].num;
           dfs(x,y+1,z+bob[y].num);
           alice[x].num+=bob[y].num;
        } else
           {
           bob[y].num-=alice[x].num;
           dfs(x+1,y,z+alice[x].num);
           bob[y].num+=alice[x].num;
           }
        }else
        {
             dfs(x+1,y,z);
             dfs(x,y+1,z);
        }
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int task;
    cin>>task;
    for (int cases=1;cases<=task;cases++)
    {
        cin>>n>>m;
        for (int i=0;i<n;i++) 
            cin>>alice[i].num>>alice[i].id;
        for (int i=0;i<m;i++) 
            cin>>bob[i].num>>bob[i].id;
        ans=0;
        dfs(0,0,0);
        cout<<"Case #"<<cases<<": "<<ans<<endl;
    }
    return 0;
}
