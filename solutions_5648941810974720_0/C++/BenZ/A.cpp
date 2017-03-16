#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int64;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define zrp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
#define foredge(i, x) for (int i = start[x]; i; i = e[i].l)
struct edge{int a, l;};
int cnt[11], num[300];
char s[2005];

int main()
{
	int T, n;
	scanf("%d", &T);
	rep(ca, T)
	{
		scanf("%s", s + 1);
		n = strlen(s + 1);
		memset(cnt, 0, sizeof(cnt));
		memset(num, 0, sizeof(num));
		rep(i, n) num[s[i]]++;
		cnt[0] = num['Z'];
	    num['Z'] -= cnt[0];
	    num['E'] -= cnt[0];
	    num['R'] -= cnt[0];
	    num['O'] -= cnt[0];
	    cnt[2] = num['W'];
	    num['T'] -= cnt[2];
	    num['W'] -= cnt[2];
	    num['O'] -= cnt[2];
	    cnt[4] = num['U'];
	    num['F'] -= cnt[4];
	    num['O'] -= cnt[4];
	    num['U'] -= cnt[4];
	    num['R'] -= cnt[4];
	    cnt[1] = num['O'];
	    num['O'] -= cnt[1];
	    num['N'] -= cnt[1];
	    num['E'] -= cnt[1];
	    cnt[3] = num['R'];
	    num['T'] -= cnt[3];
	    num['H'] -= cnt[3];
	    num['R'] -= cnt[3];
	    num['E'] -= cnt[3];
	    num['E'] -= cnt[3];
	    cnt[8] = num['G'];
	    num['E'] -= cnt[8];
	    num['I'] -= cnt[8];
	    num['G'] -= cnt[8];
	    num['H'] -= cnt[8];
	    num['T'] -= cnt[8];
	    cnt[6] = num['X'];
	    num['S'] -= cnt[6];
	    num['I'] -= cnt[6];
	    num['X'] -= cnt[6];
	    cnt[5] = num['F'];
	    num['F'] -= cnt[5];
	    num['I'] -= cnt[5];
	    num['V'] -= cnt[5];
	    num['E'] -= cnt[5];
	    cnt[7] = num['S'];
	    num['S'] -= cnt[7];
	    num['E'] -= cnt[7];
	    num['V'] -= cnt[7];
	    num['E'] -= cnt[7];
	    num['N'] -= cnt[7];
	    cnt[9] = num['E'];
	    num['N'] -= cnt[9];
	    num['I'] -= cnt[9];
	    num['N'] -= cnt[9];
	    num['E'] -= cnt[9];

	    printf("Case #%d: ", ca);
	    FOR(i, 0, 9)
	    {
	    	rep(j, cnt[i])
	    		printf("%d", i);
	    }
	    puts("");
	}
	return 0;
}
