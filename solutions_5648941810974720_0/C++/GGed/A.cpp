#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

char s[2005]; int a[100], cnt[300];


int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
	scanf("%s", s);
	CLR(cnt, 0);
	CLR(a, 0);
	for (int i=0;s[i];i++) cnt[s[i]]++;
	a[0] = cnt['Z'];
	a[2] = cnt['W'];
	a[4] = cnt['U'];
	a[3] = cnt['R'] - a[4] - a[0];
	a[6] = cnt['X'];
	a[7] = cnt['S'] - a[6];
	a[8] = cnt['G'];
	a[5] = cnt['V'] - a[7];
	a[1] = cnt['O'] - a[0] - a[2] - a[4];
	a[9] = cnt['I'] - a[5] - a[6] - a[8];
	
	FOR(i,0,10) FOR(j,0,a[i]) printf("%d", i);
	puts("");
}return 0;}
