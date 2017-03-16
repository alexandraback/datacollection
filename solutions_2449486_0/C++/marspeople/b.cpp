#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(int)n; i++)
typedef long long int64;

int mrk[110][110], m[110][110];

int main() {
	int nt,h,w;

	scanf("%d",&nt);
	REP(ct,nt) {
		scanf("%d%d",&h,&w);

		bool deu=1;
		REP(i,h)
			REP(j,w) {
				scanf("%d",&m[i][j]);
				if (m[i][j]<=0) deu=0;
			}

		REP(ch,101) {
			memset(mrk,0,sizeof(mrk));
			
			REP(i,h) {
				bool ok=1;
				REP(j,w)
					ok&=(m[i][j]<=ch);

				if (ok)
					REP(j,w) mrk[i][j]=1;
			}
			REP(j,w) {
				bool ok=1;
				REP(i,h)
					ok&=(m[i][j]<=ch);

				if (ok)
					REP(i,h) mrk[i][j]=1;
			}

			REP(i,h)
				REP(j,w)
					deu &= (m[i][j]!=ch || mrk[i][j]);
		}

		printf("Case #%d: %s\n",ct+1,deu?"YES":"NO");
	}
	return 0;
}
