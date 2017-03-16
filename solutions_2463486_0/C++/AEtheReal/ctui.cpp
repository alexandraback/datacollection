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

LL a,b;
int d[1111], k[1111];

int main() {
	
int nt; scanf("%d", &nt); FOR(tt,1,nt+1){
	scanf("%I64d%I64d", &a, &b);
	int ans = 0;
	for(LL x=1; ; x++){
		LL t = x; int nd = 0;
		while(t){
			d[nd++] = t % 10;
			t /= 10;
		}
		
		{
			LL y = 0;
			FOR(i,0,nd) y = y*10 + d[nd-1-i];
			FOR(i,1,nd) y = y*10 + d[i];
			y = y*y;
			if(y>b) break;
			if(y >= a && y <= b){
				int nk = 0; t = y;
				while(t){
					k[nk++] = t % 10;
					t /= 10;
				}
				bool bad = false;
				FOR(i,0,nk) if(k[i] != k[nk-1-i]) bad = true;
				if(!bad) ans++;
			}
		}
		
		{
			LL y = 0;
			FOR(i,0,nd) y = y*10 + d[nd-1-i];
			FOR(i,0,nd) y = y*10 + d[i];
			y = y*y;
			if(y >= a && y <= b){
				int nk = 0; t = y;
				while(t){
					k[nk++] = t % 10;
					t /= 10;
				}
				bool bad = false;
				FOR(i,0,nk) if(k[i] != k[nk-1-i]) bad = true;
				if(!bad) ans++;
			}
		}
	}
	
	printf("Case #%d: %d\n", tt, ans);
}	
return 0;
}


