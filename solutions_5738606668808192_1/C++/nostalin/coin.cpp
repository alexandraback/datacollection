#include <iostream>
#include <vector>
#include <string>
using namespace std;

//first부터 last까지 left개를 뽑는다.
void pick_three(vector<vector<int>>& comb, vector<int> picked, int first, int last, int left)
{
	if (left == 0)
	{
		comb.push_back(picked);
		return;
	}

	if (first > last)
		return;

	for (int i = first; i <= last; ++i)
	{
		picked.push_back(i);
		pick_three(comb, picked, i+1, last, left - 1);
		picked.pop_back();
	}

}


int main()
{
	FILE* input;
	FILE* output;

	input = fopen("C:\\Users\\현우\\Desktop\\Google\\2016QR\\Coin Jam\\large.txt", "r");
	output = fopen("C:\\Users\\현우\\Desktop\\Google\\2016QR\\Coin Jam\\large_answer.txt", "w");

	int T;
	int t = 1;

	fscanf(input, "%d", &T);

	int N, J;

	fscanf(input, "%d %d", &N, &J);

	int cnt = 0;

	vector<vector<int>> comb;
	vector<int> picked;

	pick_three(comb, picked, 1, 15, 2);

	char* coin = new char[N+1];
	for (int i = 1; i < N - 1; ++i)
		coin[i] = '0';
	coin[0] = '1';
	coin[N - 1] = '1';
	coin[N] = '\0';
	fprintf(output, "Case #1:\n");

	for (int ii = 0; ii < comb.size(); ++ii)
	{
		for (int ij = 0; ij < 2; ++ij)
		coin[2 * comb[ii][ij]] = '1';
			
		for (int ji = 0; ji < comb.size(); ++ji)
		{
			if (cnt == 500)
				break;

			for (int jj = 0; jj < 2; ++jj)
				coin[comb[ji][jj] * 2 - 1] = '1';

			fprintf(output, "%s 3 2 5 2 7 2 3 2 11\n", coin);
			++cnt;

			for (int jj = 0; jj < 2; ++jj)
				coin[comb[ji][jj] * 2 - 1] = '0';
		}

		for (int ij = 0; ij < 2; ++ij)
		coin[2 * comb[ii][ij]] = '0';

		if (cnt == 500)
			break;
	}

	return 0;
}



