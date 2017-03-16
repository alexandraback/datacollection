#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int tes,n,m,x,r[110],c[110];
vector<int>g[110];
bool check()
{
    memset(r,0,sizeof(r));
    memset(c,0,sizeof(c));
    for(int i=100;i>0;--i)
    {
        for(int j=0;j<g[i].size();j+=2)
            if(r[g[i][j]]&&c[g[i][j+1]])
				return false;
        for(int j=0;j<g[i].size();j+=2)
        {
            r[g[i][j]]=1;
            c[g[i][j+1]]=1;
        }
    }
    return true;
}
int main()
{
	//freopen("B-small-attempt0.in","r",stdin);
	//freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&tes);
    for(int h=1;h<=tes;++h)
    {
        for(int i=1;i<=100;++i) g[i].clear();
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                scanf("%d",&x);
                g[x].push_back(i);
				g[x].push_back(j);
            }
        }
		printf("Case #%d: ",h);
		if(!check())
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}