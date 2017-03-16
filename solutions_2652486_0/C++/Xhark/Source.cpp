#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#include <stdio.h>

int dat[16];

int pduct[64][8];
string S[64];
map<string, int> mS;
map<string, map<int, int> > uS;
map<int, int> mX;

int main() {
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("C-small-1-attempt0.out","w",stdout);

	int T;
	
	scanf("%d",&T);

	while( T-- > 0 ) {
		// input
		int R,N,M,K;
		scanf("%d %d %d %d",&R,&N,&M,&K);
		// process
		for (int i=0;i<64;i++) {
			int t = i;
			vector<int> V;
			for (int j=0;j<3;j++) {
				V.push_back(t % 4 + 2);
				t /= 4;
			}
			sort(V.begin(), V.end());
			S[i] = "";
			for (int j=0;j<3;j++) {
				S[i] += (V[j] + '0');
			}
			for (int j=0;j<(1<<3);j++) {
				pduct[i][j] = 1;
				for (int k=0;k<3;k++) {
					if (j & (1<<k)) {
						pduct[i][j] *= V[k];
					}
				}
				uS[ S[i] ][ pduct[i][j] ] ++;
			}
			mS[ S[i] ] ++;
		}
		static int cs = 1;
		printf("Case #%d: \n", cs++);
		for (int i=0;i<R;i++) {
			
			map<string, int> G;
			for (map<string, int>::iterator m = mS.begin(); m != mS.end(); m ++) {
				G[m->first] = m->second;
			}
			for (int j=0;j<K;j++) {
				scanf("%d",&dat[j]);
				for (map<string, int>::iterator m = mS.begin(); m != mS.end(); m ++) {
					G[m->first] *= uS[m->first][ dat[j] ];
				}
			}
			int mmx = 0;
			string sol = "222";
			for (map<string, int>::iterator m = G.begin(); m != G.end(); m ++) {
				if (m->second > mmx) {
					sol = m->first;
					mmx = m->second;
				}
			}
			printf("%s\n",sol.c_str());
		}

	}
	return 0;
}