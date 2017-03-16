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

int main() {
	int v[10], pr[200], p[10];
	int nt,r,n,m,k;

	scanf("%d",&nt);
	REP(ct,nt) {
		scanf("%d%d%d%d",&r,&n,&m,&k);
		printf("Case #%d:\n",ct+1);

		while (r--) {
			REP(i,k)
				scanf("%d",&p[i]);

			string sr="222";
			int res=0;
			REP(mbn,(1<<(2*n))) {
				string ri;
				for (int i=0, x=mbn; i<n;i++, x/=4) {
					v[i]=x%4+2;
					ri+='0'+v[i];
				}

				memset(pr,0,sizeof(pr));
				REP(mbs,(1<<n)) {
					int p=1;
					REP(i,n)
						if (mbs & (1<<i)) p*=v[i];

					pr[p]++;
				}

				int tp=1;
				REP(i,k)
					tp*=pr[p[i]];

				if (tp>res) {
					res=tp;
					sr=ri;
				}
			}

			cout << sr << endl;
		}
	}
				
	return 0;
}

