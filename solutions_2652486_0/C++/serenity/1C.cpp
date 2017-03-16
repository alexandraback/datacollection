/* 	Language C++
	Email xmlyqing00@gmail.com
	Copyright Liang Yongqing all
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>

using namespace std;
#define fi first
#define se second
#define ll long long
#define INF 2000000000
#define eps 1e-12
#define maxn 8

int K,n,m,tot,cnt,Max;
int a[maxn],c[maxn],b[100][maxn],s[100][10];

void dfs(int idx)
{
    int i;
    if (idx==4)
    {
        tot++;
        for (i=1;i<=3;i++) b[tot][i]=c[i];
        return;
    }

    for (i=2;i<=m;i++)
    {
        c[idx]=i;
        dfs(idx+1);
    }
}
void dfs1(int idx,int j,int sum)
{
    if (idx==4)
    {
        cnt++;
        s[j][cnt]=sum;
        return;
    }
    dfs1(idx+1,j,sum*b[j][idx]);
    dfs1(idx+1,j,sum);
}
void init()
{
    int i; tot=0;
    dfs(1);

    for (i=1;i<=tot;i++)
    {
        cnt=0;
        dfs1(1,i,1);
    }
}
int main()
{
	freopen("temp.in","r",stdin);
	freopen("temp.out","w",stdout);

    int i,j,k,Test;

    scanf("%d",&Test); printf("Case #1:\n");
    scanf("%d%d%d%d",&Test,&n,&m,&K);

    init();

    while (Test--)
    {
        Max=0;
        for (i=1;i<=K;i++) scanf("%d",&a[i]);
        for (i=1;i<=K;i++) Max=max(Max,a[i]);

        if (Max==1) {printf("234\n"); continue;}

        for (i=1;i<=tot;i++)
        {
            for (j=1;j<=K;j++)
            {
                for (k=1;k<=cnt;k++) if (s[i][k]==a[j]) break;
                if (k>cnt) break;
            }
            if (j>K)
            {
                for (j=1;j<=3;j++) printf("%d",b[i][j]);
                printf("\n");
                break;
            }
        }
        if (i<=tot) continue;
        printf("234\n");
    }
	return 0;
}
