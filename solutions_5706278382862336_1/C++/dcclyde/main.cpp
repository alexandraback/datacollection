#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

int main()
{
	//ifstream fin("test.in");
	ifstream fin("A-large.in");
	ofstream fout("output.txt");
	int N;
	long long P, Q;
	char dummy;
	int pow;

	fin >> N;
	for (int t = 1; t <= N; t++)
	{
		fout << "Case #" << t << ": ";
		fin >> P;
		fin >> dummy;
		fin >> Q;

		pow = 0;
		while (Q % 2 == 0 && pow <= 39)
		{
			pow++;
			Q /= 2;
		}

		if (P % Q != 0)
		{
			fout << "impossible" << endl;
		}
		else
		{
			// We actually have work to do.
			P /= Q;
			int steps = 0;
			while (P != 0)
			{
				P /= 2;
				steps++;
			}
			fout << pow-steps+1 << endl;
		}


	}

	fin.close();
	fout.close();
}
//
//void conv(int& key, int& presses, char in)
//{
//	if (in == 'a')
//	{
//		key = 2;
//		presses = 1;
//		return;
//	}
//	if (in == 'b')
//	{
//		key = 2;
//		presses = 2;
//		return;
//	}
//	if (in == 'c')
//	{
//		key = 2;
//		presses = 3;
//		return;
//	}
//	if (in == 'd')
//	{
//		key = 3;
//		presses = 1;
//		return;
//	}
//	if (in == 'e')
//	{
//		key = 3;
//		presses = 2;
//		return;
//	}
//	if (in == 'f')
//	{
//		key = 3;
//		presses = 3;
//		return;
//	}
//	if (in == 'g')
//	{
//		key = 4;
//		presses = 1;
//		return;
//	}
//	if (in == 'h')
//	{
//		key = 4;
//		presses = 2;
//		return;
//	}
//	if (in == 'i')
//	{
//		key = 4;
//		presses = 3;
//		return;
//	}
//	if (in == 'j')
//	{
//		key = 5;
//		presses = 1;
//		return;
//	}
//	if (in == 'k')
//	{
//		key = 5;
//		presses = 2;
//		return;
//	}
//	if (in == 'l')
//	{
//		key = 5;
//		presses = 3;
//		return;
//	}
//	if (in == 'm')
//	{
//		key = 6;
//		presses = 1;
//		return;
//	}
//	if (in == 'n')
//	{
//		key = 6;
//		presses = 2;
//		return;
//	}
//	if (in == 'o')
//	{
//		key = 6;
//		presses = 3;
//		return;
//	}
//	if (in == 'p')
//	{
//		key = 7;
//		presses = 1;
//		return;
//	}
//	if (in == 'q')
//	{
//		key = 7;
//		presses = 2;
//		return;
//	}
//	if (in == 'r')
//	{
//		key = 7;
//		presses = 3;
//		return;
//	}
//	if (in == 's')
//	{
//		key = 7;
//		presses = 4;
//		return;
//	}
//	if (in == 't')
//	{
//		key = 8;
//		presses = 1;
//		return;
//	}
//	if (in == 'u')
//	{
//		key = 8;
//		presses = 2;
//		return;
//	}
//	if (in == 'v')
//	{
//		key = 8;
//		presses = 3;
//		return;
//	}
//	if (in == 'w')
//	{
//		key = 9;
//		presses = 1;
//		return;
//	}
//	if (in == 'x')
//	{
//		key = 9;
//		presses = 2;
//		return;
//	}
//	if (in == 'y')
//	{
//		key = 9;
//		presses = 3;
//		return;
//	}
//	if (in == 'z')
//	{
//		key = 9;
//		presses = 4;
//		return;
//	}
//	if (in == ' ')
//	{
//		key = 0;
//		presses = 1;
//		return;
//	}
//	assert(false);
//}
//
//int main()
//{
//	ifstream fin("B-large-practice.in");
//	ofstream fout("outB.txt");
//	int N;
//	int key, presses, oldkey;
//	string in;
//	getline(fin, in);
//	stringstream convert(in);
//	convert >> N;
//	long P, Q;
//	for (int t = 1; t <= N; t++)
//	{
//		fout << "Case #" << t << ": ";
//
//		getline(fin, in);
//
//		int ctr = 0;
//		while (in[ctr] != '/')
//			ctr++;
//		P = (long) in.substr(0, ctr);
//		Q = 
//
//
//		//oldkey = -1;
//		//for (int i = 0; i <= in.length() - 1; i++)
//		//{
//		//	// For each character, let's print how to type it.
//		//	//////////cout << "-" << in[i] << endl;
//		//	conv(key, presses, in[i]);
//		//	if (key == oldkey)
//		//	{
//		//		fout << " ";
//		//	}
//		//	oldkey = key;
//		//	for (int j = 1; j <= presses; j++)
//		//	{
//		//		fout << key;
//		//	}
//
//		//}
//		fout << endl;
//	}
//
//	fin.close();
//	fout.close();
//}
