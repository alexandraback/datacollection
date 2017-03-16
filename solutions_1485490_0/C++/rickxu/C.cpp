#include <fstream>
#include <iostream>
using namespace std;

struct Item
{
	int type;
	long long num;
};

long long calc(long long matrix[100][100], Item boxes[100], Item toys[100], int N, int M)
{
	if (N < 0 || M < 0)
		return 0;

	if (matrix[N][M] > 0)
		return matrix[N][M];

	long long num0 = (long long)0;
	if (boxes[N].type == toys[M].type)
	{
		long long num = boxes[N].num > toys[M].num ? toys[M].num : boxes[N].num;
		if (boxes[N].num > toys[M].num)
		{
			long long x = boxes[N].num;
			boxes[N].num -= toys[M].num;
			num0 = num + calc(matrix, boxes, toys, N, M-1);
			boxes[N].num = x;
		}
		else if (boxes[N].num < toys[M].num)
		{
			long long x = toys[M].num;
			toys[M].num -= boxes[N].num;
			num0 = num + calc(matrix, boxes, toys, N-1, M);
			toys[M].num = x;
		}
		else
			num0 = num + calc(matrix, boxes, toys, N-1, M-1);

		//return matrix[N][M] = num0;
	}

	long long num1 = calc(matrix, boxes, toys, N-1, M);
	long long num2 = calc(matrix, boxes, toys, N, M-1);

	long long num = num0;
	if (num1 > num)
		num = num1;
	if (num2 > num)
		num = num2;

	return matrix[N][M] = num;
}

int main()
{
	ifstream in_file("inputC.txt");
	ofstream out_file("outputC.txt");

	int T;
	in_file >> T;

	for (int i=1; i<=T; i++)
	{
		Item boxes[100], toys[100];
		int N, M;
		in_file>>N>>M;
		for (int j=0; j<N; j++)
		{
			in_file>>boxes[j].num>>boxes[j].type;
		}
		for (int j=0; j<M; j++)
		{
			in_file>>toys[j].num>>toys[j].type;
		}

		long long matrix[100][100] = {{0}};
		for (int j=0; j<100; j++)
			for (int k=0; k<100; k++)
			{
				matrix[j][k] = 0;
			}

		out_file<<"Case #"<<i<<": "<<calc(matrix, boxes, toys, N-1, M-1)<<endl;
	}

	in_file.close();
	out_file.close();
	return 0;
}
