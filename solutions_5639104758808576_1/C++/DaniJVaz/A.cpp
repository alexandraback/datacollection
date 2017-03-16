#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n;
		scanf("%d", &n);

		char strInput[n+1];
		scanf("%s", strInput);

		int neededFriends = 0;
		int peopleClapping = 0;
		for (int i=0; i<=n; i++) {
			if (peopleClapping < i) {
				neededFriends += (i - peopleClapping);
				peopleClapping = i;
			}

			peopleClapping += (strInput[i] - '0');
		}

		printf("Case #%d: %d\n", iC, neededFriends);
	}
	return 0;
}