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
		int prob1[a];
		int divisor = 10;
		scanf("%f", &probs[0]);
		float minStrokes = b + 2;

		exp[0] = b + a - 1 + (1.f - probs[0]) * (b + 1);
		prob1[0] = 10 * probs[0];
		//cout << exp[0] << endl;
		if(exp[0] < minStrokes)
			minStrokes = exp[0];
		for(int i = 1; i < a; i++) {
			divisor *= 10;
			scanf("%f", &probs[i]);
			prob1[i] = ((int) 10 * probs[i]) * (prob1[i-1]);
			exp[i] = a - i + b - i - 1 + ((divisor - prob1[i]) * (b + 1))/(float)divisor;
			if(exp[i] < minStrokes)
				minStrokes = exp[i];
		}

		printf("Case #%d: %.6f\n", caseNo, minStrokes);
	}
}
