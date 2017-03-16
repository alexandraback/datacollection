#include <iostream>
#include <fstream>

using namespace std;

struct product
{
	long long quantity;
	int type;
};

product* line1;
product* line2;

ifstream fin("input.txt");
ofstream fout("output.txt");

int N,M;

long long maxMatch(int i, int j)
{
	if (i == N || j == M)
	{
		return 0;
	}
	if (line1[i].type == line2[j].type)
	{
		long long Min = line1[i].quantity;
		bool flag = false;
		if (Min > line2[j].quantity)
		{
			flag = true;
			Min = line2[j].quantity;
		}
		line1[i].quantity -= Min;
		line2[j].quantity -= Min;

		long long Max = 0;

		if (flag)
		{
			Max = maxMatch(i,j+1) + Min;
		}
		else
		{
			Max = maxMatch(i+1,j) + Min;
		}
		line1[i].quantity += Min;
		line2[j].quantity += Min;
		return Max;
	}

	long long Max1 = maxMatch(i,j+1);
	long long Max2 = maxMatch(i+1,j);
	return  Max1 > Max2 ? Max1 : Max2;
}

void solution()
{
	fin>>N>>M;
	delete[] line1;
	delete[] line2;
	
	line1 = new product[N];
	line2 = new product[M];
	
	product temp;
	for (int i = 0;i < N;++i)
	{
		fin>>temp.quantity>>temp.type;
		line1[i] = temp;
	}

	for (int i = 0;i < M;++i)
	{
		fin>>temp.quantity>>temp.type;
		line2[i] = temp;
	}

	fout<<maxMatch(0,0)<<endl;

	//int** dp = new int*[N];
	//for (int i = 0;i < N;++i)
	//{
	//	dp[i] = new int[M];
	//}

	//for (int i = 0;i < N;i++)
	//{
	//	dp[i][0] = 0;
	//}
	//for (int i = 0;i < M;i++)
	//{
	//	dp[0][i] = 0;
	//}

	
}

int main()
{
	int T;
	fin>>T;
	for (int i = 1;i <= T;++i)
	{
		fout<<"Case #"<<i<<": ";
		solution();
	}
}