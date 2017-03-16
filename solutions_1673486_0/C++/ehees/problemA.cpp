#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int main() {
	int numCases;
	scanf("%d", &numCases);
	for(int caseNo = 1; caseNo <= numCases; caseNo++) {
		int a, b;
		scanf("%d %d", &a, &b);

		float probs[a], dels[a], exp[a];
		scanf("%f", &probs[0]);
		float minStrokes = b + 2;

		exp[0] = b + a - 1 + (1.f - probs[0]) * (b + 1);
		//cout << exp[0] << endl;
		if(exp[0] < minStrokes)
			minStrokes = exp[0];
		for(int i = 1; i < a; i++) {
			scanf("%f", &probs[i]);
			probs[i] *= probs[i - 1];
			exp[i] = a - i + b - i - 1 + ((1.f - probs[i]) * (b + 1));
			if(exp[i] < minStrokes)
				minStrokes = exp[i];
		}

		printf("Case #%d: %.6f\n", caseNo, minStrokes);
	}
}
