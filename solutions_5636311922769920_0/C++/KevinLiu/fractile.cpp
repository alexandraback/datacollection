#include <stdio.h>
#include <vector>
using namespace std;

vector<int> fractile(const int K, const int C, const int S)
{
	vector<int> result;
	int i;

	if (S<K-1) {
		return result;
	}

	if (C==1 || K==1) {
		if (S==K) {
			result.resize(K);
			for (i=0;i<K;i++) {
				result[i]=i+1;
			}
		}
		return result;
	}

	result.resize(K-1);
	for (i=0;i<K-1;i++) {
		result[i]=i+2;
	}

	return result;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i=0;i<T;i++) {
		int K,C,S;
		vector<int> result;

		scanf("%d %d %d", &K, &C, &S);
		printf("Case #%d:", i+1);
		result = fractile(K,C,S);

		if (result.empty()) {
			printf(" IMPOSSIBLE\n");
		} else {
			for (int i=0;i<result.size();i++) {
				printf(" %d", result[i]);
			}
			printf("\n");
		}
	}
}
