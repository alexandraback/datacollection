/*
 ============================================================================
 Name        : a.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int N)
{
	int i, j, min, t;
	for (i = 0; i < N; i++) {
		min = i;
		for (j = i + 1; j < N; j++)
			if (a[j] < a[min])
				min = j;

		t = a[min];
		a[min] = a[i];
		a[i] = t;
	}
}

int count(int A, int other[], int N)
{
	int num_add[N], num_del[N];
	int i, temp;

	for (i = 0; i < N; i++) {
		num_del[i] = N - i;
		num_add[i] = 0;
	}

	temp = A;
	for (i = 0; i < N; i++) {
		if (temp > other[i]) {
			temp += other[i];
		} else {
			while (temp <= other[i]) {
				if (temp < 2) {
					num_add[i] = 10000;
					break;
				} else {
					temp += (temp - 1);
					num_add[i]++;
				}
			}

			temp += other[i];
		}
	}

	temp = 0;
	for (i = N - 1; i >= 0; i--) {
		temp += num_add[i];
		if (temp > num_del[i])
			temp = num_del[i];
	}

	//printf("%d", temp);
	//fflush(stdout);
	return temp;
}
int main(void) {
	int case_num;
	FILE *input, *output;
	int i, j;
	int A, N;
	int other[100];

	input = fopen("a_a.in", "r");
	output = fopen("a_a.out", "w");
	fscanf(input, "%d", &case_num);

	for (i = 1; i <= case_num; i++) {
		fprintf(output, "Case #%d: ", i);
		fscanf(input, "%d %d", &A, &N);
		for (j = 0; j < N; j++)
			fscanf(input, "%d", &other[j]);

		sort(other, N);
		fprintf(output, "%d\n", count(A, other, N));
	}

	fclose(input);
	fclose(output);
	return 0;
}
