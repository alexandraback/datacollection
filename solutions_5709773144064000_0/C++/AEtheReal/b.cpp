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



int main() {	
int nt; scanf("%d", &nt); FOR(tt,1,nt+1){
	double c,f,x;
	scanf("%lf%lf%lf", &c, &f, &x);
	double t = 0.0, r = 2.0;
	double ans = 1e50;
	FOR(i,0,10000000){
		ans = min(ans, x / r + t);
		t += c/r;
		r += f;
		if(t > ans) break;
	}
	printf("Case #%d: %.7f\n", tt, ans);
}	
return 0;
}


