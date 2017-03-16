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
#define maxn 15

int E,R,n,v[maxn];

ll dfs(int idx,int rest)
{
    if (idx==n+1) return 0;

    int i; ll ans=0;
    for (i=0;i<=rest;i++)
    {
        ans=max(ans,i*v[idx]+dfs(idx+1,min(rest-i+R,E)));
    }
    return ans;
}
int main()
{
    freopen("temp.in","r",stdin);
	freopen("temp.out","w",stdout);

    int Test,test,i;

    scanf("%d",&Test); test=0;
    while (Test--)
    {
        printf("Case #%d: ",++test);

        scanf("%d%d%d",&E,&R,&n);
        for (i=1;i<=n;i++) scanf("%d",&v[i]);

        ll ans=dfs(1,E);
        cout<<ans<<endl;
    }
	return 0;
}
