#pragma comment(linker,"/STACK:102400000,102400000")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<functional>
#include<bitset>
#define N 10001
using namespace std;
const double eps=1e-9;
const double pi=acos(-1.0);
const int mod=1000000007;
int used[N],cc[N],c,d,v;
void insert(int x)
{
	int i,j;
    memset(cc,0,sizeof(cc));
    for (i=1; i<=v; i++)
        if (used[i] == 1)
            for (j=1; j<=c; j++)
                cc[j*x+i] = 1;
    for (i=1;i<=v;i++)
        if (cc[i]==1)
            used[i]=1;
    for (i=1; i<=c; i++)
        used[x*i] = 1;
}
int main()
{
    int i,t,tt=0,ans,x;
    freopen("C-small-attempt0.in","r",stdin);
	freopen("C-output.txt","w",stdout);
    scanf("%d",&t);
	while(t--)
    {
        memset(used,0,sizeof(used));
        scanf("%d%d%d", &c,&d,&v);
        for (i=0; i<d; i++)
        {
            scanf("%d",&x);
            insert(x);
        }
        ans = 0;
        for (i=1; i<=v; i++)
            if (!used[i])
            {
                ans++;
                insert(i);
            }
        printf("Case #%d: %d\n",++tt, ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
99
1 2 3
1 2
1 3 6
1 2 5
2 1 3
3
1 6 100
1 5 10 25 50 100

Case #1: 0
Case #2: 1
Case #3: 1
Case #4: 3
*/
