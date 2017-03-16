#include <cstdio>

void printChain(int * previous, int sum) {
	printf("%d", previous[sum]);
	sum -= previous[sum];

	while (sum != 0) {
		printf(" %d", previous[sum]);
		sum -= previous[sum];
	}
	printf("\n");
}

bool recCall(int * numbers, int n, int * previous, int ind, int sum) {
	if (ind == n)
		return false;

	if (previous[sum + numbers[ind]] != -1) { /* This sum has already been found */
		printChain(previous, sum + numbers[ind]);
		previous[sum + numbers[ind]] = numbers[ind];
		printChain(previous, sum + numbers[ind]);
		return true;
	}

	previous[sum + numbers[ind]] = numbers[ind];

	if (recCall(numbers, n, previous, ind+1, sum))
		return true;
	if (recCall(numbers, n, previous, ind+1, sum + numbers[ind]))
		return true;

	return false;
}

int main() {
	int iC, nC;
	scanf("%d", &nC);
	for (iC = 1; iC <= nC; iC++) {
		int n, s = 0;
		scanf("%d", &n);
		int numbers[n];

		for (int i=0; i<n; i++) {
			scanf("%d", numbers + i);
			s += numbers[i];
		}

		int * previous = new int[s+1];
		for (int i=0; i<=s; i++) {
			previous[i] = -1;
		}

		previous[0] = 0;
		printf("Case #%d:\n", iC);
		if (!recCall(numbers, n, previous, 0, 0))
			printf("Impossible\n");
		delete previous;
	}
	return 0;
}
