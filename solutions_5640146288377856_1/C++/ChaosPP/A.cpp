#include <stdio.h>

int main()
{
	int T;

	scanf("%d", &T);
	for (int w = 0; w < T; w++) {
		int R, C, W;
		scanf("%d %d %d", &R, &C, &W);

		int val = R * (C / W);

		if (C % W == 0)
			val += (W - 1);
		else
			val += W;

		printf("Case #%d: %d\n", w+1, val);

	}

	return 0;
}