#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct {
	int s;
	int ss;
} str;

int recursion(vector <str> v, int numStages, int *numStars, int *ans) {
	int aux, i;
//printf("%d = %d?\n",*numStars, numStages*2);
	if (*numStars == numStages * 2)
		return 0;

	for (i = 0; i < numStages; i++) {
		if (v[i].ss != -1 && v[i].ss <= *numStars) {
			v[i].ss = -1;
			(*numStars)++;
			if (v[i].s != -1) {
				v[i].s = -1;
				(*numStars)++;
			}
			aux = recursion(v, numStages, numStars, ans);
			break;
		}
	}

	if (aux == -1)
		return -1;
	else if (i < numStages) {
		(*ans)++;
		return 0;
	}

	for (i = numStages-1; i >= 0; i--) {
		if (v[i].s != -1 && v[i].s <= *numStars) {
			v[i].s = -1;
			(*numStars)++;
			aux = recursion(v, numStages, numStars, ans);
			break;
		}
	}

	if (aux == -1 || i == -1)
		return -1;

	(*ans)++;
	return 0;
}

bool mySort(str v1, str v2) {
	return (v1.ss < v2.ss || v1.ss == v2.ss && v1.s < v2.s);
}

int main() {
	int N;
	scanf("%d", &N);

	for (int C = 1; C <= N; C++) {
		int N;
		vector <str> v;
		int aux, numStars, ans;

		scanf("%d", &N);

		v = vector <str> (N);

		for (int i = 0; i < N; i++) {
			scanf("%d %d", &v[i].s, &v[i].ss);
		}

		sort(v.begin(), v.end(), mySort);

		ans = 0;
		numStars = 0;
		aux = recursion(v, N, &numStars, &ans);

		if (aux != -1)
			printf("Case #%d: %d\n", C, ans);
		else
			printf("Case #%d: Too Bad\n", C);
	}

	return 0;
}

