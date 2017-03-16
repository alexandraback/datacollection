#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		char arr[2000];
		scanf("%s", arr);

		string S = arr;
		string best, prev="";
		for (unsigned i=0; i<S.size(); i++) {
			best = S[i] + prev;
			if (best < prev + S[i])
				best = prev + S[i];
			prev = best;
		}

		printf("Case #%d: %s\n", iC, best.c_str());
	}
	return 0;
}