#include <stdio.h>
#include <string.h>

void quicksort (unsigned long x[100], int first, int last) {
	int pivot, j, i;
	unsigned long temp;

	if(first<last){
		pivot=first;
		i=first;
		j=last;

		while(i<j){
			while(x[i]<=x[pivot]&&i<last)
				i++;
			while(x[j]>x[pivot])
				j--;
			if(i<j){
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}

		temp=x[pivot];
		x[pivot]=x[j];
		x[j]=temp;
		quicksort(x,first,j-1);
		quicksort(x,j+1,last);

	}
}

int main () {
	int T, test_case = 0, index, N;
	unsigned long A, motes[100];
	int add, add_del, motes_start, temp, result, is_A_1;;

	scanf("%d",&T);

	while (test_case++ < T) {
		//scan and proces one test-case
		scanf("%lu", &A);
		scanf("%d", &N);
		add = 0;
		add_del = N;
		motes_start = 0;
		is_A_1 = 0;

		for(index = 0; index < N; index++) {
			scanf("%lu", &motes[index]);
		}

		quicksort(motes, 0, N-1);

		while (1) {
			//absorb all possible
			for (index = motes_start; index < N; index++) {
				if (motes[index] < A) {
					A = A + motes[index];
					motes_start++;
				}
				else
					break;
			}
			if (motes_start == N)
				break;

			//update add_del
			temp = add + N - motes_start;
			if (temp < add_del)
				add_del = temp;

			//add one A-1, if possible
			if (A == 1) {
				is_A_1 = 1;
				break;
			}
			A = 2 * A - 1;
			add++;
		}

		//result = min(add, add_del)
		if (!is_A_1)
			result = (add < add_del) ? add : add_del;
		else
			result = add_del;
		printf("Case #%d: %d\n", test_case, result);
	}
	return 0;
}

