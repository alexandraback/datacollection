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

int p10[20];

int main() {

	p10[0] = 1; FOR(i,1,20) p10[i] = p10[i-1]*10;

int nt, tt=0; scanf("%d", &nt); while(nt--){
	int a,b;
	scanf("%d%d", &a, &b);

	int nd = 0;
	int ta = a; while(ta > 0) { ta /= 10; nd ++; }

	int ans = 0;
	FOE(k,a,b){
		set<int> vis;
		FOR(n, 1, nd){
			int k2 = (k % p10[n]) * p10[nd-n] + (k / p10[n]);
			if( k2 > k && k2 >= a && k2 <= b && vis.find(k2) == vis.end()){
				ans++;
				vis.insert(k2);
			}
		}
	}

	printf("Case #%d: %d\n", ++tt, ans);
}
	return 0;
}


