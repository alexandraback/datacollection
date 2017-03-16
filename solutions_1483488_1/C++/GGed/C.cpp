#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

int tc_, n, m, x, l, ret;
int v[2000005];
char s[20];

int main(){
	scanf("%d", &tc_);
	FOE(tc,1,tc_){
		scanf("%d%d", &n, &m);
		ret = 0;
		CLR(v, 0);

		FOE(i,n,m){
			sprintf(s, "%d", i);
			l = strlen(s);
			FOR(j,0,l){
				rotate(s, s + 1, s + l);
				sscanf(s, "%d", &x);
				if (x > i && x <= m && v[x] != i) ret++, v[x] = i;
			}
		}

		printf("Case #%d: %d\n", tc, ret);
	}
	return 0;
}
