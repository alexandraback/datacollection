#include<bits/stdc++.h>

using namespace std;

int f[10000006], Q[10000006];

int rev(int a)
{
    int res = 0;
    while (a>0)
    {
        int t = a%10;
        res=res*10+t;
        a/=10;
    }
    return res;
}

void bfs()
{
    int l = 0, r = 0;
    memset(f,0,sizeof(f));
    f[1]=1; Q[0]=1;
    while (l<=r)
    {
        int u = Q[l++];
        if (u<10000000&&f[u+1]==0)
        {
            f[u+1]=f[u]+1;
            Q[++r]=u+1;
        }
        int v = rev(u);
        if (f[v]==0)
        {
            f[v]=f[u]+1;
            Q[++r]=v;
        }
    }
}

int main()
{
	//freopen("test.inp","r",stdin); freopen("test.out","w",stdout);
	bfs();
	int T; scanf("%d",&T);
	for(int i=1; i<=T; i++)
    {
        int N; scanf("%d",&N);
        printf("Case #%d: %d\n",i,f[N]);
    }
	//fclose(stdin); fclose(stdout);
	return 0;
}
