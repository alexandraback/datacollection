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

double a[1111],b[1111];
int n;

int main() {	
int nt; scanf("%d", &nt); FOR(tt,1,nt+1){
	scanf("%d", &n);
	FOR(i,0,n) scanf("%lf", &a[i]);
	FOR(i,0,n) scanf("%lf", &b[i]);
	
	sort(a,a+n); sort(b,b+n);
	int ans0 = 0, ans1 = n;
	for(int w=n; w>0; w--){
		bool bad = false;
		FOR(i,0,w){
			if(a[n-w+i] < b[i]){
				bad = true;
				break;
			}
		}
		if(!bad){
			ans0 = w;
			break;
		}
	}
	
	int p = 0;
	FOR(i,0,n){
		while(p < n && b[p] < a[i]) p++;
		if(p < n){
			ans1--;
			p++;
		}
	}
	
	printf("Case #%d: %d %d\n", tt, ans0, ans1);
}	
return 0;
}


