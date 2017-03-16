#include <fstream>
//This standard library handles files
#include <sstream>
//This standard library handles stringstreams, useful generalisations of strings
#include <iostream>
//Standard library for talking to the user
#include <algorithm>
#include <array>
//Standard libraries to sort arrays
using namespace std;

int deceit(int N, array<double, 1000> blocksNao, array<double, 1000> blocksKen)
{
	int score = 0, i, j;
	for (i = 0; i < N; i++)
	{
		//Naomi finds the lightest block she owns that's heavier than the lightest block Ken owns and then lies about it,
		//saying it is slightly heavier than his heaviest. So he will use his lightest one instead and she will win.
		for (j = 0; j < N; j++)
		{
			if (blocksNao[j] > blocksKen[i])
			{
				score++;
				blocksNao[j] = 0.0;
				break;
			}
		}
		//If no block of hers is heavier than his lightest, she won't get any more points
		if (j == N)
			break;
	}
	return score;
}

int war(int N, array<double, 1000> blocksNao, array<double, 1000> blocksKen)
{
	int score = 0, i, j;
	for (i = N - 1; i >= 0; i--)
	{
		//The optimal strategy is Naomi choosing her heaviest block, and Ken finding the lightest one he has that's heavier than hers
		for (j = 0; j < N; j++)
		{
			if (blocksKen[j] > blocksNao[i])
			{
				blocksKen[j] = 0.0;
				break;
			}
		}
		if (j == N)							//Naomi scores if Ken can't find a block heavier than hers
		{
			score++;
			blocksKen[0] = 0.0;				//in which case he uses his lightest
		}
	}
	return score;
}

int main()
{
	fstream filein, fileout;
	int T, i, j, N;
	array<double, 1000> blocksNao;
	array<double, 1000> blocksKen;
	string s;
	cout << "Please type name of input file: ";
	cin >> s;
	filein.open(s.c_str(), fstream::in);
	cout << "Please type name of output file: ";
	cin >> s;
	fileout.open(s.c_str(), fstream::out);
	fileout.precision(7);
	filein >> T;									//gets number of cases
	for (i = 0; i < T; i++)
	{
		//loops for each case
		fileout << "Case #" << (i + 1) << ": ";		//starts building output file
		filein >> N;
		blocksNao.fill(1.0);
		blocksKen.fill(1.0);
		for (j = 0; j < N; j++)
			filein >> blocksNao[j];					//gets Naomi's blocks
		for (j = 0; j < N; j++)
			filein >> blocksKen[j];					//gets Ken's blocks
		sort(blocksNao.begin(), blocksNao.end());	//sorts their blocks by weight
		sort(blocksKen.begin(), blocksKen.end());
		fileout << deceit(N, blocksNao, blocksKen) << " " << war(N, blocksNao, blocksKen) << endl;
	}
	filein.close();
	fileout.close();
	return 0;
}
