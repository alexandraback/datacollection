#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
#include "deque"
using namespace std;
typedef long long i64;

vector<vector<int> > in;
vector<set<int> > parents;

bool digg(int cur, int parent)
{
	fprintf(stderr, "%d %d\n", parent, cur);
	if (parents[cur].insert(parent).second == false) {
		return true;
	}
	for (int i=0;i<in[cur].size();++i) {
		if (digg(in[cur][i], parent)) return true;
	}
	return false;
}

int main() {
	int T; scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti) {
		fprintf(stderr, "Case #%d of %d...\n", Ti, T);

		int N;
		scanf("%d", &N);
		in.clear();
		in.resize(N);
		parents.clear();
		parents.resize(N);

		for (int c=0;c<N;++c) {
			int M;
			scanf("%d", &M);
			for (int i=0;i<M;++i) {
				int base;
				scanf("%d", &base);
				in[base-1].push_back(c);
			}
		}

		bool b=false;
		for (int c=0;c<N;++c) {
			if (digg(c, c)) {
				b=true;
				break;
			}
		}


		printf("Case #%d: %s\n", Ti, (b?"Yes":"No"));
	}
	return 0;
}
