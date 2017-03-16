#include<bits/stdc++.h>

using namespace std;

int N, S;
int Q[1000006], h[1000006], pw[10], A[10], p[10];

void nhap()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++) scanf("%d",&A[i]);
    S=0;
    for(int i=1; i<=N; i++) S+=A[i]*pw[i-1];
}

void bfs()
{
    memset(h,255,sizeof(h));
    h[S]=0;
    int l=0, r=0; Q[0]=S;
    while (l<=r)
    {
        int u=Q[l++], v;
        cout<<u<<' '<<h[u]<<endl;
        for(int i=1; i<=N; i++) p[i]=(u/pw[i-1])%10;
        v=0; for(int i=1; i<=N; i++) v+=(max(p[i]-1,0)*pw[i-1]);
        if (h[v]==-1)
        {
            h[v]=h[u]+1;
            Q[++r]=v;
        }
        v=0; for(int i=1; i<=N; i++) v+=(p[i]*pw[i-1]);
        for(int i=1; i<=N; i++)
        if (p[i]>0)
        {
            int t = v;
            t-=(p[i]*pw[i-1]);
            t+=((p[i]-p[i]/2)*pw[i-1]);
            if (h[t]==-1)
            {
                h[t]=h[u]+1;
                Q[++r]=t;
            }
        }
    }
}

int main()
{
	freopen("test.inp","r",stdin); freopen("test.out","w",stdout);
	pw[0]=1;
	for(int i=1; i<=9; i++) pw[i]=pw[i-1]*10;
	int T; scanf("%d",&T);
	for(int i=1; i<=T; i++)
    {
        nhap();
        bfs();
        printf("Case #%d: %d\n",i,h[0]);
    }
	fclose(stdin); fclose(stdout);
	return 0;
}
