/*
 * BFFsmall.cpp
 *
 *  Created on: Apr 15, 2016
 *      Author: jonathan
 */

#include <stdio.h>

void iterate_perm(int* f_array, int* perm, int& i, int num, int* used, int& ans)
{
	if (i == num) {
		int q = 0;
		for (int j = 0;j < num;j++)
		{
//			printf("%d ",perm[j]);
			if (f_array[perm[j]] == perm[0]) q = j;
			if (f_array[perm[j]] == perm[(j+1)%num]) {}
			else if (j > 0 && f_array[perm[j]] == perm[(j - 1)]) {q = j;}
			else j = num;
		}
//		printf("\n");
		++q;
		if (q > ans) ans = q;
	}
/*	else if (i == 0)
	{
		perm[i] = 0;
		++i;
		used[0] = 1;
		iterate_perm(f_array,perm,i,num,used,ans);
		used[0] = 0;
		--i;
	}*/
	else {
		for (int j = 0;j < num;j++)
		{
			if (used[j] == 0)
			{
				perm[i] = j;
				++i;
				used[j] = 1;
				iterate_perm(f_array,perm,i,num,used,ans);
				used[j] = 0;
				--i;
			}
		}
	}
}

int main()
{
	FILE* input;
	FILE* output;
	input = fopen("C-small-attempt1.in","r");
	output = fopen("output-C-small.txt","w");
	long num_cases;
	fscanf(input,"%ld",&num_cases);
	for (long i = 0;i < num_cases;i++)
	{
		long N;
		fscanf(input,"%ld",&N);
		int* friends = new int[N];
		int* perm = new int[N];
		int* used = new int[N];
		for (long j = 0;j < N;j++)
		{
			fscanf(input,"%d",&friends[j]);
			--friends[j];
		}
		for (long j = 0;j < N;j++)
		{
			used[j] = 0;
		}
		int q = 0;
		int ans = 0;
		iterate_perm(friends,perm,q,N,used,ans);
		fprintf(output,"Case #%ld: %d \n",i+1,ans);
		delete[] friends;
		delete[] perm;
		delete[] used;
	}
}
