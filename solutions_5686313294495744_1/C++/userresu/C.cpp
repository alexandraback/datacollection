//Used http://stanford.edu/~liszt90/acm/notebook.html#file5
#include <vector>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

map<string,int> M1, M2;
string s1, s2;
char tmp[30];
int main () {
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		M1.clear();
		M2.clear();
		int N;
		scanf("%d",&N);
		vector<pair<int,int> > edge;
		int a = -1, b = -1;
		for (int i=0;i<N;++i) {
			s1.clear(), s2.clear();
			scanf("%s",tmp);
			int n = strlen(tmp);
			for (int j=0;j<n;++j) s1 += tmp[j];
			scanf("%s",tmp);
			n = strlen(tmp);
			for (int j=0;j<n;++j) s2 += tmp[j];

			map<string,int>::iterator I = M1.find(s1);
			if (I == M1.end()) M1[s1] = ++a;
			I = M2.find(s2);
			if (I == M2.end()) M2[s2] = ++b;
			edge.push_back(make_pair(M1[s1],M2[s2]));
		}
		VVI w(a+1);
		for (int i=0;i<=a;++i) for (int j=0;j<=b;++j) w[i].push_back(0);
		for (int i=0;i<edge.size();++i) w[edge[i].first][edge[i].second] = 1;
		VI mr, mc;
		printf("Case #%d: %d\n",z,N- (a+b+2) + BipartiteMatching(w,mr,mc));
	}
	return 0;
}
