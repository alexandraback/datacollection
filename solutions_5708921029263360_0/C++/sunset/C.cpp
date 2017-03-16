#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Record {
	int j, p, s;
	Record(int j, int p, int s)
	:j(j), p(p), s(s) {}
};
int JP[14][14], JS[14][14], PS[14][14];

int main() {
	int T;
	scanf("%d", &T);
	for(int NOWCASE=1; NOWCASE<=T; ++NOWCASE) {
		int J, P, S, K;
		scanf("%d%d%d%d", &J, &P, &S, &K);
		vector<Record> record;
		memset(JP, 0, sizeof(JP));
		memset(JS, 0, sizeof(JS));
		memset(PS, 0, sizeof(PS));
		for(int i=1; i<=J; ++i)
		for(int j=1; j<=P; ++j)
		for(int t=1; t<=S; ++t)
		if( JP[i][j]<K && JS[i][t]<K && PS[j][t]<K ) {
			++JP[i][j];
			++JS[i][t];
			++PS[j][t];
			record.emplace_back(Record(i,j,t));
		}
		printf("Case #%d: %d\n", NOWCASE, (int)record.size());
		for(int i=0; i<record.size(); ++i)
			printf("%d %d %d\n", record[i].j, record[i].p, record[i].s);
	}
	return 0;
}
