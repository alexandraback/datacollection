#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T, A, B;
	float keystrokes, minimum, expected;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		keystrokes = 0.0;
		float product = 1.0;
		expected = 0.0;
		scanf("%d %d", &A, &B);
		float *prob = (float *)calloc(sizeof(float), A+1);
		for (int j = 1; j <= A; j++)
				scanf("%f", &prob[j]);
	/*	for (int j = 1; j <= A; j++)
				printf("%f ", prob[j]);
		printf("\n"); */
		prob[0] = 1.0;
		minimum = (float)(B + 2);
		for (int backspace = A, j = 0; backspace >= 0; backspace--, j++)
		{
				product = product * prob[j];
				expected = product * ((float)(2*backspace + (B - A + 1))) + (1.0 - product)*((float)(2*backspace + (B - A + 1) + B + 1));
				//printf("expected is %0.6f\n", expected);
				if (expected < minimum)
					minimum = expected;
		}
		printf("Case #%d: %0.6f\n", i, minimum);
	}

}
