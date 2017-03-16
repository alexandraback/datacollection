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

int n;
char s[1005];

void solve(int tc){
	scanf("%d%s", &n, s);
	int ret = 0, t = 0;
	FOE(i,0,n){
		if (t < i){
			ret += i - t;
			t = i;
		}
		t += (s[i] - '0');
	}

	printf("Case #%d: %d\n", tc, ret);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
