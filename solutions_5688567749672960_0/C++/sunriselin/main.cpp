#include <stdio.h>
#include <vector>
#include <iostream>

int reverseNum(int num)
{
	std::vector<int> reverse;

	if (num % 10 == 0)
		return num;

	while (num) {
		reverse.push_back(num%10);
		num /= 10;
	}

	int result = 0;
	for (int i = 0; i < reverse.size(); i++) {
		result *= 10;
		result += reverse[i];
	}
	return result;
}

std::vector<int> res(1000001, -1);

int getMinStep(int cur_s) {
	if (cur_s <= 22)
		return cur_s;

	int min_step_1 = getMinStep(cur_s-1)+1;
	int reverseN = reverseNum(cur_s);

	int min_step_2 = min_step_1;
	if (reverseN < cur_s) {
		min_step_2 = getMinStep(reverseN) + 1;
	}

	return std::min(min_step_1, min_step_2);
}

int main()
{
	FILE* fp = fopen("A-small-attempt0.in", "r");

	FILE* fp_w = fopen("file_out.txt", "w");

	//if (NULL == fp)
	//	return -1;

	//FILE* fp = fopen("Table.txt", "w");

	int T;
	fscanf(fp, "%d", &T);

	for (int i = 0; i <= 1000; i++)
		res[i] = i;	

	for (int i = 0; i <= 19; i++) {
		res[i] = i;
	}

	for (int i = 20; i <= 1000000; i++) {
		int reverse_i = reverseNum(i);

		int st = res[i-1]+1;
		if (reverse_i < i)
			st = std::min(st, res[reverse_i]+1);

		res[i] = st;
	}

	
	for (int i = 1; i <= T; i++) {
		int n;
		fscanf(fp, "%d", &n);
		
		fprintf(fp_w, "Case #%d: %d\n", i, res[n]);
	}

	fclose(fp);
	fclose(fp_w);
	
	return 0;
}
