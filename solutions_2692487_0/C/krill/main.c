#include <stdio.h>

int motes[100];
int N;

int consume(int mote_index, int size) {
	int rem, add, times;
	if(mote_index == N)
		return 0;
	else if(motes[mote_index] < size)
		return consume(mote_index + 1, size + motes[mote_index]);
	else {
		rem = consume(mote_index + 1, size) + 1;
		if(size - 1 == 0)
			return rem;
		for(times = 0; size <= motes[mote_index]; times++, size += size - 1);
		add = consume(mote_index + 1, size + motes[mote_index]) + times;

		//printf("%d %d\n", add, rem );

		if(add < rem)
			return add;
		else
			return rem;
	}
}

int main(int argc, char *argv[])
{
	FILE *input, *output;
	int T, t;
	int A;
	int n;
	int i, j, k;
	int cnt;

	input = fopen(argv[1], "r");
	output = fopen("output.txt", "w");

	fscanf(input, "%d", &T);

	for(t = 1; t <= T; t++) {
		fscanf(input, "%d", &A);
		fscanf(input, "%d", &N);

		for(n = 0; n < N; n++)
			fscanf(input, "%d", motes + n);


		//bubblesort
		for(j = N - 1; j > 0; j--) {
			k = 0;
			for(i = 0; i < j; i++) {
				if(motes[i] > motes[i+1]) {
					k = motes[i];
					motes[i] = motes[i+1];
					motes[i+1] = k;
				}
			}
			if(k == 0)
				break;
		}

		//for(n = 0; n < N; n++)
		//	printf("%d ", motes[n] );
		//njama njama

		#if 0
		cnt = 0;

		for(i = 0; i < N; i++) {
			if(motes[i] < A) {
				A += motes[i];
			}
			else {
				if()
			}
		}
		#endif

		printf("Case #%d: %d\n", t, consume(0,A));
		fprintf(output, "Case #%d: %d\n", t, consume(0,A));
	}


	fclose(output);
	fclose(input);

	return 0;
}