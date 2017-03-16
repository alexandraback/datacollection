#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;

typedef unsigned long long ull;
int T, k;

map<int,int> m01, m02, m12;
int a[5], p[5];
int ans[10000][5];
int cnt;
void dfs(int x)
{
    if (x == 3)
    {
        int p01 = p[0] * 100 + p[1];
        int p02 = p[0] * 100 + p[2];
        int p12 = p[1] * 100 + p[2];
        //printf("P %d %d %d\n", p01, p02, p12);
        if (m01[p01] < k && m02[p02] < k && m12[p12] < k)
        {
            m01[p01]++;
            m02[p02]++;
            m12[p12]++;
            ans[cnt][0] = p[0];
            ans[cnt][1] = p[1];
            ans[cnt][2] = p[2];
            cnt++;
            //printf("+ ");
        }
        /*else
        {
            printf("- ");
        }
        printf("%d %d %d\n", p[0], p[1], p[2]);*/
        return;
    }
    for (int i = 1; i <= a[x]; i++)
    {
        p[x] = i;
        dfs(x + 1);
    }
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    //freopen("B-large.in","r",stdin);
    freopen("a.txt","w",stdout);
    scanf("%d", &T);
	for (int cse = 1; cse <= T; cse++)
	{
	    m01.clear();
	    m02.clear();
	    m12.clear();
	    cnt = 0;
	    int x, y, z;
	    scanf("%d %d %d %d", &x, &y, &z, &k);
	    a[0] = x;
	    a[1] = y;
	    a[2] = z;
	    dfs(0);
	    printf("Case #%d: %d\n", cse, cnt);
	    for (int i = 0; i < cnt; i++)
            printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
	}
	return 0;
}
