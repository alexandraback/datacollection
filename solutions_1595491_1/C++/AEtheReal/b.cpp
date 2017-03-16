#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

int n,s,p;
int a[11111];

int main() {

int nt, tt=0; scanf("%d", &nt); while(nt--){
	scanf("%d%d%d", &n, &s, &p);
	FOR(i,0,n) scanf("%d", &a[i]);
	int ans = 0;
	FOR(i,0,n){
		int cs = (a[i]+2) / 3;
		int ms;
		if(a[i] <= 0) ms = 0;
		else ms = min((a[i]+4) / 3, 10);
		if(cs >= p) ans++;
		else if(s>0 && ms >= p){
			ans ++;
			s --;
		}
	}

	printf("Case #%d: %d\n", ++tt, ans);
}
	return 0;
}


