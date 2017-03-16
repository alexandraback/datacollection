#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ifstream fin("warin.txt");
	ofstream fout("warout.txt");

	fin.setf(ios::fixed, ios::floatfield);
	fin.precision(10);
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(3);

	int T = 0;
	fin >> T;

	for (int i = 0; i < T; i++)
	{
		int n, WarScore = 0, DeceitScore = 0;
		vector<float> N, K;

		fin >> n;

		for (int j = 0; j < n; j++)
		{
			float t;
			fin >> t;
			N.push_back(t);
		}
		for (int j = 0; j < n; j++)
		{
			float t;
			fin >> t;
			K.push_back(t);
		}

		sort(N.begin(), N.end());
		sort(K.begin(), K.end()); 

		for (int j = n-1, k = n-1; k >= 0; k--)
		{
			if (N[k] > K[j])
			{
				WarScore++;
			}
			else
			{
				j--;
			}
		}

		for (int j = 0, k = 0; k < n; k++)
		{
			if (N[k] > K[j])
			{
				DeceitScore++;
				j++;
			}
		}

		fout << "Case #" << i + 1 << ": " << DeceitScore << " " << WarScore << '\n';
		/*
		cout << "Case #" << i + 1 << ":\n";
		for (int j = 0; j < n; j++)
		{
			cout << N[j] << " ";
		}
		cout << "\n";
		for (int j = 0; j < n; j++)
		{
			cout << K[j] << " ";
		}
		cout << "\n";//*/
	}
	fin.close();
	fout.close();
	system("pause");
}
