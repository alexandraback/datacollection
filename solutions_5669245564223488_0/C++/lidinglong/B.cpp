#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
const long long mo = 1000000007;

using namespace std;

void fileOpen()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int rd[30], cd[30], e[30], X[30], flag, bj[30];
char st[110][110];

void link(int u, int v)
{
    rd[v]++, cd[u]++;
    if (rd[v] > 1) flag = 1;
    if (cd[u] > 1) flag = 1;
    e[u] = v;
}

long long jc(int x)
{
    long long tmp = 1;
    for (int i = 2; i <= x; ++i)
	tmp = tmp * i % mo;
    return tmp;
}

int main()
{
    fileOpen();
    int task;
    scanf("%d\n", &task);
    for (int t = 1; t <= task; ++t)
    {
	printf("Case #%d: ", t);
	int n;
	scanf("%d\n", &n);
	for (int i = 1; i < n; ++i)
	    scanf("%s ", st[i]);
	scanf("%s\n", st[n]);
	for (int i = 0; i < 26; ++i)
	    e[i] = -1;
	memset(rd, 0, sizeof(rd));
	memset(cd, 0, sizeof(cd));
	memset(X, 0, sizeof(X));
	long long ans = 1;
	flag = 0;
	for (int i = 1; i <= n; ++i)
	{
	    int len = strlen(st[i]), l, r;
	    for (l = 0; st[i][l + 1] == st[i][l]; ++l);
	    if (l == len - 1) 
	    {
		++X[st[i][0] - 'a'];
		continue;
	    }
	    for (r = len - 1; st[i][r - 1] == st[i][r]; --r);
	    if (r == l + 1) link(st[i][0] - 'a', st[i][len - 1] - 'a');
	    else flag = 1;
	    if (flag) break;
	}
	memset(bj, 0, sizeof(bj));
	int tot = 0, cirnum = 0;
	for (int i = 0; i < 26; ++i)
	    if (X[i]) ans = ans * jc(X[i]) % mo;
	int cirjs = 0;
	for (int i = 0; i < 26; ++i)
	    if (!bj[i])
	    {
		if (rd[i] + cd[i] == 0)
		{
		    if (X[i]) ++tot;
		    continue;
		}
		cirjs++;
		int p = i;
		bj[i] = 1;
		for(;;)
		{
		    int q = e[p];
		    if (bj[q])
		    {
			++cirnum;
			++tot;
			break;
		    }
		    if (q == -1)
		    {
			++tot;
			break;
		    }
		    p = q;
		    bj[p] = 1;
		    ++cirjs;
		}
	    }
	if (cirnum > 1) flag = 1;
	else if (cirnum == 1)
	{
	    for (int i = 0; i < 26; ++i)
		if (X[i] && (!bj[i])) flag = 1;
	    ans = ans * cirjs % mo;
	} else ans = ans * jc(tot) % mo;
	if (flag) printf("0\n");
	else cout << ans << endl;
    }
    return 0;
}
