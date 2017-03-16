#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
int main()
{
	ifstream fin;
	fin.open("A-small-attempt1.in");
	if (fin.is_open())
	{
		ofstream fout;
		fout.open("A-small-attempt1.out");
		int T;
		fin >> T;
		unsigned long long N,NN,NNN;
		for (int i = 0; i < T; i++)
		{
			fin >> N;
			int notChanged=0;
			vector<bool> digits(10);
			int s = 0;
			NN = 0;
			while (notChanged<100 && s<10)
			{

				int lasts = s;
				NN += N;
				NNN = NN;
				while (NNN>0)
				{
					int a = NNN % 10;
					if (!digits[a])
					{
						digits[a] = true;
						s++;
					}
					NNN = NNN / 10;
				}
				if (s == lasts) notChanged++; else notChanged = 0;
			}
			if (s < 10)
			{
				cout << "Case #" << i + 1 << ": INSOMNIA" << endl;
				fout << "Case #" << i + 1 << ": INSOMNIA" << endl;
			}
			else
			{
				cout << "Case #" << i + 1 << ": " << NN << endl;
				fout << "Case #" << i + 1 << ": " << NN << endl;
			}
		}
		fin.close();
		fout.close();
	}
	return 0;
}