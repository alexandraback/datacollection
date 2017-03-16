#include <stdio.h>

int main() {
	int T, R, C, M, i, j, k;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %d %d", &R, &C, &M);
		printf("Case #%d:\n", i + 1);
		if (R == 1) {
			for (j = 0; j < M; j++)
				printf("*");
			for (j = 0; j < C - M - 1; j++)
				printf(".");
			printf("c\n");
		} else if (C == 1) {
			for (j = 0; j < M; j++)
				printf("*\n");
			for (j = 0; j < R - M - 1; j++)
				printf(".\n");
			printf("c\n");
		} else if (R == 2) {
			if (M % 2 == 0 && M <= R * C - 4) {
				for (j = 0; j < M / 2; j++)
					printf("*");
				for (j = 0; j < C - M / 2; j++)
					printf(".");
				printf("\n");
				for (j = 0; j < M / 2; j++)
					printf("*");
				for (j = 0; j < C - M / 2 - 1; j++)
					printf(".");
				printf("c\n");
			} else if (M == R * C - 1) {
				for (j = 0; j < C; j++)
					printf("*");
				printf("\n");
				for (j = 0; j < C - 1; j++)
					printf("*");
				printf("c\n");
			} else
				printf("Impossible\n");
		} else if (C == 2) {
			if (M % 2 == 0 && M <= R * C - 4) {
				for (j = 0; j < M / 2; j++)
					printf("**\n");
				for (j = 0; j < R - M / 2 - 1; j++)
					printf("..\n");
				printf(".c\n");
			} else if (M == R * C - 1) {
				for (j = 0; j < R - 1; j++)
					printf("**\n");
				printf("*c\n");
			} else
				printf("Impossible\n");
		} else {
			if (M <= (R - 2) * C) {
				if (M % C == C - 1) {
					if (C == 3 && R == 3) {
						printf("Impossible\n");
					}
					else if (M == (R - 2) * C - 1) {
						if (C == 3) {
							printf("Impossible\n");
						} else {
							for (j = 0; j < R; j++) {
								for (k = 0; k < C; k++) {
									if (M > 2) {
										printf("*");
										M--;
									} else if (M > 0 && k != 0) {
										printf(".");
									} else if (M > 0 && k == 0) {
										printf("*");
										M--;
									} else if (j != R - 1 || k != C - 1) {
										printf(".");
									} else
									printf("c");
								}
								printf("\n");
							}
						}
					}
					else {
						for (j = 0; j < R; j++) {
							for (k = 0; k < C; k++) {
								if (M > 1) {
									printf("*");
									M--;
								} else if (M > 0 && k != 0) {
									printf(".");
								} else if (M > 0 && k == 0) {
									printf("*");
									M--;
								} else if (j != R - 1 || k != C - 1) {
									printf(".");
								} else
								printf("c");
							}
							printf("\n");
						}
					}
				} else {
					for (j = 0; j < R; j++) {
						for (k = 0; k < C; k++) {
							if (M > 0) {
								printf("*");
								M--;
							} else if (j != R - 1 || k != C - 1) {
								printf(".");
							} else {
								printf("c");
							}
						}
						printf("\n");
					}
				}
			} else {
				if ((M - (R - 2) * C) % 2 == 1) {
					if (M == R * C - 1) {
						for (j = 0; j < R; j++) {
							for (k = 0; k < C; k++) {
								if (j != R - 1 || k != C - 1)
									printf("*");
								else
									printf("c");
							}
							printf("\n");
						}
					} else if (C - 3 >= (M - (R - 2) * C + 1) / 2 + 1) {
						for (j = 0; j < R - 3; j++) {
							for (k = 0; k < C; k++)
								printf("*");
							printf("\n");
						}
						for (j = 0; j < C - 3; j++)
							printf("*");
						printf("...\n");
						for (j = 0; j < (M - (R - 2) * C + 3) / 2; j++)
							printf("*");
						for (j = 0; j < C - (M - (R - 2) * C + 3) / 2; j++)
							printf(".");
						printf("\n");
						for (j = 0; j < (M - (R - 2) * C + 3) / 2; j++)
							printf("*");
						for (j = 0; j < C - (M - (R - 2) * C + 3) / 2 - 1; j++)
							printf(".");
						printf("c\n");
					} else {
						printf("Impossible\n");
					}
				} else if (M - (R - 2) * C == 2 * (C - 1)) {
					printf("Impossible\n");
				} else {
					for (j = 0; j < R - 2; j++) {
						for (k = 0; k < C; k++) {
							printf("*");
							M--;
						}
						printf("\n");
					}
					for (j = 0; j < M / 2; j++)
						printf("*");
					for (j = 0; j < C - M / 2; j++)
						printf(".");
					printf("\n");
					for (j = 0; j < M / 2; j++)
						printf("*");
					for (j = 0; j < C - M / 2 - 1; j++)
						printf(".");
					printf("c\n");
				}
			}
			/*
			if (M == (R - 2) * C - 1) {
				if (C == 3) {

				} else {
				}
			} else if (M <= (R - 2) * C) {
			} else {
			}
			*/
		}
	}
	return 0;
}
