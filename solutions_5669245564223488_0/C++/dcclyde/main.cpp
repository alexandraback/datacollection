#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <algorithm>

using namespace std;

int factorial(int x, long long result = 1) {
	if (x == 1) return result; else return factorial(x - 1, x * result);
}

int main()
{
	//ifstream fin("test.in");
	ifstream fin("B-small-attempt0.in");
	ofstream fout("output1c.txt");
	int N,T;
	string* trains;
	bool* inplay;
	long long ways;
	string starts, ends, mids, solos;
	int* realstrs;

	fin >> T;
	for (int t = 1; t <= T; t++)
	{
		ways = 1;
		fout << "Case #" << t << ": ";
		fin >> N;
		trains = new string[N];
		inplay = new bool[N];
		realstrs = new int[N];
		starts = "";
		ends = "";
		mids = "";
		solos = "";
		for (int i = 0; i <= N - 1; i++)
		{
			fin >> trains[i];
			inplay[i] = false;
			for (int j = 1; j <= (int)trains[i].length() - 1; j++)
			{
				if (trains[i][j] != trains[i][0])
					inplay[i] = true;
			}
			if (inplay[i] == false)
			{
				// This train is just one character over and over.
				solos += trains[i][0];
				starts += " ";
				ends += " ";
			}
			else
			{
				starts += trains[i][0];
				ends += trains[i][(int)trains[i].length() - 1];
			}
		}


		// OK, let's try to concatenate everything.
		
		bool working = true;
		while (working)
		{
			working = false;
			for (int i = 0; i <= N - 1; i++)
			{
				if (inplay[i])
				{
					// Try to match ends[i] to some starts[j].
					for (int j = 0; j <= N - 1; j++)
					{
						if (inplay[j])
						{
							if (ends[i] == starts[j])
							{
								trains[i] += trains[j];
								inplay[j] = false;
								ends[i] = ends[j];
								working = true;
							}
						}
					}
				}
			}
		}

		// OK, now we just have a few huge strings left.
		string final = "";
		ways = 1;
		int factctr = 1;
		for (int i = 0; i <= N - 1; i++)
		{
			if (inplay[i])
			{
				ways = (ways * factctr) % 1000000007;
				factctr++;
				final += trains[i];
			}
		}

		// Now need to take into account the solo stuff.
		sort(solos.begin(), solos.end());
		// how many of each character?

		int factctr2 = 2;
		for (int i = 0; i <= (int)solos.length() - 2; i++)
		{
			if (solos[i] == solos[i + 1])
			{
				ways = (ways * factctr2) % 1000000007;
				factctr2++;
			}
			else
			{
				factctr2 = 2;
			}
		}

		// Finally, just need to check whether the string 'final' is acceptable.
		string seen = "";
		seen += final[0];
		bool FAIL = false;
		for (int i = 1; i <= (int)final.length() - 1 && !FAIL; i++)
		{
			if (final[i] != final[i - 1])
			{
				// Found a non-repeating character, so it'd better not be something we've already seen.
				for (int j = 0; j <= (int)seen.length() - 1 && !FAIL; j++)
				{
					if (seen[j] == final[i])
						FAIL = true;
				}
				seen += final[i];
			}
		}
		if (FAIL)
			fout << "0" << endl;
		else
		{
			for (int i = 0; i <= (int)solos.length() - 1; i++)
			{
				bool tester = false;
				for (int j = 0; j <= (int)final.length() - 1; j++)
				{
					if (solos[i] == final[j])
						tester = true;
				}
				if (tester == false)
				{
					ways = (ways * factctr) % 1000000007;
					factctr++;
					final += solos[i];
				}
			}
			fout << ways << endl;
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
