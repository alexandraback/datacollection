#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <string.h>

using namespace std;

int main(int argc, const char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Error:%d\n", __LINE__);
        return -1;
    }

    ifstream fin(argv[1]);
    ofstream fout("out.txt");

    int T;
    fin >> T;
	for (int j = 0; j < T; j++)
	{
		string S;
		fin >> S;

		string a;
		a = S[0];
		for (int i = 1; i < S.length(); i++)
		{
			if (a[0] > S[i])
			{
				a += S[i];
			}
			else
			{
				string b;
				b = S[i];
				b += a;
				a = b;
			}
		}

		fout << "Case #" << j + 1 << ": " << a << endl;
	}
    return (0);
}
