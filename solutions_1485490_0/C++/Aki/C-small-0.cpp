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
using namespace std;
typedef long long i64;

struct LI {
	i64 num;
	int type;
};

typedef deque<LI> vLI;

i64 send(vLI box, vLI toy)
{
	if (box.empty() || toy.empty()) return 0;
	
	if (box[0].type == toy[0].type) {
		i64 n = min(box[0].num, toy[0].num);
		box[0].num -= n;
		if (box[0].num == 0) box.pop_front();
		toy[0].num -= n;
		if (toy[0].num == 0) toy.pop_front();
		return n + send(box, toy);
	}

	i64 n0 = 0;
	for (int i=1;i<box.size();++i) {
		if (box[i].type == toy[0].type) {
			vLI tmp_box(box.begin() + i, box.end());
			n0 = send(tmp_box, toy);
			break;
		}
	}

	i64 n1=0;
	for (int i=1;i<toy.size();++i) {
		if (box[0].type == toy[i].type) {
			vLI tmp(toy.begin() + i, toy.end());
			n1 = send(box, tmp);
			break;
		}
	}

	return max(n0,n1);
}

int main() {
	int T; scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti) {
		fprintf(stderr, "Case #%d of %d...\n", Ti, T);


		int N, M;
		scanf("%d %d", &N, &M);
		vLI box(N);
		vLI toy(M);
		for (int i=0;i<N;++i) {
			scanf("%lld %d", &box[i].num, &box[i].type);
		}
		for (int i=0;i<M;++i) {
			scanf("%lld %d", &toy[i].num, &toy[i].type);
		}

		i64 y = send(box, toy);
		printf("Case #%d: %lld\n", Ti, y);
	}
	return 0;
}
